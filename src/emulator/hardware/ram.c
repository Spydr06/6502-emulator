#include "ram.h"
#include <string.h>

void init_ram(RAM* ram)
{
    memset(ram, 0, sizeof(RAM));
}

void hexdump(FILE* file, RAM *ram)
{
    fprintf(file, "RAM:\n");
    for(uint32_t i = 0; i < RAM_SIZE; i += 8)
    {
        uint8_t null[8] = {};
        uint16_t start = i;
        while(!memcmp(&ram->bytes[i], null, 8) && i < RAM_SIZE) 
            i += 8;
        fprintf(file, "  0x%04x - 0x%04x: 00\n", start, i);
        
        if(i >= RAM_SIZE) 
            break;
        
        fprintf(file, "  0x%04x: %02X %02X %02X %02X %02X %02X %02X %02X\n", i, 
            ram->bytes[i + 0], ram->bytes[i + 1], ram->bytes[i + 2], ram->bytes[i + 3],
            ram->bytes[i + 4], ram->bytes[i + 5], ram->bytes[i + 6], ram->bytes[i + 7]
        );
    }
}