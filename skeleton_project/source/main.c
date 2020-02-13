#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "elevator_cart.h"
#include "queue.h"



int main(){
    //printf("Press the stop button on the elevator panel to exit\n");

    //hardware_command_movement(HARDWARE_MOVEMENT_UP);

    start_elevator();

    while(1){

        switch(elevator_state){
            case IDLE:
                if(hardware_read_stop_signal()){
                    elevator_state = STOP;
                }
                update_queue();
                elevator_state  = MOVING_UP;
                break;
            case MOVING_UP:
                hardware_command_movement(HARDWARE_MOVEMENT_UP);
                if (get_floor_number() != -1){
                    elevator_state = DOOR_OPEN;
                }
                /*else if(hardware_read_floor_sensor(0)){
                    hardware_command_movement(HARDWARE_MOVEMENT_UP);
                }
                else if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
                    hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
                }*/
                /*if (!hardware_read_stop_signal()){
                    elevator_state = MOVING_UP; //ENDRE TIL IDLE
                }*/
                break;
            case MOVING_DOWN:
                break;
            case STOP:
                reset_queue();
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                if (!hardware_read_stop_signal()){
                    elevator_state = IDLE; //ENDRE TIL IDLE
                }
                break;
            case DOOR_OPEN:
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                open_door();
                elevator_state = MOVING_UP;
                break;
        }

        //updateQueue();
        if (hardware_read_obstruction_signal()){
            break;
        }
    }

    int floor;
    HardwareOrder button; 

    for (floor = 0; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        printf(" (");
        /*printf("floor ");

        printf("%d", floor);
        printf(": ");*/
        for (button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
            //printf("button ");
            //printf("%d", button);
            printf("%d     ", Q_MATRIX[floor][button]);
        }
        printf(")\n");
    }
}
