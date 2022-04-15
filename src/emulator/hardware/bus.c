#include "bus.h"

void init_bus(BUS* bus)
{
    init_cpu(&bus->cpu);
    init_ram(&bus->ram);
}

uint8_t read_bus(BUS* bus, uint16_t addr)
{
    return bus->ram.bytes[addr];
}

void write_bus(BUS* bus, uint16_t addr, uint8_t value)
{
    bus->ram.bytes[addr] = value;
}