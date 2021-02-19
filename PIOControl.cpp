//COPIED FROM LAB4B
#include "PIOControl.h"

#include <iostream>

using namespace std;

PIOControl::PIOControl()
{
    out_regValue = RegisterRead(OUT_BASE);
    in_regValue = RegisterRead(IN_BASE);
    //leds_regValue = RegisterRead(LEDR_BASE)
}

PIOControl::~PIOControl()
{
    cout << "Closing PIO's..." << endl;
}

void PIOControl::WritePIOout(int value)//WriteAllLeds(int value) 
{
    RegisterWrite(OUT_BASE, value);
    out_regValue = value;
}

int PIOControl::ReadPIOin()//ReadAllSwitches()
{
    return RegisterRead(IN_BASE);
    in_regValue = RegisterRead(IN_BASE);
}



