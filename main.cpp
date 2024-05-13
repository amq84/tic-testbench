/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include "Tic.hpp"
#include <cstdio>


TicT500 tic;
int main()
{
printf("Start testbench \n\r");

    while (true) {

        tic.energize();
        tic.setTargetVelocity(1000000);
        
        ThisThread::sleep_for(10000ms);
        //tic.deenergize();
        tic.haltAndHold();
        ThisThread::sleep_for(5000ms);
    }
}
