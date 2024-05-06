//
// Created by Sahar Mohamed on 04/03/2024.
//

#include "../inc/maze.h"

void verLine(SDL_Renderer *renderer, int x, int startY, int endY, SDL_Color color)
{
    for (int y = startY; y <= endY; y++)
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

void drawButton(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}
