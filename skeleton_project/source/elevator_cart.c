#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include "elevator_cart.h"


int get_floor_number(){
  if (hardware_read_floor_sensor(0))
      return 1;
  else if (hardware_read_floor_sensor(1))
      return 2;
  else if (hardware_read_floor_sensor(2))
      return 3;
  else if (hardware_read_floor_sensor(3))
      return 4;
  else return 0;
}

void start_elevator(){
   int error = hardware_init();
   if(error != 0){
        fprintf(stderr, "Unable to initialize hardware\n");
        exit(1);
    }
  
  //assert(get_floor_number() =< 0);
  //assert(get_floor_number() > HARDWARE_NUMBER_OF FLOORS); //Hvis heisen er mellom 1 og 4 så vil den ikke gå videre. 
  
  while (get_floor_number() == 0){
      hardware_command_movemnet(HARDWARE_MOVEMENT_UP);
  }
}






