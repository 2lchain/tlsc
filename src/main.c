

//#include "client.h"
#include "listener.h"
#include "stream.h"


int main()
{
    Listener l = {};
    listenerInit(&l, "127.0.0.1", "3000");

    Listen(&l, 1);

    for(;;)
    {
        struct sockaddr new_addr = {};
        int sock = Accept(&l, &new_addr);
        
    }
    


    //printf("")
    /* code */
    return 0;
}

