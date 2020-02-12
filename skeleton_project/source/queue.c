#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "hardware.h"



void updateQueue(){
	int i;
	HardwareOrder j; 

    for (i = 0; i < HARDWARE_NUMBER_OF_FLOORS; ++i){
        for (j = HARDWARE_ORDER_UP; j <= HARDWARE_ORDER_DOWN; ++j){ //Hardwareorders
        	if (hardware_read_order(i, j)){
        		//int a = i+1;
        		printf("%d",i);
        	}
        	Q_MATRIX[i][0] = hardware_read_order(i, j);
        }
    }
}
 
