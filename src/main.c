#include <stdio.h>
#include <time.h>

#if defined _WIN64 || defined _WIN32
    #include <winsock2.h>
    #include <windows.h>
    #include <ws2tcpip.h>
    #include <strings.h>
#else
    #include <string.h>
#endif

#include "log.h"
#include "util.h"

#include "SDLTread01.h"

int main(int argc, char* argv[]){
    struct timeval st, et;
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);

    getTick(&st);
    infoLog("Starting", "");
  
    SDLThread01();

    getTick(&et);
    infoLog("Completed. ETA %s", getETA(st, et));

    return 0;
}