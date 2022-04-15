#include "bus.h"

void init_bus(BUS* bus)
{
    init_cpu(&bus->cpu);
    init_ram(&bus->ram);
}