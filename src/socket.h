#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

/**
 * Socket
 * -----------------------------------------------------
 * Makes socket connection alot easier.
 */
typedef struct socket_t {
    int   descriptor;
    char  *ip;
    int   port;
    void  (*set)(void *obj, char *ip, int port);
    void  (*buff_send)(void *obj, char *buffer);
    char  *(*buff_recv)(void *obj);
    void  (*bind_ip)(void *obj);
    void  (*disconnect)(void *obj);
    struct sockaddr_in server;
} Socket_Object;

/**
 * -----------------------------------------------------
 * socket constructor.
 * preconfigure socket descritpor, and alloc some memory.
 * ------------------------------------------------------
 */
extern Socket_Object *Socket_ctor( void );

/**
 * Setup data for connection.
 * sets ip and port, and handle with pre defined data.
 * ---------------------------------------------------
 */
static void set ( void * obj, char *ip, int port );

/**
 * Connect to target.
 * gets data_packet to send to target.
 * -----------------------------------
 */
static void bind_ip ( void * obj );

/**
 * Method to send data to target..
 * ---------------------------------------------------
 */
static void buff_send ( void * obj, char *buffer );

/**
 * Method to call received data from target.
 * ---------------------------------------------------
 * @args: < void *obj >
 */
static char *buff_recv ( void *obj );

/**
 * destroy socket connection.
 * free memory.
 * ---------------------------
 */
static void disconnect ( void * obj);

#endif
