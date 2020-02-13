
#include "elevator_cart.h"


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

void start_elevator(){
   int error = hardware_init();
   if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
  
  while (get_floor_number() == -1){
      hardware_command_movement(HARDWARE_MOVEMENT_UP);
  }
  hardware_command_movement(HARDWARE_MOVEMENT_STOP);
  elevator_state = IDLE;
}


void open_door(){
  do {
    int time = 3000;
    clock_t start_time = clock();
    hardware_command_door_open(1);
    while(clock() < start_time + time) {
      hardware_command_floor_indicator_on(get_floor_number());
      break;
    } 
  } while (hardware_read_obstruction_signal());
  
  hardware_command_door_open(0);
}


