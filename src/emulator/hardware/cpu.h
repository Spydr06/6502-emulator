#pragma once

#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint16_t pc; // Program counter
    uint8_t sp;  // Stack pointer
    
    uint8_t A; // Accumulator
    uint8_t X; // X Register
    uint8_t Y; // Y Register

    union {
        uint8_t status;
        struct {
            int carry_flag        : 1;
            int zero_flag         : 1;
            int interrupt_disable : 1;
            int decimal_mode      : 1;
            int break_command     : 1;
            int overflow_flag     : 1;
            int negative_flag     : 1;
        };
    };

    union {
        uint16_t address;
        struct {
            int a0 :1, a1 :1, a2 :1, a3 :1, a4 :1, a5 :1, a6 :1, a7:1,
            a8 :1, a9 :1, a10 :1, a11 :1, a12 :1, a13 :1, a14 :1, a15 :1;
        };
    };

    union {
        uint8_t data;
        struct {
            int d0 :1, d1 :1, d2 :1, d3 :1, d4 :1, d5 :1, d6 :1, d7:1;
        };
    };
} CPU;

typedef enum {
    ADDR_MODE_IMP,
    ADDR_MODE_ACC,
    ADDR_MODE_IMM,
    ADDR_MODE_IND_JMP,
    ADDR_MODE_REL,
    ADDR_MODE_ABS,
    ADDR_MODE_ABS_JMP,
    ADDR_MODE_ZP,
    ADDR_MODE_ZP_IND_X,
    ADDR_MODE_ZP_IND_Y,
    ADDR_MODE_ABS_X,
    ADDR_MODE_ABS_Y,
    ADDR_MODE_IND_X,
    ADDR_MODE_IND_Y
} AddressMode;

void init_cpu(CPU* cpu);
void dump_cpu_state(FILE* file, CPU* cpu);