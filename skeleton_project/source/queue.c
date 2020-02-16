#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "hardware.h"



void update_queue(){
	//int floor;
	//HardwareOrder button; 

    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ //Hardwareorders
        	if (hardware_read_order(floor, button) == 1){
        		Q_MATRIX[floor][button] = 1;
            } 
       	}
        
		/*if(hardware_read_floor_sensor(floor)){ //when you arrive at floor. Deletes the order. 
			//Q_MATRIX[floor][button] = 0; 
            open_door();
		}*/
    }
}

void reset_queue(){
    int floor;
    HardwareOrder button; 
    for (floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ //Hardwareorders
            Q_MATRIX[floor][button] = 0; 
        }
    }
}

bool empty_queue(){
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ //Hardwareorders
            if (Q_MATRIX[floor][button] == 1){
                return false;
            } 
        }
    }
    return true;
}
 
void delete_order(int floor){
    for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ //Hardwareo
        Q_MATRIX[floor][button] = 0;
}
}
