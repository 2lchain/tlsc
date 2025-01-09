#include"wr.h"
#include "stuff.h"
#include <assert.h>
RW RWInit(void*closure, read_fn r, write_fn w){
    return(RW){
        .read = r,
        .write = w,
        .closure = closure
    };
}

uint8_t ReadU8(RW *s)
{
    uint8_t buf;
    int n = s->read(s->closure, &buf, 1);
    assert(n == 1);
    return buf;
}

uint16_t ReadU16(RW *s)
{
    uint16_t buf;
    int n = s->read(s->closure, &buf, 2);
    assert(n == 2);
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint16_t, buf);
    }
    return buf;
}

uint32_t ReadU32(RW *s)
{
    uint32_t buf;
    int n = s->read(s->closure, &buf, 4);
    assert(n == 4);
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint32_t, buf);
    }
    return buf;
}

uint64_t ReadU64(RW *s)
{
    uint64_t buf;
    int n = s->read(s->closure, &buf, 8);
    assert(n == 8);
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint64_t, buf);
    }
    return buf;
}

void WriteU8(RW *s, uint8_t d)
{
    int n = s->write(s->closure, &d, 1);
    assert(n == 1);
}

void WriteU16(RW *s, uint16_t d)
{
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint16_t, d);
    }
    int n = s->write(s->closure, &d, 2);
    assert(n == 2);
}

void WriteU32(RW *s, uint32_t d)
{
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint32_t, d);
    }
    int n = s->write(s->closure, &d, 4);
    assert(n == 4);
}

void WriteU64(RW *s, uint64_t d)
{
    if (IsLittleEndian())
    {
        ENDIANSWAP(uint64_t, d);
    }
    int n = s->write(s->closure, &d, 8);
    assert(n == 8);
}



int WriteAll(RW *s, char *buf, int n)
{
    int sent = 0;
    while (sent < n)
    {
        int len = s->write(s->closure, buf + sent, n - sent);
        assert(len > 0);
        sent += len;
    }
    assert(sent == n);
    return sent;
}



int ReadAll(RW *s, char *buf, int n)
{
    int sent = 0;
    while (sent < n)
    {
        int len = s->read(s->closure, buf + sent, n - sent);
        assert(len >= 0);
        if (len == 0)
            break;
        sent += len;
    }
    return sent;
}


int Read(RW *s, char *buf, int n)
{
    int len = s->read(s->closure, buf, n);
    assert(n >= 0);
    return len;
}

int Write(RW *s, char *buf, int n)
{
    int len = s->write(s->closure, buf, n);
    assert(n >= 0);
    return len;
}