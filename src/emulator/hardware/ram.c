#include "ram.h"
#include <string.h>

void init_ram(RAM* ram)
{
    memset(ram, 0, sizeof(RAM));
}

void hexdump(FILE* file, RAM *ram)
{
    for(uint32_t i = 0; i < RAM_SIZE; i += 16)
        fprintf(file, "%x: %x%x %x%x %x%x %x%x %x%x %x%x %x%x %x%x\n", i, 
            ram->bytes[i + 0], ram->bytes[i + 1], ram->bytes[i + 2], ram->bytes[i + 3],
            ram->bytes[i + 4], ram->bytes[i + 5], ram->bytes[i + 6], ram->bytes[i + 7],
            ram->bytes[i + 8], ram->bytes[i + 9], ram->bytes[i + 10], ram->bytes[i + 11],
            ram->bytes[i + 12], ram->bytes[i + 13], ram->bytes[i + 14], ram->bytes[i + 15]
        );
}