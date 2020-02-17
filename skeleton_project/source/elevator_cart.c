
#include "elevator_cart.h"
#


int get_floor_number(){
  if (hardware_read_floor_sensor(0))
      return 0;
  else if (hardware_read_floor_sensor(1))
      return 1;
  else if (hardware_read_floor_sensor(2))
      return 2;
  else if (hardware_read_floor_sensor(3))
      return 3;
  else return -1;
}

void set_prev_floor(){
  if (get_floor_number() != -1){
    TheElevator.prev_floor = get_floor_number();
  }
}

void start_elevator(){
   int error = hardware_init();
   if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
  
  while (get_floor_number() != 0){
      hardware_command_movement(HARDWARE_MOVEMENT_DOWN);
  }
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  TheElevator.state = IDLE;
  TheElevator.prev_floor = 0;
}


void open_door(){
  clock_t start_time = clock();
  do {
    hardware_command_movement(HARDWARE_MOVEMENT_STOP);
    update_queue();
    set_lights();
    if(hardware_read_stop_signal()){
        TheElevator.state = STOP;
        break;
    }
    hardware_command_door_open(1);
    if (hardware_read_obstruction_signal()){
        start_time = clock();
    }
    check_stop();


  } while (clock()-start_time < 3*CLOCKS_PER_SEC);
  
  hardware_command_door_open(0);
  }


void check_stop(){
  if(hardware_read_stop_signal()){
    TheElevator.state = STOP;
  }
}