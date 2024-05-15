/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Tic.hpp"
#include <cstdio>
#include <chrono>
#include <ratio>

AnalogIn current_mV(A0);
Timeout t;
TicT500 tic;


MemoryPool<float, 1024> mpool;
Queue<float, 1024> queue;

void currentRead()
{
    
}

void currentPrint()
{

}

int main()
{
printf("Start testbench \n\r");
t.attach_us(&currentRead, 1000);
t.attach(&currentPrint, 1);

    while (true) {

        tic.energize();
        tic.setTargetVelocity(1000000);
        
        ThisThread::sleep_for(10000ms);
        //tic.deenergize();
        tic.haltAndHold();
        ThisThread::sleep_for(5000ms);
    }
}
