#include "instructions.h"

uint8_t INSTR_LEN[0xff] = {
    [NOP] = 1,
    [JMP_ABS] = 3,
    [JMP_IND] = 3,
    [INX] = 1,
    [INY] = 1,
    [DEX] = 1,
    [DEY] = 1,
    [TAY] = 1,
    [TAX] = 1,
    [TXA] = 1,
    [TYA] = 1,
    [TXS] = 1,
    [TSX] = 1,
};

uint8_t INSTR_CYCLES[0xff] = {
    [NOP] = 2,
    [JMP_ABS] = 3,
    [JMP_IND] = 5,
    [INX] = 2,
    [INY] = 2,
    [DEX] = 2,
    [DEY] = 2,
    [TAY] = 2,
    [TAX] = 2,
    [TXA] = 2,
    [TYA] = 2,
    [TXS] = 2,
    [TSX] = 2,
};