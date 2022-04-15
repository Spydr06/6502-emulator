#include "emulator.h"
#include "instructions.h"

void emulate(BUS* bus)
{
    while(emulate_op(bus)) {}
    printf("-> finished execution\n");
}

bool emulate_op(BUS* bus)
{
    uint8_t instr = bus->ram.bytes[bus->cpu.pc];
    switch(instr)
    {
    case NOP:
        bus->cpu.pc++;
        break;
    case JMP_ABS:
    case JMP_IND:
        bus->cpu.pc = bus->ram.bytes[bus->cpu.pc + 1] | bus->ram.bytes[bus->cpu.pc + 2] << 8;
        break;

    default:
        fprintf(stderr, "0x%04x: unknown instruction \"0x%02X\"\n", bus->cpu.pc, instr);
        return false;
    }
    bus->cpu.cycles = INSTR_CYCLES[instr];
    return true;
}