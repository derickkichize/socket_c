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
 *
 * <struct> : socket_t
 *  @descriptor             // holds socket descriptor
 *  @ip                     // holds ip address
 *  @port                   // holds port number
 *  @set(){}                // config socket
 *  @_connect(){}           // connects using the socket
 *  @destroy(){}            // free socket of mem.
 */
typedef struct socket_t {
    int   descriptor;
    char  *buffer;
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
 * @args: < void >
 */
extern Socket_Object *Socket_ctor( void );

/**
 * Setup data for connection.
 * sets ip and port, and handle with pre defined data.
 * ---------------------------------------------------
 * @args: < void *obj , char *ip, int port>
 */
static void set ( void * obj, char *ip, int port );

/**
 * Connect to target.
 * gets data_packet to send to target.
 * -----------------------------------
 * @args: < void *obj>
 */
static void bind_ip ( void * obj );

/**
 * Method to send data to target..
 * ---------------------------------------------------
 * @args: < void *obj , char *buffer>
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
 * @args: < void *obj >
 */
static void disconnect ( void * obj);

#endif
