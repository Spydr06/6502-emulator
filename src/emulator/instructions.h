#pragma once

#include <stdint.h>

enum {
    // add memory to accumulator with carry
    ADC_IM = 0x69,   // immediate
    ADC_ZP = 0x65,   // zeropage
    ADC_ZPX = 0x75,  // zeropage,X
    ADC_ABS = 0x6D,  // absolute
    ADC_ABSX = 0x7D, // absolute,X
    ADC_ABSY = 0x79, // absolute,Y
    ADC_INDX = 0x61, // (indirect,X)
    ADC_INDY = 0x71, // (indirect),Y

    // and memory with accumulator
    AND_IM = 0x29,   // immediate
    AND_ZP = 0x25,   // zeropage
    AND_ZPX = 0x35,  // zeropage,X
    AND_ABS = 0x2D,  // absolute
    AND_ABSX = 0x3D, // absolute,X
    AND_ABSY = 0x39, // absolute,Y
    AND_INDX = 0x21, // (indirect,X)
    AND_INDY = 0x31, // (indirect),Y

    // shift left one bit (memory or accumulator)
    ASL_ACU = 0x0A,  // accumulator
    ASL_ZP = 0x06,   // zeropage
    ASL_ZPX = 0x16,  // zeropage,X
    ASL_ABS = 0x0E,  // absolute
    ASL_ABSX = 0x1E, // absolute,X

    BCC = 0x90, // branch on carry clear
    BCS = 0xB0, // branch on carry set
    BEQ = 0xF0, // branch on equal (zero set)
    BMI = 0x30, // branch on minus (negative set)

    // test bits in memory with accumulator
    BIT_ZP = 0x24,  // zeropage
    BIT_ABS = 0x2C, // absolute
    
    BPL = 0x10, // branch on plus (negative clear)
    BNE = 0xD0, // branch on not equal (zero clear)
    BRK = 0x00, // break / interrupt
    BVC = 0x50, // branch on overflow clear
    BVS = 0x70, // branch on overflow set
    CLC = 0x18, // clear carry
    CLD = 0xD8, // clear decimal
    CLI = 0x58, // clear interrupt disable
    CLV = 0xB8, // clear overflow

    // compare memory with accumulator
    CMP_IM = 0xC9,   // immediate
    CMP_ZP = 0xC5,   // zeropage
    CMP_ZPX = 0xD5,  // zeropage,X
    CMP_ABS = 0xCD,  // absolute
    CMP_ABSX = 0xDD, // absolute,X
    CMP_ABSY = 0xD9, // absolute,Y
    CMP_INDX = 0xC1, // (indirect,X)
    CMP_INDY = 0xD1, // (indirect),Y
    
    // compare memory and index X
    CPX_IM = 0xE0,  // immediate
    CPX_ZP = 0xE4,  // zeropage
    CPX_ABS = 0xEC, // absolute
    
    // compare memory and index Y
    CPY_IM = 0xC0,
    CPY_ZP = 0xC4,
    CPY_ABS = 0xCC,
    
    // decrement memory by one
    DEC_ZP = 0xC6,   // zeropage
    DEC_ZPX = 0xD6,  // zeropage,X
    DEC_ABS = 0xCE,  // absolute
    DEC_ABSX = 0xDE, // absolute,X

    DEX = 0xCA, // decrement X
    DEY = 0x88, // decrement Y

    // exclusive-or memory with accumulator
    EOR_IM = 0x49,   // immediate
    EOR_ZP = 0x45,   // zeropage
    EOR_ZPX = 0x55,  // zeropage,X
    EOR_ABS = 0x4D,  // absolute
    EOR_ABSX = 0x5D, // absolute,X
    EOR_ABSY = 0x59, // absolute,Y
    EOR_INDX = 0x41, // (indirect,X)
    EOR_INDY = 0x51, // (indirect),Y

    // increment memory by one
    INC_ZP = 0xE6,   // zeropage
    INC_ZPX = 0xF6,  // zeropage,X
    INC_ABS = 0xEE,  // absolute
    INC_ABSX = 0xFE, // absolute,X

    INX = 0xE8, // increment X
    INY = 0xC8, // increment Y
    JMP_ABS = 0x4C, // jump (absolute mode)
    JMP_IND = 0x6C, // jump (indirect)
    JSR = 0x20, // jump subroutine

