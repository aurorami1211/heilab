#pragma once

#include "elevator_cart.h"
#include <stdio.h>
#include <stdlib.h>





typedef enum{
	UP,
	DOWN,
}direction;

void set_moving_state();

void set_moving_state_middle_floors();


void set_destination_up();

void set_destination_up_while_moving();

void set_destination_down();

void set_destination_down_while_moving();