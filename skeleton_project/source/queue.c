#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void updateQueue(){
    for (int i = 0; i < HARDWARE_NUMBER_OF_FLOORS; ++i){
        for (int j = 0; j < 3; ++j){ //Hardwareorders
            QueueMatrix[i][j] = hardware_read_order(floor + 1, orderArray*); //hvordan iterere gjennom hardwareorders?
        }
    }
}
