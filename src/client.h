
#pragma once

#include"sock.h"


typedef struct Client {
    int socket;
    struct sockaddr address;
} Client;

int ClientCreate(Client *client, char *hostname, char *port);

const char *ClientAddressToString(Client *client);