   #include "motor_control.h"


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
    if(check_empty_queue()){
        TheElevator.state = IDLE;
    }
    else if (get_floor_number() == -1){
        set_destination_up();
        set_destination_down();
        if (TheElevator.prev_direction == UP){
            if (TheElevator.destination <= TheElevator.prev_floor){
                TheElevator.state = MOVING_DOWN;
            }
            else{
                TheElevator.state = MOVING_UP;
            }
        }
        else {
            if (TheElevator.destination >= TheElevator.prev_floor){
                TheElevator.state = MOVING_UP;
            }
            else{
                TheElevator.state = MOVING_DOWN;
            }
        }
        
    }
    else if(TheElevator.prev_floor == 3){
        TheElevator.prev_direction = DOWN;
        TheElevator.state = MOVING_DOWN;
    }
    else if(TheElevator.prev_floor==0){
        TheElevator.prev_direction = UP;
        TheElevator.state  = MOVING_UP;
    }else{
         set_moving_state_middle_floors();
    }
}

void set_moving_state_middle_floors(){
    if(TheElevator.prev_direction == UP){

        for (int floor = TheElevator.prev_floor; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
            for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
        
                if (Q_MATRIX[floor][button]==1){
                    TheElevator.state = MOVING_UP;
                    return;
                }
            }
        }
        TheElevator.prev_direction = DOWN;
        TheElevator.state = MOVING_DOWN;
        return;
    }
    else{
        for (int floor = TheElevator.prev_floor; floor >= 0; --floor){
            for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
                if (Q_MATRIX[floor][button]==1){
                    TheElevator.state = MOVING_DOWN;
                    return;
                }
            }
        }
        TheElevator.prev_direction = UP;
        TheElevator.state = MOVING_UP;
    }
}


void set_destination_up(){
    for (int floor = TheElevator.prev_floor; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
            if (Q_MATRIX[floor][button]==1){
                TheElevator.destination = floor;
                return;
            }
        }
    } 
}

void set_destination_up_while_moving(){
    for (int floor = TheElevator.prev_floor; floor < HARDWARE_NUMBER_OF_FLOORS; ++floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_INSIDE; ++button){
            if (Q_MATRIX[floor][button]==1){
                TheElevator.destination = floor;
                return;
            }
        }
    } 
}


void set_destination_down(){
    for (int floor = TheElevator.prev_floor; floor >= 0; --floor){
        for (HardwareOrder button = HARDWARE_ORDER_UP; button <= HARDWARE_ORDER_DOWN; ++button){
            if (Q_MATRIX[floor][button]==1){
                TheElevator.destination = floor;
                return;
            }
        }
    }
}

void set_destination_down_while_moving(){
    for (int floor = TheElevator.prev_floor; floor >= 0; --floor){
        for (HardwareOrder button = HARDWARE_ORDER_INSIDE; button <= HARDWARE_ORDER_DOWN; ++button){
            if (Q_MATRIX[floor][button]==1){
                TheElevator.destination = floor;
                return;
            }
        }
    }
}