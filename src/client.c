
#include"client.h"


int ClientCreate(Client *client, char *hostname, char *port) {
    assert(client != NULL);
    assert(hostname != NULL);
    assert(port != NULL);
    client->socket = createSocket("google.com", "80", &client->address, true);
    if(client->socket < 0) {
        return client->socket;
    }
    return 0;
}

const char *ClientAddressToString(Client *client) {
    assert(client != NULL);
    static char ip_str[INET_ADDRSTRLEN];
    return inet_ntop(AF_INET, &client->address, ip_str, INET_ADDRSTRLEN);
}