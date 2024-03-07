//
// Created by Sahar Mohamed on 04/03/2024.
//

#include "../inc/maze.h"


int init_instance(SDL_Instance *instance) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
        return (1);
    }

    instance->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
    if (instance->window == NULL) {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }

    instance->renderer = SDL_CreateRenderer(instance->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (instance->renderer == NULL) {
        SDL_DestroyWindow(instance->window);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return (1);
    }

    return (0);
}



int poll_events() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                return (1);
            case SDL_KEYDOWN:
//                printf("Keyboard %d: scancode 0x%08X = %s, keycode 0x%08X = %s\n",
//                        event.key.type, event.key.keysym.scancode,
//                        SDL_GetScancodeName(event.key.keysym.scancode),
//                        event.key.keysym.sym, SDL_GetKeyName(event.key.keysym.sym));
                if (event.key.keysym.scancode == 0x29)
                    return (1);
//                if (event.key.keysym.scancode == 0x0000004F) {
//                    printf("in right\n");
//                    return (2);
//                }
//                if (event.key.keysym.scancode == 0x00000050) {
//                    printf("in left\n");
//                    return (3);
//                }
                break;
        }
    }

    return (0);
}


int done() {
    return (0);
}


//void drawWalls(SDL_Instance* instance, double cameraX, double cameraY, double cameraAngle, int mazeMap[][MAP_HEIGHT]) {
//    // Clear the renderer
//    SDL_SetRenderDrawColor(instance->renderer, 0, 0, 0, 255);
//    SDL_RenderClear(instance->renderer);
//
//    // Raycasting parameters
//    double rayDirX, rayDirY;
//    int mapX, mapY;
//
//    // Loop through each column of the screen
//    for (int x = 0; x < SCREEN_WIDTH; x++) {
//        // Calculate ray direction and initial position
//        rayDirX = cos(cameraAngle) + sin(cameraAngle) * (2 * x / (double)SCREEN_WIDTH - 1);
//        rayDirY = sin(cameraAngle) - cos(cameraAngle) * (2 * x / (double)SCREEN_WIDTH - 1);
//
//        mapX = (int)cameraX;
//        mapY = (int)cameraY;
//
//        double sideDistX, sideDistY;
//        double deltaDistX = fabs(1 / rayDirX);
//        double deltaDistY = fabs(1 / rayDirY);
//        double perpWallDist;
//
//        int stepX, stepY;
//
//        if (rayDirX < 0) {
//            stepX = -1;
//            sideDistX = (cameraX - mapX) * deltaDistX;
//        } else {
//            stepX = 1;
//            sideDistX = (mapX + 1.0 - cameraX) * deltaDistX;
//        }
//
//        if (rayDirY < 0) {
//            stepY = -1;
//            sideDistY = (cameraY - mapY) * deltaDistY;
//        } else {
//            stepY = 1;
//            sideDistY = (mapY + 1.0 - cameraY) * deltaDistY;
//        }
//
//        // Perform DDA (Digital Differential Analyzer) algorithm
//        while (mazeMap[mapX][mapY] == 0) {
//            if (sideDistX < sideDistY) {
//                sideDistX += deltaDistX;
//                mapX += stepX;
//            } else {
//                sideDistY += deltaDistY;
//                mapY += stepY;
//            }
//        }
//
//        // Calculate the perpendicular distance to the wall
//        if (sideDistX < sideDistY) {
//            perpWallDist = sideDistX;
//        } else {
//            perpWallDist = sideDistY;
//        }
//
//        // Calculate height of the line to draw on the screen
//        int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);
//
//        // Calculate starting and ending points of the line
//        int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
//        if (drawStart < 0) {
//            drawStart = 0;
//        }
//
//        int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
//        if (drawEnd >= SCREEN_HEIGHT) {
//            drawEnd = SCREEN_HEIGHT - 1;
//        }
//
//        // Draw the wall column
//        SDL_SetRenderDrawColor(instance->renderer, 255, 255, 255, 255); // White color for walls
//        SDL_RenderDrawLine(instance->renderer, x, drawStart, x, drawEnd);
//    }
//
//    // Update the renderer
//    SDL_RenderPresent(instance->renderer);
//}