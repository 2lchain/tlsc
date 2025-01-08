

// #include "client.h"
#include "listener.h"
#include "stream.h"
#include "stuff.h"

typedef enum RecordType
{
    INVALID = 0,
    CHANGE_CIPHER_SPEC = 20,
    ALERT = 21,
    HANDSHAKE = 22,
    APPLICATION_DATA = 23
} RecordType;

#define LEGACY_RECORD_VERSION 0x0303

int main()
{
    Listener l = {};
    listenerInit(&l, "127.0.0.1", "3000");

    Listen(&l, 1);

    for (;;)
    {
        struct sockaddr new_addr = {};
        int sock = Accept(&l, &new_addr);
        printf("new connection.....\n");

        Stream stream = StreamInit(sock);

        uint8_t record_type = ReadU8(&stream);

        uint16_t legacy_record_version = ReadU16(&stream);

        printf("Legacy v: 0x%x\n", legacy_record_version);

        uint16_t length = ReadU16(&stream);

        printf("Record Length: %d\n", length);


        switch (record_type)
        {
        case HANDSHAKE:
            printf("Handshake record type\n");

            break;

        case CHANGE_CIPHER_SPEC:
            printf("change cipher spec record type\n");

            break;

        case ALERT:
            printf("alert record type\n");

            break;

        case APPLICATION_DATA:
            printf("application data record type\n");

            break;

        case INVALID:
            printf("invalid record type\n");

            break;

        default:
            printf("unknown record type\n");

            break;
        }

        Close(&stream);
    }

    // printf("")
    /* code */
    return 0;
}
