#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>

void main() {
  const char get[] = "GET ";
  const char path[]= "/data/2.5/weather?q=Florianopolis&appid=";
  const char APIKey[] = ""; 
  const char http[] = " HTTP/1.1\r\n";
  const char host[] = "Host: ";
  const char hostname[] = "api.openweathermap.org";
  const char cr[] = "\r\n\r\n";
  const int maxsize = strlen(get) + strlen(path) + strlen(APIKey) + strlen(http) + strlen(host) + strlen(hostname) + strlen(cr) + 1;
  
  char *url = (char *) malloc(maxsize);
  url = strcpy(url, get);
  url = strcat(url, path);
  url = strcat(url, APIKey);
  url = strcat(url, http);
  url = strcat(url, host);
  url = strcat(url, hostname);
  url = strcat(url, cr);

  struct addrinfo *result;
  struct addrinfo hints;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(hostname, "http", &hints, &result);
  if (status != 0) {
    fprintf(stderr, "getaddrresult error: %s\n", gai_strerror(status));
    exit(EXIT_FAILURE);
  }
  
  int fd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (fd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  
  int connr = connect(fd, (struct sockaddr *) result->ai_addr, result->ai_addrlen);
  if (connr < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  int writer = write(fd, (const char *) url, strlen(url));
  if (writer < 0) {
    perror("write");
    exit(EXIT_FAILURE);
  }
  
  char *buffer = (char *) malloc(1024);
  int bytes = read(fd, buffer, 1024);
  if (bytes < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  buffer[bytes] = 0x00;
  puts(buffer);

  free(url);
  free(buffer);
  freeaddrinfo(result);
  close(fd);
  exit(EXIT_SUCCESS);
}
