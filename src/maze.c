//
// Created by Sahar Mohamed on 04/03/2024.
//

#include "../inc/maze.h"

/**
 * verLine - Draws a vertical line on the screen.
 * @param renderer: The pointer to the renderer of SDL to display at.
 * @param x: The x (first) component of the start and end points of the line.
 * @param startY: The y (second) component of the start point of the line.
 * @param endY: The y (second) component of the end point of the line.
 * @param color: The color to display the line with.
 */
void verLine(SDL_Renderer *renderer, int x, int startY, int endY, SDL_Color color)
{
    for (int y = startY; y <= endY; y++)
    {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderDrawPoint(renderer, x, y);
    }
}

/**
 * drawButton - Draws rectangular button with a specific color.
 * @param renderer: The pointer to the renderer of the SDL to display at.
 * @param x: The x (first) component of the first point (corner) of the
 *           rectangular button.
 * @param y: The y (second) component of the first point (corner) of the
 *           rectangular button.
 * @param width: The width of the button to know its area to be colored.
 * @param height: The height of the button to know its area to be colored.
 * @param color: The color to fill the button (rectangle) with.
 */
void drawButton(SDL_Renderer *renderer, int x, int y, int width, int height, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}
