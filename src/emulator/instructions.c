#include "instructions.h"

uint8_t INSTR_LEN[INSTR_LAST - 1] = {
    [NOP] = 1,
    [JMP_ABS] = 3,
    [JMP_IND] = 3,
};

uint8_t INSTR_CYCLES[INSTR_LAST - 1] = {
    [JMP_ABS] = 3,
    [JMP_IND] = 5,
    [NOP] = 2
};