    // load accumulator with memory
    LDA_IM = 0xA9,    
    LDA_ZP = 0xA5,
    LDA_ZPX = 0xB5,
    LDA_ABS = 0xAD,
    LDA_ABSX = 0xBD,
    LDA_ABSY = 0xB9, //
    LDA_IDNX = 0xA1, // (indirect,X)
    LDA_INDY = 0xB1, // (indirect),Y
    
    // load index Y with memory
    LDY_IM = 0xA0,
    LDY_ZP = 0xA4,
    LDY_ZPX = 0xB4,
    LDY_ABS = 0xAC,
    LDY_ABSX = 0xBC,
    
    // load index X with memory
    LDX_IM = 0xA2,
    LDX_ZP = 0xA6,
    LDX_ZPY = 0xB6,
    LDX_ABS = 0xAE,
    LDX_ABSY = 0xBE,
    
    // shift one bit right (memory or accumulator)
    LSR_ACU = 0x4A,
    LSR_ZP = 0x46,
    LSR_ZPX = 0x56,
    LSR_ABS = 0xAC,
    LSR_ABSX = 0xBC,

    NOP = 0xEA, // no operation

    // or memory with accumulator
    ORA_IM = 0x09,   // immediate
    ORA_ZP = 0x05,   // zeropage
    ORA_ZPX = 0x15,  // zeropage,X
    ORA_ABS = 0x0D,  // absolute
    ORA_ABSX = 0x1D, // absolute,X
    ORA_ABSY = 0x19, // absolute,Y
    ORA_INDX = 0x01, // (indirect,X)
    ORA_INDY = 0x11, // (indirect),Y

    PHA = 0x48, // push accumulator
    PLA = 0x68, // pull accumulator
    PHP = 0x08, // push processor status (SR)

    // rotate one left (memory or accumulator)
    ROL_ACC = 0x2A,  // accumulator
    ROL_ZP = 0x26,   // zeropage
    ROL_ZPX = 0x36,  // zeropage,X
    ROL_ABS = 0x2E,  // absolute
    ROL_ABSX = 0x3E, // absolute,X

    // rotate one bit right (memory or accumulator)
    ROR_ACC = 0x6A,  // accumulator
    ROR_ZP = 0x66,   // zeropage
    ROR_ZPX = 0x76,  // zeropage,X
    ROR_ABS = 0x6E,  // absolute
    ROR_ABSX = 0x7E, // absolute,X

    PLP = 0x28, // pull processor status (SR)
    RTI = 0x40, // return from interrupt
    RTS = 0x60, // return from subroutine

    // subtract memory from accumulator with borrow
    SBC_IM = 0xE9,
    SBC_ZP = 0xE5,
    SBC_ZPX = 0xF5,
    SBC_ABS = 0xED,
    SBC_ABSX = 0xFD,
    SBC_ABSY = 0xF9,
    SBC_INDX = 0xE1,
    SBC_INDY = 0xF1,

    SEC = 0x38, // set carry
    SED = 0xF8, // set decimal
    SEI = 0x78, // set interrupt disable

    // store accumulator in memory
    STA_ZP = 0x85,
    STA_ZPX = 0x95,
    STA_ABS = 0x8D,
    STA_ABSX = 0x9D,
    STA_ABSY = 0x99,
    STA_INDX = 0x81,
    STA_INDY = 0x91,

    // store index X in memory
    STX_ZP = 0x86,
    STX_ZPY = 0x96,
    STX_ABS = 0x8E,

    // store index Y in memory
    STY_ZP = 0x84,
    STY_ZPX = 0x94,
    STY_ABS = 0x8C,
    
    TAY = 0xA8, // transfer accumulator to Y
    TAX = 0xAA, // transfer accumulator to X
    TXA = 0x8A, // transfer X to accumulator
    TSX = 0xBA, // transfer stack pointer to X
    TYA = 0x98, // transfer Y to accumulator
    TXS = 0x9A, // transfer X to stack pointer
    HLT = 0x02, // op codes: 02, 12, 22, 32, 42, 52, 62, 72, 92, B2, D2, F2
    JAM = HLT,
    KIL = HLT,
};

extern uint8_t INSTR_LEN[0xff];
extern uint8_t INSTR_CYCLES[0xff];