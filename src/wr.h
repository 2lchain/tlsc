#pragma once

#include <stdint.h>

typedef  int(*read_fn)(void*closure, uint8_t *buf, int n);
typedef  int(*write_fn)(void *closure, uint8_t *buf,int n);


typedef struct RW{
    read_fn read;
    write_fn write;
    void*closure;
}RW;

RW RWInit(void*closure, read_fn r, write_fn w);

uint8_t ReadU8(RW *s);

uint16_t ReadU16(RW *s);

uint32_t ReadU32(RW *s);

uint64_t ReadU64(RW *s);

void WriteU8(RW *s, uint8_t d);

void WriteU16(RW *s, uint16_t d);

void WriteU32(RW *s, uint32_t d);

void WriteU64(RW *s, uint64_t d);


int WriteAll(RW *s, char *buf, int n);
int ReadAll(RW *s, char *buf, int n);

int Write(RW *s, char *buf, int n);
int Read(RW *s, char *buf, int n);

