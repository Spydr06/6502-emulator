#include "cpu.h"
#include <string.h>

void init_cpu(CPU* cpu)
{
    memset(cpu, 0, sizeof(CPU));
}

void dump_cpu_state(FILE* file, CPU* cpu)
{
    fprintf(file, 
        "CPU:\n"
        "  pc = %04x\n"
        "  sp = %04x\n"
        "  A = %02x\n"
        "  X = %02x\n"
        "  Y = %02x\n"
        "  status = %02x\n"
        "  address = %04x\n"
        "  data = %02x\n"
        "  cycles = %lu\n",
        (int) cpu->pc, (int) cpu->sp, (int) cpu->A, (int) cpu->X, (int) cpu->Y,
        (int) cpu->status, (int) cpu->address, (int) cpu->data, cpu->cycles
    );
}