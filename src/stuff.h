#pragma once

#include <stdint.h>
#include <stdbool.h>


static inline bool IsLittleEndian() {
    uint16_t a= 1;
    if(((uint8_t *)&a)[0] == 1) {
        return true;
    }
    return false;
}

#define ENDIANSWAP(T, value)\
        uint8_t *__swapbuf__ = (uint8_t *)(&value);\
        int __half__ = sizeof(T) / 2;\
        for (int __i__ = 0; __i__ < __half__; __i__++)\
        {\
            uint8_t __a__ = __swapbuf__[__i__];\
            __swapbuf__[__i__] = __swapbuf__[sizeof(T) - __i__ - 1];\
            __swapbuf__[sizeof(T) - __i__ - 1] = __a__;\
        }
