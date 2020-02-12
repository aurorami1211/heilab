#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void updateQueue(){
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; ++i){
        for (HardwareOrder j = HARDWARE_ORDER_UP; j < HARDWARE_ORDER_DOWN; ++j){ //Hardwareorders
            QueueMatrix[i][j] = hardware_read_order(i + 1, j);
        }
    }
}
 
