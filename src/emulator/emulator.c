#include "emulator.h"
#include "instructions.h"

void emulate(BUS* bus)
{

}

void emulate_op(BUS* bus, uint16_t addr)
{
    uint8_t instr = bus->ram.bytes[addr];
    switch(instr)
    {
    case NOP:
        break;

    default:
        fprintf(stderr, "0x%04x: unknown instruction \"0x%02X\"\n", addr, instr);
        return;
    }

    bus->cpu.pc += INSTR_LEN[instr];
}