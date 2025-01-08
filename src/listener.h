#pragma once

#include "sock.h"

typedef struct Listener{
    int socket;
    struct sockaddr address;
}Listener;

int listenerInit(Listener *listener, char *host, char *port);

const char *listenerAddressToString(Listener *l);

void Listen(Listener *l, int qsize);

int Accept(Listener *l, struct sockaddr *addr);
