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
            [0x0088] = HLT,
            [0x1000] = INX,
            DEY,
            TXA,
            JMP_IND, 0x55, 0x44,
            [0x4455] = 0x88, 0x00,
            [0xfff0] = NOP,
            JMP_ABS, 0x00, 0x10
        }, 
    RAM_SIZE);

    emulate(&system_bus);

    hexdump(stdout, &system_bus.ram);
    dump_cpu_state(stdout, &system_bus.cpu);

    return 0;
}