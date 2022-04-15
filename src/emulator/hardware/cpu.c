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
        "  pc = %x\n"
        "  sp = %x\n"
        "  A = %x\n"
        "  X = %x\n"
        "  Y = %x\n"
        "  status = %x\n"
        "  address = %x\n"
        "  data = %x\n",
        (int) cpu->pc, (int) cpu->sp, (int) cpu->A, (int) cpu->X, (int) cpu->Y,
        (int) cpu->status, (int) cpu->address, (int) cpu->data
    );
}