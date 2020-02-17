#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "hardware.h"
#include <time.h>
#include "queue.h"
#include "motor_control.h"
#include "lights.h"

typedef enum {
	IDLE,
	DOOR_OPEN,
	MOVING_DOWN,
	MOVING_UP,
	STOP,
}states;

struct Elevator_cart{
	direction prev_direction;
	int prev_floor;
	int destination;
	
	states state;

}

Elevator_cart TheElevator;


int get_floor_number();

void set_prev_floor();

void start_elevator();

void open_door();

void check_stop();