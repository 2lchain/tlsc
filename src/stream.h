#pragma once

#include <sys/socket.h>
#include <stdint.h>
#include<assert.h>
#include "sock.h"


typedef struct Stream {
    int fd;
} Stream;

Stream StreamInit(int sock);
void Close(Stream *s);

uint8_t ReadU8(Stream *s);

uint16_t ReadU16(Stream *s);

uint32_t ReadU32(Stream *s);

uint64_t ReadU64(Stream *s);

void WriteU8(Stream *s, uint8_t d);

void WriteU16(Stream *s, uint16_t d);

void WriteU32(Stream *s, uint32_t d);

void WriteU64(Stream *s, uint64_t d);

int Write(Stream *s, char *buf, int n);

int WriteAll(Stream *s, char *buf, int n);

int Read(Stream *s, char *buf, int n);

int ReadAll(Stream *s, char *buf, int n);

