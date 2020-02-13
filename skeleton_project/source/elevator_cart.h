#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include <time.h>

typedef enum {
	IDLE,
	DOOR_OPEN,
	MOVING_DOWN,
	MOVING_UP,
	STOP,
}state;

state elevator_state; 

int get_floor_number();

void start_elevator();

void open_door();

