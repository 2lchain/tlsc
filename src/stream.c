#include "stream.h"
#include "stuff.h"

Stream StreamInit(int sock)
{
    return (Stream){
        .fd = sock};
}

void Close(Stream *s)
{
    close(s->fd);
}

uint8_t ReadU8(Stream *s)
{
    uint8_t buf;
    int n = recv(s->fd, &buf, 1, 0);
    assert(n == 1);
    return buf;
}

uint16_t ReadU16(Stream *s)
{
    uint16_t buf;
    int n = recv(s->fd, &buf, 2, 0);
    assert(n == 2);
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint16_t, buf);
    }
    return buf;
}

uint32_t ReadU32(Stream *s)
{
    uint32_t buf;
    int n = recv(s->fd, &buf, 4, 0);
    assert(n == 4);
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint32_t, buf);
    }
    return buf;
}

uint64_t ReadU64(Stream *s)
{
    uint64_t buf;
    int n = recv(s->fd, &buf, 8, 0);
    assert(n == 8);
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint64_t, buf);
    }
    return buf;
}

void WriteU8(Stream *s, uint8_t d)
{
    int n = send(s->fd, &d, 1, 0);
    assert(n == 1);
}

void WriteU16(Stream *s, uint16_t d)
{
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint16_t, d);
    }
    int n = send(s->fd, &d, 2, 0);
    assert(n == 2);
}

void WriteU32(Stream *s, uint32_t d)
{
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint32_t, d);
    }
    int n = send(s->fd, &d, 4, 0);
    assert(n == 4);
}

void WriteU64(Stream *s, uint64_t d)
{
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint64_t, d);
    }
    int n = recv(s->fd, &d, 8, 0);
    assert(n == 8);
}

int Write(Stream *s, char *buf, int n)
{
    int len = send(s->fd, buf, n, 0);
    assert(n >= 0);
    return len;
}

int WriteAll(Stream *s, char *buf, int n)
{
    int sent = 0;
    while (sent < n)
    {
        int len = send(s->fd, buf + sent, n - sent, 0);
        assert(len > 0);
        sent += len;
    }
    assert(sent == n);
    return sent;
}

int Read(Stream *s, char *buf, int n)
{
    int len = recv(s->fd, buf, n, 0);
    assert(n >= 0);
    return len;
}

int ReadAll(Stream *s, char *buf, int n)
{
    int sent = 0;
    while (sent < n)
    {
        int len = recv(s->fd, buf + sent, n - sent, 0);
        assert(len >= 0);
        if (len == 0)
            break;
        sent += len;
    }
    return sent;
}