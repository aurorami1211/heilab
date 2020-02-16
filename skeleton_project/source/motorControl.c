   #include "motorControl.h"


   /*
        if(hardware_read_stop_signal()){
            hardware_command_movement(HARDWARE_MOVEMENT_STOP);
            break;
        }

        if(hardware_read_floor_sensor(0)){
            hardware_command_movement(HARDWARE_MOVEMENT_UP);
        }
        if(hardware_read_floor_sensor(HARDWARE_NUMBER_OF_FLOORS - 1)){
            hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
        }*/


void set_moving_state(){
    if(prev_dir == UP){

        for (int floor = prev_floor; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
            for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
        
                if (Q_MATRIX[floor][button]==1){
                    elevator_state = MOVING_UP;
                    return;
                }
            }
        }
        prev_dir = DOWN;
        elevator_state = MOVING_DOWN;
        return;
    }
    else{
        for (int floor = prev_floor; floor <= 0; --floor){
            for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
                if (Q_MATRIX[floor][button]==1){

                    elevator_state = MOVING_DOWN;
                    return;
                }
            }
        }
        prev_dir = UP;
        elevator_state = MOVING_UP;
    }
}

void set_destination_up(){
    for (int floor = prev_floor; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
            if (Q_MATRIX[floor][button]==1){
                destination = floor;
                return;
            }
        }
    } 
}
void set_destination_up_moving(){
    for (int floor = prev_floor; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_INSIDE; ++button){
            if (Q_MATRIX[floor][button]==1){
                destination = floor;
                return;
            }
        }
    } 
}


void set_destination_down(){
    for (int floor = prev_floor; floor >= 0; --floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
            if (Q_MATRIX[floor][button]==1){
                destination = floor;
                return;
            }
        }
    }
}

void set_destination_down_moving(){
    for (int floor = prev_floor; floor >= 0; --floor){
        for (HardwareOrder button = HARDWARE_ORDER_INSIDE; button <= HARDWARE_ORDER_DOWN; ++button){
            if (Q_MATRIX[floor][button]==1){
                destination = floor;
                return;
            }
        }
    }
}