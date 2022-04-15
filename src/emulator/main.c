#include <stdio.h>

#include "hardware/bus.h"

int main()
{
    BUS system;
    init_bus(&system);

    hexdump(stdout, &system.ram);
    return 0;
}