//
// Created by Sahar Mohamed on 04/03/2024.
//

#ifndef THEMAZE_MAZE_H
#define THEMAZE_MAZE_H

#include <math.h>

#include <stdlib.h>
//#define MAP_WIDTH 10
//#define MAP_HEIGHT 10

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24


void verLine(SDL_Renderer *renderer, int x, int startY, int endY, SDL_Color color);
void drawButton(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color color);

#endif //THEMAZE_MAZE_H
