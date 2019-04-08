#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_thread.h>

#if defined _WIN64 || defined _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "util.h"
#include "log.h"
#include "SDLTread01.h"

//The thread that will be used
SDL_Thread *thread = NULL;
//Quit flag
bool quit = false;

void SDLThread01(){
    struct timeval st, et;

    getTick(&st);
    infoLog("Starting");
  
    //Create and run the thread
    thread = SDL_CreateThread( TH01, "TestThread", NULL );

    uint16_t deelay_ = 300;
    uint16_t count = 0;
    while(count<10){
        infoLog("Main loop %d iterations", count);

        #if defined _WIN64 || defined _WIN32
            Sleep(deelay_);
        #else
            sleep(deelay_);
        #endif

        count++;
    }

    getTick(&et);
    infoLog("Completed. ETA %s", getETA(st, et));
}


int TH01( void *data )
{
    //While the program is not over
    uint16_t count = 0;
    while( quit == false )
    {
        infoLog("Thread Execution [%d]", count);
        count++;
        SDL_Delay( 250 );
    }
    
    return 0;    
}