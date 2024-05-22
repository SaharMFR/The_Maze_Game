#include "../inc/maze.h"

//int worldMap[mapWidth][mapHeight] =
//{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
//};


/**
 * main - The main function to render mazes.
 * @param argc: The argument count.
 * @param argv: The argument vector (all arguments).
 * @return: 0 if successfully completed, 1 when failure happen.
 */
int main(int argc, char *argv[])
{
    double posX = 22, posY = 12;  //x and y start position
    double dirX = -1, dirY = 0;    //initial direction vector
    //the 2d raycaster version of camera plane
    double planeX = 0, planeY = 0.66;

    double time = 0;               //time of current frame
    double oldTime = 0;            //time of previous frame

    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(screenWidth, screenHeight,
                                0, &window, &renderer);
    SDL_SetWindowTitle(window, "Sahar's Maze Game");


    // Main loops flags
    int quit = 0, start = 0, mapWidth, mapHeight;
    char maze = '0';
    char *filename = (char *) malloc(20 * sizeof(char));
    int **worldMap;


    // Event handler
    SDL_Event e;

    // Starting loop
    quit = startPage(renderer, quit, e);

    maze = mazesPage(renderer, quit, e);

//    maze = '1';
    if (maze == '0')
    {
        quit = 1;
    }
    else
    {
        strcat(filename, "../mazes/maze");
        strcat(filename, &maze);
        strcat(filename, ".txt");

        worldMap = readMazeFile(filename, &mapHeight, &mapWidth);
    }


    int isMinimapVisible = 1;

    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                quit = 1;
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                if (mouseX >= screenWidth - 50 && mouseX <= screenWidth - 10 &&
                    mouseY >= screenHeight - 50 && mouseY <= screenHeight - 10)
                {
                    isMinimapVisible = !isMinimapVisible;
                }
            }
        }

        // Green color for earth
        SDL_SetRenderDrawColor(renderer, 0, 0x70, 0, 0xFF);
        SDL_RenderClear(renderer);

        // Render upper half with baby blue color
        SDL_Rect upperHalfRect = {0, 0, screenWidth, screenHeight / 2};
        // Baby blue color for sky
        SDL_SetRenderDrawColor(renderer, 0x40, 0xA2, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &upperHalfRect);

        // Render lower half with green color
        SDL_Rect lowerHalfRect = {0, screenHeight / 2, screenWidth,
                                  screenHeight / 2};
        // Green color for earth
        SDL_SetRenderDrawColor(renderer, 0x00, 0x99, 0x00, 0xFF);
        SDL_RenderFillRect(renderer, &lowerHalfRect);

        for (int x = 0; x < screenWidth; x++)
        {
            //calculate ray position and direction
            //x-coordinate in camera space
            double cameraX = 2 * x / (double)screenWidth - 1;
            double rayDirX = dirX + planeX * cameraX;
            double rayDirY = dirY + planeY * cameraX;

            //which box of the map we're in
            int mapX = (int)posX;
            int mapY = (int)posY;

            //length of ray from current position to next x or y-side
            double sideDistX;
            double sideDistY;

            //length of ray from one x or y-side to next x or y-side
            double deltaDistX = fabs(1 / rayDirX);
            double deltaDistY = fabs(1 / rayDirY);
            double perpWallDist;

            //what direction to step in x or y-direction (either +1 or -1)
            int stepX;
            int stepY;

            int hit = 0; //was there a wall hit?
            int side;    //was a NS or a EW wall hit?

            //calculate step and initial sideDist
            if (rayDirX < 0)
            {
                stepX = -1;
                sideDistX = (posX - mapX) * deltaDistX;
            }
            else
            {
                stepX = 1;
                sideDistX = (mapX + 1.0 - posX) * deltaDistX;
            }
            if (rayDirY < 0)
            {
                stepY = -1;
                sideDistY = (posY - mapY) * deltaDistY;
            }
            else
            {
                stepY = 1;
                sideDistY = (mapY + 1.0 - posY) * deltaDistY;
            }

            //perform DDA
            while (hit == 0)
            {
                //jump to next map square
                // either in x-direction, or in y-direction
                if (sideDistX < sideDistY)
                {
                    sideDistX += deltaDistX;
                    mapX += stepX;
                    side = 0;
                }
                else
                {
                    sideDistY += deltaDistY;
                    mapY += stepY;
                    side = 1;
                }
                //Check if ray has hit a wall
                if (worldMap[mapX][mapY] > 0)
                    hit = 1;
            }
            //Calculate distance projected on camera direction
            if (side == 0)
                perpWallDist = (sideDistX - deltaDistX);
            else
                perpWallDist = (sideDistY - deltaDistY);

            //Calculate height of line to draw on screen
            int lineHeight = (int)(screenHeight / perpWallDist);

            //calculate lowest and highest pixel to fill in current stripe
            int drawStart = -lineHeight / 2 + screenHeight / 2;
            if (drawStart < 0)
                drawStart = 0;
            int drawEnd = lineHeight / 2 + screenHeight / 2;
            if (drawEnd >= screenHeight)
                drawEnd = screenHeight - 1;

            //choose wall color
            SDL_Color color;
            switch (worldMap[mapX][mapY])
            {
                case 1:
                    color = (SDL_Color){80, 80, 80, 255}; // gray
                    break;
                case 2:
                    color = (SDL_Color){0, 0, 115, 255}; // blue
                    break;
                case 3:
                    color = (SDL_Color){200, 115, 200, 255}; // yellow
                    break;
                case 4:
                    color = (SDL_Color){115, 0, 0, 255}; // red
                    break;
                default:
                    color = (SDL_Color){115, 115, 115, 255}; // gray
                    break;
            }

            //give x and y sides different brightness
            if (side == 1)
            {
                color.r /= 1.2;
                color.g /= 1.2;
                color.b /= 1.2;
            }

            //draw the pixels of the stripe as a vertical line
            verLine(renderer, x, drawStart, drawEnd, color);
        }

        if (isMinimapVisible) {
            displayMinimap(renderer, worldMap, mapWidth, mapHeight, posX, posY,
                           dirX, dirY, planeX, planeY);
        }

        // Render toggle button
        drawButton(renderer, screenWidth - 50, screenHeight - 50, 40, 40,
                   (SDL_Color){255, 255, 255, 255});

        //Timing for input and FPS counter
        oldTime = time;
        time = SDL_GetTicks();
        //frameTime is the time this frame has taken, in seconds
        double frameTime = (time - oldTime) / 1000.0;

        SDL_RenderPresent(renderer);
