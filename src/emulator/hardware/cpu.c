#include "cpu.h"
#include <string.h>

void init_cpu(CPU* cpu)
{
    memset(cpu, 0, sizeof(CPU));
}