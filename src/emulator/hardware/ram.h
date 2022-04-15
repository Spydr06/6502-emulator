#pragma once

#include <stdint.h>
#include <stdio.h>

#define RAM_SIZE 0xffff

typedef struct {
    uint8_t bytes[RAM_SIZE];
} RAM;

void init_ram(RAM* ram);
void hexdump(FILE* file, RAM* ram);