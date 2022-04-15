#pragma once
#include "hardware/bus.h"
#include <stdbool.h>

void emulate(BUS* system);
bool emulate_op(BUS* bus);