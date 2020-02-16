#pragma once

#include "elevator_cart.h"
#include <stdio.h>
#include <stdlib.h>





typedef enum{
	UP,
	DOWN,
}dir;


dir prev_dir;

int destination;

void set_moving_state();

void set_destination_up();

void set_destination_up_moving();

void set_destination_down();

void set_destination_down_moving();