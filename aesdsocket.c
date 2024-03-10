#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <syslog.h>
#include <arpa/inet.h>

#define PORT 9000
#define BACKLOG 5

static int stop_server = 0;

// Signal handler for SIGINT and SIGTERM
void signal_handler(int sig)
{
    syslog(LOG_INFO, "Caught signal, exiting");
    stop_server = 1;
    // You'll need to handle cleanup here
}

int main(int argc, char *argv[])
{
    int sockfd, new_sockfd;  // Listen on sock_fd, new connection on new_sockfd
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    socklen_t sin_size;

    // Set up signal handling for SIGINT and SIGTERM
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    // Open syslog for logging
    openlog("aesdsocket", LOG_PID, LOG_USER);

    // TODO: Create a socket, bind to port 9000, listen, and accept connections

    // TODO: Receive data from the client, write to file, and send file content back to client

    // Cleanup and close any open resources
    // TODO: Close sockets, free allocated memory, and delete the file /var/tmp/aesdsocketdata

    closelog(); // Close the syslog

    return 0;
}
