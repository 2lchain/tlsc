#include "listener.h"

int listenerInit(Listener *listener, char *host, char *port){
    assert(listener!=NULL);
    assert(host != NULL);
    assert(port != NULL);
    listener->socket = createSocket(host, port, &listener->address, false);
    if(listener->socket < 0) {
        return listener->socket;
    }
    return 0;
}

const char *listenerAddressToString(Listener *l) {
    assert(l != NULL);
    static char ip_str[INET_ADDRSTRLEN];
    return inet_ntop(AF_INET, &l->address, ip_str, INET_ADDRSTRLEN);
}

void Listen(Listener *l, int qsize) {
    int res = listen(l->socket, qsize);
    if(res!= 0) {
        perror("listen: ");
    }
    assert(res == 0);
}

int Accept(Listener *l, struct sockaddr *addr) {
    socklen_t len = sizeof(struct sockaddr);
    int res = accept(l->socket, addr, &len);
    if(res < 0) {
        perror("accept: ");
    }
    assert(res >= 0);
    return res;
}

