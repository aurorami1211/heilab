#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "hardware.h"



void updateQueue(){
	int floor;
	HardwareOrder button; 

    for (floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ //Hardwareorders
        	if (hardware_read_order(floor, button)){
        		int a = floor+1;
        		printf("%d",a);
        	}
		Q_MATRIX[floor][0] = hardware_read_order(floor, button);
		
		if(hardware_read_floor_sensor(floor){ //when you arrive at floor. Deletes the order. 
			Q_MATRIX[floor][button] = 0; 
		}
        }
    }
}
 
