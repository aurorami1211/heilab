#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "elevator_cart.h"
#include "queue.h"
#include "motorControl.h"



int main(){
    //printf("Press the stop button on the elevator panel to exit\n");

    //hardware_command_movement(HARDWARE_MOVEMENT_UP);

    start_elevator();



    while(1){

        switch(elevator_state){
            case IDLE:
                check_stop();
                update_queue();
                set_prev_floor();
                set_destination_up();
               if(empty_queue()){
                    elevator_state = IDLE;
                }
                else if (get_floor_number() == -1 && destination == prev_floor){
                    if (prev_dir == UP){
                        elevator_state = MOVING_DOWN;
                    }
                    else if (prev_dir == DOWN){
                        elevator_state = MOVING_UP;
                    }
                }
                else if(prev_floor==3){
                    prev_dir = DOWN;
                    elevator_state = MOVING_DOWN;
                }else if(prev_floor==0){
                    prev_dir = UP;
                    elevator_state  = MOVING_UP;
                }else{
                    set_moving_state();
                }

                break;

            case MOVING_UP:
                set_destination_up();
                while(get_floor_number() != destination){
                    if(hardware_read_stop_signal()){
                        elevator_state = STOP;
                        break;
                    }
                    hardware_command_movement(HARDWARE_MOVEMENT_UP);
                    update_queue();
                    set_destination_up_moving();
                    set_prev_floor();
                }
                elevator_state = DOOR_OPEN;
                if(hardware_read_stop_signal()){
                        elevator_state = STOP;
                        break;
                    }

                break;
            case MOVING_DOWN:
                 set_destination_down();
                while(get_floor_number() != destination){
                    if(hardware_read_stop_signal()){
                        elevator_state = STOP;
                        break;
                    }
                    hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
                   check_stop();
                    update_queue();
                    set_prev_floor();
                    set_destination_down_moving();
                }
                elevator_state = DOOR_OPEN;
                if(hardware_read_stop_signal()){
                        elevator_state = STOP;
                        break;
                }
        
                break;
            case STOP:
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);
                if (!hardware_read_stop_signal()){
                    elevator_state = IDLE; //ENDRE TIL IDLE
                }
                reset_queue();
                break;
            case DOOR_OPEN:
                check_stop();
                update_queue();
                set_prev_floor();
                hardware_command_movement(HARDWARE_MOVEMENT_STOP);

                open_door();
                delete_order(destination);
                elevator_state = IDLE;
                break;
        }

        //updateQueue();
        

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
