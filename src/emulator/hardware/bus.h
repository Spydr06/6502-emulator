#pragma once

#include "cpu.h"
#include "ram.h"

typedef struct {
    CPU cpu;
    RAM ram;
} BUS;

void init_bus(BUS* bus);