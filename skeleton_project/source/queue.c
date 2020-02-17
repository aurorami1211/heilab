#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "hardware.h"



void update_queue(){
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ 
        	if (hardware_read_order(floor, button) == 1){
        		Q_MATRIX[floor][button] = 1;
            }
       	}
    }
}

void reset_queue(){
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ 
            Q_MATRIX[floor][button] = 0; 
        }
    }
}

bool check_empty_queue(){
    for (int floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ 
            if (Q_MATRIX[floor][button] == 1){
                return false;
            } 
        }
    }
    return true;
}
 
void delete_order(int floor){
    for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){ 
        Q_MATRIX[floor][button] = 0;
}
}
