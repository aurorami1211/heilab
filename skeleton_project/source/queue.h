#pragma once

#include <stdbool.h>

unsigned int Q_MATRIX[4][3];

int prev_floor;




void update_queue(); 

void reset_queue();

bool empty_queue();

void delete_order(int floor);