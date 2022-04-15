#pragma once
#include "hardware/bus.h"

void emulate(BUS* system);
void emulate_op(BUS* bus, uint16_t addr);