#include "instructions.h"

uint8_t INSTR_LEN[INSTR_LAST - 1] = {
    [NOP] = 1
};

uint8_t INSTR_CYCLES[INSTR_LAST - 1] = {
    [NOP] = 2
};