//        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        //speed modifiers
        //the constant value is in squares/second
        double moveSpeed = frameTime * 4.0;
        //the constant value is in radians/second
        double rotSpeed = frameTime * 2.0;

        //move forward if no wall in front of you
        if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_UP] ||
            SDL_GetKeyboardState(NULL)[SDL_SCANCODE_W])
        {
            if (worldMap[(int)(posX + dirX * moveSpeed)][(int)posY] == 0)
                posX += dirX * moveSpeed;
            if (worldMap[(int)posX][(int)(posY + dirY * moveSpeed)] == 0)
                posY += dirY * moveSpeed;
        }
        //move backwards if no wall behind you
        if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_DOWN] ||
            SDL_GetKeyboardState(NULL)[SDL_SCANCODE_S])
        {
            if (worldMap[(int)(posX - dirX * moveSpeed)][(int)posY] == 0)
                posX -= dirX * moveSpeed;
            if (worldMap[(int)posX][(int)(posY - dirY * moveSpeed)] == 0)
                posY -= dirY * moveSpeed;
        }
        //rotate to the right
        if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT] ||
            SDL_GetKeyboardState(NULL)[SDL_SCANCODE_D])
        {
            double oldDirX = dirX;
            dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
            dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
            double oldPlaneX = planeX;
            planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
            planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
        }
        //rotate to the left
        if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT] ||
            SDL_GetKeyboardState(NULL)[SDL_SCANCODE_A])
        {
            double oldDirX = dirX;
            dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
            dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
            double oldPlaneX = planeX;
            planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
            planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
        }
    }

    freeMaze(worldMap, mapHeight);
    free(filename);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
