#include "socket.h"

/**
 * socket constructor.
 * preconfigure socket descritpor, and alloc some memory.
 * ------------------------------------------------------
 */
extern Socket_Object *Socket_ctor( void ) {
    Socket_Object *self = (Socket_Object*) malloc(sizeof(Socket_Object));

    self->descriptor = socket(AF_INET, SOCK_STREAM, 0);
    self->set = &set;
    self->bind_ip = &bind_ip;
    self->buff_send = &buff_send;
    self->buff_recv = &buff_recv;
    self->disconnect = &disconnect;

    return self;
}

/**
 * Setup data for connection.
 * set up ip and port, and handle with pre defined data.
 * ---------------------------------------------------
 */
static void set ( void * obj, char *ip, int port ) { 
    Socket_Object *self = (Socket_Object*) obj;

    self->ip = ip;
    self->port = port; 
    self->server.sin_addr.s_addr = inet_addr(self->ip);
    self->server.sin_family = AF_INET;
    self->server.sin_port = htons(self->port);
}

/**
 * Connect to target.
 * gets buffer to send to target.
 * ------------------------------
 */
static void bind_ip ( void * obj) {
    Socket_Object *self = (Socket_Object*) obj;
    
    if ( connect(self->descriptor, 
                (struct sockaddr *)&self->server, 
                sizeof(self->server)) < 0) {

        printf("Connection failed\n");
    }

    printf("Conected!\n");
}

/**
 * Method to send data to target.
 * ------------------------------
 */
static void buff_send(void * obj, char *buffer) {
    Socket_Object *self = (Socket_Object*) obj;

    if (send(self->descriptor, buffer, strlen(buffer),0) < 0) {
        printf("Cannot send buffer\n");
    }

    printf("send successfully\n");
}


/**
 * Method to call received data from target.
 * -----------------------------------------
 */
static char *buff_recv(void *obj) {
    Socket_Object *self = (Socket_Object*) obj;
    char *recv_buffer[12000];

    if (recv(self->descriptor, recv_buffer , 2000 , 0) < 0) {
        printf("cannot recv buffer\n");
    }

    printf("%s", &recv_buffer);
    return &recv_buffer;
}

/**
 * Destroy socket connection.
 * free memory and close connection.
 * ---------------------------------
 */
static void disconnect (void *obj) {
    Socket_Object *self = (Socket_Object*) obj;

    close(self->descriptor);
    free(self);
}

