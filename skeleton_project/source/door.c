#include <door.h>

void open_door(){
  do {
    int time = 3000;
    clock_t start_time = clock();

    while(clock() < start_time + time) {
      hardware_command_door_open(1);
      break;
    } 
  } while (!hardware_read_obstruction);
  
  hardware_command_door_open(0);
}

