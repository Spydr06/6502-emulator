#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "hardware/bus.h"
#include "instructions.h"
#include "emulator.h"

int main()
{
    BUS system;
    init_bus(&system);
    system.cpu.pc = 0xfff0;

    memcpy(system.ram.bytes, 
        (uint8_t[RAM_SIZE]) {
            [0xfff0] = NOP,
            [0xfff1] = NOP,
            [0xfff2] = NOP
        }, 
    RAM_SIZE);

    emulate_op(&system, 0xfff0);
    emulate_op(&system, 0xfff1);
    emulate_op(&system, 0xfff2);
    emulate_op(&system, 0xfff3);

    hexdump(stdout, &system.ram);
    dump_cpu_state(stdout, &system.cpu);

    return 0;
}