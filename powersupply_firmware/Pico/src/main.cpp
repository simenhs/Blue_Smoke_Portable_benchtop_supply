#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"





#include "Display.h"
#include "Flash.h"
#include "Pcb.h"
#include "Onoff.h"
#include "Hartbeat.h"
#include "ComandlineInterface.h"
#include "GUI.h"
#include "PSU.h"
#include "Analog.h"
#include "Knobs.h"
#include "Battery.h"


int main() {
    //sleep_ms(500);
    stdio_init_all();   // allowing printf debung in onoff init
    printf("hello world\r\n");
    // keap device powered on, need to be the frist thin that happens 
    Onoff::Init(); 
    
    //stdio_init_all();   

    Hartbeat hartbeat = Hartbeat(); 
    Analog::Init(); 
    PSU::Init(); 
    ComandLineInterface::Init();
    GUI::Init();
    Battery::Init();
    Knobs::Init();
     



    while (true) {
        
        //Onoff::KeepAlive(); 
        hartbeat.Update(); 
    
        PSU::Update(); 
        ComandLineInterface::Update();
        GUI::Update();
        Knobs::Update(); 
        Battery::Update(); 
        


     
    }
}