#include "sock_stream.h"
#include "stuff.h"

SockStream SockStreamInit(int sock)
{
    return (SockStream){
        .fd = sock
    };
}

void SockClose(SockStream *s)
{
    close(s->fd);
}

int SockRead(SockStream *s, uint8_t *buf, int n)
{
    int len = recv(s->fd, buf, n, 0);
    assert(n >= 0);
    return len;
}

int SockWrite(SockStream *s, uint8_t *buf, int n)
{
    int len = send(s->fd, buf, n, 0);
    assert(n >= 0);
    return len;
}