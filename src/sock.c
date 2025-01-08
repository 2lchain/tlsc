#include "sock.h"

int createSocket(char *address_, char *port, struct sockaddr *host, bool client)
{
  int status, sock;
  struct addrinfo hints;
  struct addrinfo *res, *p;

  memset(&hints, 0, sizeof hints);

  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_CANONNAME | AF_INET;

  status = getaddrinfo(address_, port, &hints, &res);

  if (status != 0)
  {
    fprintf(stderr, "%s\n", gai_strerror(status));
    return -1;
  }

  for (p = res; p; p = p->ai_next)
  {
    sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

    if (sock < 0)
      continue;

    if (client)
    {

      if (!connect(sock, p->ai_addr, p->ai_addrlen))
      {
        memcpy(host, p->ai_addr, p->ai_addrlen);
        break;
      }
      perror("connect");
      return-1;
    }
    else
    {
      if (!bind(sock, p->ai_addr, p->ai_addrlen))
      {
        memcpy(host, p->ai_addr, p->ai_addrlen);
        break;
      }
      perror("bind");
      return -1;
    }
  }

  if (p == NULL)
  {
    return -1;
  }

  freeaddrinfo(res);
  return sock;
}
