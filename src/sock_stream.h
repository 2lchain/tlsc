#pragma once

#include <sys/socket.h>
#include <stdint.h>
#include<assert.h>
#include "sock.h"


typedef struct SockStream {
    int fd;
} SockStream;

SockStream SockStreamInit(int sock);
void SockClose(SockStream *s);
int SockWrite(SockStream *s, uint8_t *buf, int n);
int SockRead(SockStream *s, uint8_t*buf, int n);


