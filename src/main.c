/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include "../inc/maze.h"


// Function to initialize maze map
//void initMap(int mazeMap[][MAP_HEIGHT]) {
//    // Example map: 1 represents a wall, 0 represents an empty space
//    int mapData[MAP_WIDTH][MAP_HEIGHT] = {
//            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//            {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
//            {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
//            {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
//            {1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
//            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//    };
//
//    // Copy map data to the mazeMap array
//    for (int i = 0; i < MAP_WIDTH; i++) {
//        for (int j = 0; j < MAP_HEIGHT; j++) {
//            mazeMap[i][j] = mapData[i][j];
//        }
//    }
//}
//
//int main(int argc, char* args[]) {
//    SDL_Instance instance;
//    double cameraX = 5.0; // Initial camera position (X-coordinate)
//    double cameraY = 5.0; // Initial camera position (Y-coordinate)
//    double cameraAngle = M_PI / 4; // Initial camera angle (45 degrees)
//
//    int mazeMap[MAP_WIDTH][MAP_HEIGHT];
//    initMap(mazeMap);
//
//    if (init_instance(&instance) != 0) {
//        return 1;
//    }
//
//    while (poll_events() != 1) {
//        // Change the camera angle (for testing purposes)
//        if (poll_events() == 2) {
//            printf("out Right\n");
//            cameraAngle += 0.01;
//        }
//        if (poll_events() == 3) {
//            printf("out Left\n");
//            cameraAngle -= 0.01;
//        }
//
//        // Draw walls using raycasting
//        drawWalls(&instance, cameraX, cameraY, cameraAngle, mazeMap);
//    }
//
//    // Destroy window
//    SDL_DestroyWindow(instance.window);
//
//    // Quit SDL subsystems
//    SDL_Quit();
//
//    return 0;
//}


//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[]) {
    double posX = 22, posY = 12;  //x and y start position
    double dirX = -1, dirY = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame



    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Get window surface
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    // Fill upper half with blue color
    SDL_Rect upperHalfRect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_FillRect(screenSurface, &upperHalfRect, SDL_MapRGB(screenSurface->format, 0x40, 0xA2, 0xFF));

    // Fill lower half with green color
    SDL_Rect lowerHalfRect = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
    SDL_FillRect(screenSurface, &lowerHalfRect, SDL_MapRGB(screenSurface->format, 0, 0x70, 0));

    // Update the surface
    SDL_UpdateWindowSurface(window);

    // Handle events
    while (!poll_events() && !done()) {
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            //calculate ray position and direction
            double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; //x-coordinate in camera space
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;


        }
    }

    // Destroy window
    SDL_DestroyWindow(window);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}


//int main(void) {
//    SDL_Instance  instance;
//
//    if (init_instance(&instance) != 0) {
//        return (1);
//    }
//
//    while ("C is awesome") {
//        SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
//        SDL_RenderClear(instance.renderer);
//        if (poll_events() == 1)
//            break;
//        SDL_SetRenderDrawColor(instance.renderer, 0xFF, 0xFF, 0xFF, 0xFF);
//        SDL_RenderDrawLine(instance.renderer, 200, 10, 100, 100);
//
//        SDL_RenderPresent(instance.renderer);
//    }
//
//    SDL_DestroyRenderer(instance.renderer);
//    SDL_DestroyWindow(instance.window);
//    SDL_Quit();
//
//    return (0);
//}


////Screen dimension constants
//const int SCREEN_WIDTH = 640;
//const int SCREEN_HEIGHT = 480;
//
//int main( int argc, char* args[] )
//{
//    //The window we'll be rendering to
//    SDL_Window* window = NULL;
//
//    SDL_Renderer *renderer;
//
////    //The surface contained by the window
////    SDL_Surface* screenSurface = NULL;
//
//    //Initialize SDL
//    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
//    {
//        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
//    }
//    else
//    {
//        //Create window
//        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, SDL_WINDOW_SHOWN );
//        if( window == NULL )
//        {
//            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
//        }
//        else
//        {
//            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//            if (renderer == NULL) {
//                printf( "SDL_CreateRenderer Error: %s\n", SDL_GetError());
//            }
//
////            //Get window surface
////            screenSurface = SDL_GetWindowSurface( window );
////
////            //Fill the surface white
////            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
////
////            //Update the surface
////            SDL_UpdateWindowSurface( window );
////
////            //Hack to get window to stay up
//            SDL_Event e; int quit = 0; while( quit == 0 ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = 1; } }
//        }
//    }
//
//    //Destroy window
//    SDL_DestroyWindow( window );
//
//    //Quit SDL subsystems
//    SDL_Quit();
//
//    return 0;
//}

