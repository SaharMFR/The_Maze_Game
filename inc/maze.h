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
#include <SDL_ttf.h>
#include <stdio.h>

#define screenWidth 1024
#define screenHeight 700
//#define mapWidth 24
//#define mapHeight 24

int startPage(SDL_Renderer *renderer, int quit, SDL_Event e);
char mazesPage(SDL_Renderer *renderer, int quit, SDL_Event e);
void verLine(SDL_Renderer *renderer, int x, int startY, int endY,
             SDL_Color color);
void drawButton(SDL_Renderer *renderer, int x, int y, int width, int height,
                SDL_Color color);
int **readMazeFile(const char *filename, int *rows, int *cols);
void freeMaze(int **maze, int rows);
void displayMinimap(SDL_Renderer *renderer, int **maze, int width, int height,
                    double posY, double posX, double dirY, double dirX,
                    double planeY, double planeX);

#endif