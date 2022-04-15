#pragma once

#include "cpu.h"
#include "ram.h"

typedef struct {
    CPU cpu;
    RAM ram;
} BUS;

void init_bus(BUS* bus);
uint8_t read_bus(BUS* bus, uint16_t addr);
void write_bus(BUS* bus, uint16_t addr, uint8_t value);