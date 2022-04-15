#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>

#include "hardware/bus.h"
#include "instructions.h"
#include "emulator.h"

static BUS system_bus;

void int_handler(int signal)
{
    printf("\n");
    hexdump(stdout, &system_bus.ram);
    dump_cpu_state(stdout, &system_bus.cpu);
    exit(130);
}

int main()
{
    signal(SIGINT, int_handler);

    init_bus(&system_bus);
    system_bus.cpu.pc = 0xfff0;

    memcpy(system_bus.ram.bytes, 
        (uint8_t[RAM_SIZE]) {
            [0xfff0] = NOP,
            [0xfff1] = JMP_ABS, 0xf0, 0xff
        }, 
    RAM_SIZE);

    emulate(&system_bus);

    hexdump(stdout, &system_bus.ram);
    dump_cpu_state(stdout, &system_bus.cpu);

    return 0;
}