#include "GSensor.h"
#include "ADXL345.h"
using namespace std;
#include <iostream>
#include <stdint.h>

GSensor::GSensor()
{
    cout << "initializing GSensor... !" << endl;
     cout<< "start pinmuxconfig" << endl;
    GSensor::PinmuxConfig();
    cout<< "end pinmuxconfig" << endl;
    GSensor::I2C0_Init();
    cout<< "Done initializing GSensor.." << endl;
}

GSensor::~GSensor()
{
     cout << "Done Using GSensor... !" << endl;

}


void GSensor::PinmuxConfig()
{
    RegisterWrite(PIN_MUX_I2C0USEFPGA, 0);
    RegisterWrite(PIN_MUX_GEN_IO7,1);
    RegisterWrite(PIN_MUX_GEN_IO8,1);
}

void GSensor::I2C0_Init()
{
    RegisterWrite(I2C0_ENABLE,2);
    while((RegisterRead(I2C0_ENABLE_STATUS))&0x1 == 1) {}

    RegisterWrite(I2C0_CON,0x65);
    RegisterWrite(I2C0_TAR,0x53);

    RegisterWrite(I2C0_FS_SCL_HCNT, 90);
    RegisterWrite(I2C0_FS_SCL_LCNT,160);

    RegisterWrite(I2C0_ENABLE, 1);

    while ((RegisterRead(I2C0_ENABLE_STATUS))&0x1 == 0)
    {
        /* code */
    }
    
}

void GSensor::ADXL345_Init()
{
    ADXL345_RegWrite(ADXL345_REG_DATA_FORMAT, XL345_RANGE_16G | XL345_FULL_RESOLUTION);
    ADXL345_RegWrite(ADXL345_REG_BW_RATE, XL345_RATE_200);
    ADXL345_RegWrite(ADXL345_REG_THRESH_ACT, 0x04);
    ADXL345_RegWrite(ADXL345_REG_THRESH_INACT, 0x02);
    ADXL345_RegWrite(ADXL345_REG_TIME_INACT, 0x02);
    ADXL345_RegWrite(ADXL345_REG_ACT_INACT_CTL, 0xFF);  
    ADXL345_RegWrite(ADXL345_REG_INT_ENABLE, XL345_ACTIVITY | XL345_INACTIVITY ); 
    ADXL345_RegWrite(ADXL345_REG_POWER_CTL, XL345_STANDBY);
    ADXL345_RegWrite(ADXL345_REG_POWER_CTL, XL345_MEASURE);
    
}

void GSensor::ADXL345_RegRead(uint8_t address, uint8_t *value)
{   

    RegisterWrite(I2C0_DATA_CMD,address + 0x400);
    RegisterWrite(I2C0_DATA_CMD,0x100);

    while(RegisterRead(I2C0_RXFLR) == 0) {}

    *value = RegisterRead(I2C0_DATA_CMD);
 

}

void GSensor::ADXL345_RegWrite(uint8_t address, uint8_t value)
{
    RegisterWrite(I2C0_DATA_CMD, address + 0x400);
    RegisterWrite(I2C0_DATA_CMD, value);
}

void GSensor::ADXL345_RegMultiRead(uint8_t address, uint8_t values[], uint8_t len)
{
    RegisterWrite(I2C0_DATA_CMD, address + 0x400);
    
    for (int i = 0; i < len; i++)
    {
        RegisterWrite(I2C0_DATA_CMD, 0x100);
    }

    int nth_byte=0;
    while(len) 
    {
        if (RegisterRead(I2C0_RXFLR) > 0)
        {
            values[nth_byte] = RegisterRead(I2C0_DATA_CMD);
            nth_byte++;
            len--;
        }
    }    
}

void GSensor::ADXL345_XYZ_Read(int16_t szData16[3], int16_t mg_per_lsb)
{

    uint8_t szData8[6];
    ADXL345_RegMultiRead(0x32, (uint8_t *)&szData8, sizeof(szData8));
    szData16[0] = (szData8[1] << 8) | szData8[0];
    szData16[1] = (szData8[3] << 8) | szData8[2];
    szData16[2] = (szData8[5] << 8) | szData8[4];

}

bool GSensor::ADXL345_IsDataReady()
{
    bool bReady = false;
    uint8_t data8;

    ADXL345_RegRead(ADXL345_REG_INT_SOURCE, &data8);
    if (data8 & XL345_ACTIVITY)
    {
        bReady = true;
    }

    return bReady;
    
}