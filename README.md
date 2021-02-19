# DE1-SoC-FPGA-Accelerometer-F2020

## Objectives 
Integrating Hardware, and Software components with a ADXL345 Accelerometer

## Process 
* Pbtain measurements from the ADXL345 digital accelerometer sensor module, refered to as G-sensor, which is connected to the HPS on the DE1SoC
* Using adders, multiplexers, and verilog, measurements from the G-sensor will be processed by the the FPGA and converted into the inclination angle of the board 
* The corresponding angle will bedisplayed on a 7-segment display and also returned to the HPS for synchronus data retrieval.

##  Skills Used
* Registers 
* I2C Communication Protocol 
* C++ Object Oriented Design 
* Makefiles
* Vi, GNC 
* ADXL345 
* Dynamic Memory Allocation 
* HPS - FPGA Bridge
* Quartus Prime
* PIO
* Platform Desigining
* Bit-Wise Operators
* Pin Planner


## Layout of the repository

there are several files that are used thorughout this program. De!SoCFpga.h represents the header file that interacts with the DE1SoC. These define the constants and bit registers. These also apply to the ADXL345, D1SoChps, Gsensor, and PIO Control. These files, as named all work in tandem to ultimately create the following image. 


<p align="center"><img src="https://nuvainqueur.wpengine.com/wp-content/uploads/2021/02/Screen-Shot-2021-02-08-at-6.51.55-PM-1.png" align=middle width=900pt height=750pt/></p>

<p align="center"><img src="https://nuvainqueur.wpengine.com/wp-content/uploads/2021/02/2160-video-1.gif" align=middle width=900pt height=750pt/></p>

![2bb5d450319f0a721c07d202cc35d324]()

![2nd GIF](https://nuvainqueur.wpengine.com/wp-content/uploads/2021/02/2160-video-1.gif)

## Useful information

1. The G-sensor in the DE1SoC board is a small, thin, ultralow power assumption 3-axis accelerometer with high-resolution measurement. 
2. Execution time = How long it takes the program to complete the simulation
3. Unit Circle = Circle of radius 1 with a center at the origin (0,0) on a standard coordinate system

## Credits
 Benoni Vainqueur 
 Ike Kaper
