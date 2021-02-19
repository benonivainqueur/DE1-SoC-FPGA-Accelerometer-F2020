#include "ADXL345.h"
#include <stdio.h>
#include "GSensor.h"
#include "PIOControl.h"
#include <iostream>
using namespace std;


int main(){
    uint8_t devid;
    int16_t mg_per_lsb = 4;
    int16_t XYZ[3];



    GSensor foo;
    PIOControl bar;
    foo.ADXL345_RegRead(0x00, &devid);

    if (devid == 0xE5){
        foo.ADXL345_Init();
        double ang;
        while(1){
            if(foo.ADXL345_IsDataReady()){
                foo.ADXL345_XYZ_Read(XYZ,mg_per_lsb);
                printf("X=%d mg, Y=%d mg, Z=%d mg\n", XYZ[0]*mg_per_lsb,
                XYZ[1]*mg_per_lsb, XYZ[2]*mg_per_lsb);
                
                    ang = ((((double)XYZ[0]) * mg_per_lsb)  / 11.111111 )  + 90;
                
                cout << "x angle: "  << ang  << " \n" ;
                bar.WritePIOout(ang);
                cout<< "\n x angle from PIO" << bar.ReadPIOin() << "\n";
               
            }
        }

    } else {
        printf("incorrect device ID \n");
    }
    return 0;




    

    

}