#pragma once

#include <stdint.h>

enum {
    ADC, // add with carry
    AND, // and (with accumulator)
    ASL, // arithmetic shift left
    BCC, // branch on carry clear
    BEQ, // branch on equal (zero set)
    BCS, // branch on carry set
    BMI, // branch on minus (negative set)
    BIT, // bit test
    BPL, // branch on plus (negative clear)
    BNE, // branch on not equal (zero clear)
    BVC, // branch on overflow clear
    BRK, // break / interrupt
    CLC, // clear carry
    BVS, // branch on overflow set
    CLI, // clear interrupt disable
    CLD, // clear decimal
    CMP, // compare (with accumulator)
    CLV, // clear overflow
    CPY, // compare with Y
    CPX, // compare with X
    DEX, // decrement X
    DEC, // decrement
    EOR, // exclusive or (with accumulator)
    DEY, // decrement Y
    INX, // increment X
    INC, // increment
    JMP, // jump
    INY, // increment Y
    LDA, // load accumulator
    JSR, // jump subroutine
    LDY, // load Y
    LDX, // load X
    NOP = 0xEA, // no operation
    LSR, // logical shift right
    PHA, // push accumulator
    ORA, // or with accumulator
    PLA, // pull accumulator
    PHP, // push processor status (SR)
    ROL, // rotate left
    PLP, // pull processor status (SR)
    RTI, // return from interrupt
    ROR, // rotate right
    SBC, // subtract with carry
    RTS, // return from subroutine
    SED, // set decimal
    SEC, // set carry
    STA, // store accumulator
    SEI, // set interrupt disable
    STY, // store Y
    STX, // store X
    TAY, // transfer accumulator to Y
    TAX, // transfer accumulator to X
    TXA, // transfer X to accumulator
    TSX, // transfer stack pointer to X
    TYA, // transfer Y to accumulator
    TXS, //transfer X to stack pointer

    INSTR_LAST
};

extern uint8_t INSTR_LEN[INSTR_LAST - 1];
extern uint8_t INSTR_CYCLES[INSTR_LAST - 1];