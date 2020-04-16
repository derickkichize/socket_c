#include <stdio.h>
#include <stdlib.h>
#include "./src/socket.h"

int main ( int argc, char *argv[] ) {
    Socket_Object *sock = Socket_ctor();
    
    sock->set(sock,"172.217.30.68",80);
    sock->bind_ip(sock);
    sock->buff_send(sock,"GET / HTTP/1.1\r\n\r\n");
    printf("%s",sock->buff_recv(sock));
    sock->disconnect(sock);

    return 0;
}
