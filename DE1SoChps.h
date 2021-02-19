#ifndef DE1SOCHPS_h
#define DE1SOCHPS_h

// OLD OFFSETS 
/* 

// Physical base address of FPGA Devices
const unsigned int LW_BRIDGE_BASE 	= 0xFF200000;  // Base offset

// Length of memory-mapped IO window
const unsigned int LW_BRIDGE_SPAN 	= 0x00005000;  // Address map size

// Cyclone V FPGA device addresses
const unsigned int LEDR_BASE 		= 0x00000000;  // Leds offset
const unsigned int SW_BASE 			= 0x00000040;  // Switches offset
const unsigned int KEY_BASE 		= 0x00000050;  // Push buttons offset

const unsigned int HEX3_HEX0_BASE = 0x00000020; // HEX Reg1 offset
const unsigned int HEX5_HEX4_BASE = 0x00000030; // HEX Reg2 offset


Cyclone V HPS devices 
const unsigned int HPS_BRIDGE_BASE = 0xFF700000; // base
const unsigned int HPS_BRIDGE_SPAN = 0x006FFFFF; // span





const unsigned int gpio1_base = 0x00009000  ;
const unsigned int gpio1_dr_offset = 0x00000000 ;
const unsigned int gpio1_ddr_offset = 0x00000004 ;
const unsigned int gpio1_debounce_offset = 0x00000048 ;
const unsigned int gpio1_ext_port_offset = 0x00000050 ;

HPS timer registers 
const unsigned int timer0_load_reg       = 0x00508000;
const unsigned int timer0_curr_val_reg   = 0x00508004;
const unsigned int timer0_control_reg    = 0x00508008; 
const unsigned int timer0_eoi_reg        = 0x0050800C; 
const unsigned int timer0_int_stat_reg   = 0x00508010;
*/////////////////////////////////


//NEW OFFSETS 
/* Cyclone V HPS devices */
const unsigned int HPS_BRIDGE_BASE = 0xFF700000; // base
const unsigned int HPS_BRIDGE_SPAN = 0x006FFFFF; // span

/* I2C0 Peripheral Registers */
const unsigned int I2C0_BASE = 0x00504000; // I2C0 Base Address
const unsigned int I2C0_CON = 0x00504000; // Control Register
const unsigned int I2C0_TAR = 0x00504004 ; // Target Address Register
const unsigned int I2C0_DATA_CMD = 0x00504010 ; // Tx Rx Data and Command Register
const unsigned int I2C0_FS_SCL_HCNT = 0x0050401C ; // Fast Spd Clock SCL HCNT Register
const unsigned int I2C0_FS_SCL_LCNT =  0x00504020 ; // Fast Spd Clock SCL LCNT Register

const unsigned int I2C0_CLR_INTR = 0x00504040 ; // Combined and Individual Interrupt Register
const unsigned int I2C0_ENABLE = 0x0050406C ; // Enable Register
const unsigned int I2C0_TXFLR = 0x00504074 ; // Transmit FIFO Level Register
const unsigned int I2C0_RXFLR =  0x00504078; // Receive FIFO Level Register
const unsigned int I2C0_ENABLE_STATUS = 0x0050409C ; // Enable Status Register

 // The Pin Multiplexer selection
 const unsigned int PIN_MUX_GEN_IO7 = 0xFFD0849C - HPS_BRIDGE_BASE; // GENERALIO7 reg offset
 const unsigned int PIN_MUX_GEN_IO8 =  0xFFD084A0 - HPS_BRIDGE_BASE; // GENERALIO8 reg offset
 const unsigned int PIN_MUX_GPLMUX55 =  0xFFD086B0 -  HPS_BRIDGE_BASE; // GPLMUX55 reg offset
 const unsigned int PIN_MUX_GPLMUX56 = 0xFFD086B4 -  HPS_BRIDGE_BASE; // GPLMUX56 reg offset
 const unsigned int PIN_MUX_I2C0USEFPGA = 0xFFD08704 - HPS_BRIDGE_BASE ; // I2C0USEFPGA reg offset



class DE1SoChps
{
    char *pBase;
    int fd;

public:
    DE1SoChps();
    ~DE1SoChps();
    void RegisterWrite(unsigned int offset, int value);
    int RegisterRead(unsigned int offset);    
};

#endif