#pragma once

#include<assert.h>
#include<stdbool.h>

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include <fcntl.h>
#include<unistd.h>


int createSocket(char *address_, char *port, struct sockaddr *host, bool client);
