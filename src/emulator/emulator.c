#include "emulator.h"
#include "instructions.h"

void emulate(BUS* bus)
{
    while(emulate_op(bus)) {}
    printf("-> finished execution at address 0x%04x\n", bus->cpu.pc);
}

bool emulate_op(BUS* bus)
{
    uint16_t addr = bus->cpu.pc;
    uint8_t instr = bus->ram.bytes[addr];

    bus->cpu.pc += INSTR_LEN[instr];
    bus->cpu.cycles = INSTR_CYCLES[instr];

    switch(instr)
    {
    case NOP:
        break;

    case JMP_ABS:
        bus->cpu.pc = bus->ram.bytes[addr + 1] | bus->ram.bytes[addr + 2] << 8;
        break;

    case JMP_IND:
        bus->cpu.pc = bus->ram.bytes[
            bus->ram.bytes[addr + 1] | bus->ram.bytes[addr + 2] << 8
        ];
        break;

    case INX:
        bus->cpu.X++;
        break;
    
    case INY:
        bus->cpu.Y++; 
        break;
    
    case DEX:
        bus->cpu.X--;
        break;
    
    case DEY:
        bus->cpu.Y--; 
        break;
    
    case TAY:
        bus->cpu.Y = bus->cpu.A;
        break;
    
    case TAX:
        bus->cpu.X = bus->cpu.A;
        break;
    
    case TXA:
        bus->cpu.A = bus->cpu.X;
        break;

    case TYA:
        bus->cpu.A = bus->cpu.Y;
        break;
    
    case TSX:
        bus->cpu.X = bus->cpu.sp;
        break;
    
    case TXS:
        bus->cpu.sp = bus->cpu.X;
        break;
    
    // HLT, KIL, JAM
    case 0x02: case 0x12: case 0x22: case 0x32:
    case 0x92: case 0xB2: case 0xD2: case 0xF2:
    case 0x42: case 0x52: case 0x62: case 0x72: 
        return false;
    
    default:
        fprintf(stderr, "0x%04x: unknown instruction \"0x%02X\"\n", addr, instr);
        return false;
    }
    return true;
}