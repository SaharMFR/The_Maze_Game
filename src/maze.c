//
// Created by Sahar Mohamed on 04/03/2024.
//

#include "../inc/maze.h"

/**
 * startPage - To display the starting page to the player.
 * @param renderer: The pointer to the renderer of SDL to display at.
 * @param quit: Flag to determine if the user has exited the game or not.
 * @param e: The event to handle exiting and mouse clicking.
 * @return: 1 if the user exited the game, 0 if he clicked `Play`.
 */
int startPage(SDL_Renderer *renderer, int quit, SDL_Event e)
{
    SDL_Texture *image = IMG_LoadTexture(renderer, "../assets/background.png");
    if (image == NULL)
    {
        printf("Failed to load image! SDL_Error: %s\n", SDL_GetError());
        exit(1);
    }

    int play = 0;

    // Button parameters
    int buttonX = screenWidth / 2 - 50;
    int buttonY = screenHeight - 80;
    int buttonWidth = 100;
    int buttonHeight = 50;

    while (!quit && !play)
    {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            // Handle mouse click
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                // Check if the mouse click is within the button area
                if (mouseX >= buttonX && mouseX <= buttonX + buttonWidth &&
                    mouseY >= buttonY && mouseY <= buttonY + buttonHeight) {
                    // Start button clicked
                    play = 1;
                }
            }
        }

        // Clear screen
        SDL_RenderClear(renderer);

        // Render background image
        SDL_RenderCopy(renderer, image, NULL, NULL);

        // Render start button
        drawButton(renderer, buttonX, buttonY, buttonWidth, buttonHeight,
                   (SDL_Color){0, 0, 0, 255});

        // Update screen
        SDL_RenderPresent(renderer);

    }
    // Free resources and close SDL
    SDL_DestroyTexture(image);
    return quit;
}

/**
 * mazesPage - To display the page of mazes to the player to chose one.
 * @param renderer: The pointer to the renderer of SDL to display at.
 * @param quit: Flag to determine if the user has exited the game or not.
 * @param e: The event to handle exiting and mouse clicking.
 * @return: 1 if the user exited the game, 0 if he chose one of the mazes.
 */
char mazesPage(SDL_Renderer *renderer, int quit, SDL_Event e)
{
    int start = 0;
    char maze = '0';

    // Button parameters
    int buttonWidth = 200;
    int buttonHeight = 100;
    int button1X = screenWidth / 4 - 50;
    int button2X = screenWidth - (screenWidth / 4) - buttonWidth + 50;
    int buttonY = (screenHeight / 2) - buttonHeight;

    while (!quit && !start)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            // User requests quit
            if (e.type == SDL_QUIT)
            {
                quit = 1;
            }
            // Handle mouse click
            else if (e.type == SDL_MOUSEBUTTONDOWN)
            {
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
                // Check if the mouse click is within the button area
                if (mouseX >= button1X && mouseX <= button1X + buttonWidth &&
                    mouseY >= buttonY && mouseY <= buttonY + buttonHeight)
                {
                    maze = '1';
                    start = 1;
                }
                else if (mouseX >= button2X && mouseX <= button2X +
                         buttonWidth && mouseY >= buttonY &&
                         mouseY <= buttonY + buttonHeight)
                {
                    maze = '2';
                    start = 1;
                }
            }
        }

        // Clear screen
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        // Render 2 buttons
        drawButton(renderer, button1X, buttonY, buttonWidth,
                   buttonHeight, (SDL_Color){255, 255, 255, 255});
        drawButton(renderer, button2X, buttonY, buttonWidth,
                   buttonHeight, (SDL_Color){255, 255, 255, 255});


        // Update screen
        SDL_RenderPresent(renderer);

//        // Load a font
//        TTF_Font *font = TTF_OpenFont("/Library/Fonts/Arial",
//                                      20); // Replace "path/to/your/font.ttf" with the path to your font file
//
//        // Render text onto a surface
//        SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Start", (SDL_Color) {255, 255, 255,
//                                                                                    255}); // Replace textColor with the color you want
//
//        // Create a texture from the surface
//        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
//
//        // Get the width and height of the text surface
//        int textWidth = textSurface->w;
//        int textHeight = textSurface->h;
//
//        // Free the surface since we don't need it anymore
//        SDL_FreeSurface(textSurface);
//
//        // Render the texture onto the renderer
//        SDL_Rect textRect = {buttonX + (buttonWidth - textWidth) / 2, buttonY + (buttonHeight - textHeight) / 2,
//                             textWidth, textHeight};
//        SDL_RenderCopy(renderer, textTexture, NULL, &textRect);
//
//        // Destroy the texture to free memory
//        SDL_DestroyTexture(textTexture);
//
//// Now, the "Start" text will be rendered on the button

    }

    return maze;
}

/**
 * verLine - Draws a vertical line on the screen.
 * @param renderer: The pointer to the renderer of SDL to display at.
 * @param x: The x (first) component of the start and end points of the line.
 * @param startY: The y (second) component of the start point of the line.
 * @param endY: The y (second) component of the end point of the line.
 * @param color: The color to display the line with.
 */
void verLine(SDL_Renderer *renderer, int x, int startY, int endY,
             SDL_Color color)
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
void drawButton(SDL_Renderer *renderer, int x, int y, int width, int height,
                SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {x, y, width, height};
    SDL_RenderFillRect(renderer, &rect);
}

/**
 * readMazeFile - To parse the map of the maze from text file.
 * @param filename: The path and name of the text file to parse the map from.
 * @param rows: The number of the rows of the file (map height).
 * @param cols: The number of the columns of the file (map width).
 * @return: The 2D dynamic allocated array which is the map of the maze.
 */
int **readMazeFile(const char *filename, int *rows, int *cols) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        return NULL;
    }

    // Determine the dimensions of the maze
    *rows = 0;
    *cols = 0;
    int ch;
    int currentRowLength = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            (*rows)++;
            if (currentRowLength > *cols) {
                *cols = currentRowLength;
            }
            currentRowLength = 0;
        } else {
            currentRowLength++;
        }
    }
    // Count the last row if file does not end with a newline
    if (currentRowLength > 0) {
        (*rows)++;
        if (currentRowLength > *cols) {
            *cols = currentRowLength;
        }
    }
    rewind(file);

    // Allocate memory for the maze
    int **maze = (int **)malloc(*rows * sizeof(int *));
    for (int i = 0; i < *rows; i++) {
        maze[i] = (int *)malloc(*cols * sizeof(int));
    }

    // Read the file content into the maze array
    int row = 0, col = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            row++;
            col = 0;
        } else if (ch >= '0' && ch <= '9') {
            maze[row][col++] = ch - '0';
        }
    }
    fclose(file);

    return maze;
}

/**
 * freeMaze - To free (deallocate) the 2D dynamically allocated array for
 *            the map of the maze to avoid memory leak.
 * @param maze: The 2D array to be freed.
 * @param rows: The number of rows of the 2D array.
 */
void freeMaze(int **maze, int rows) {
    for (int i = 0; i < rows; i++) {
        free(maze[i]);
    }
    free(maze);
}

/**
 * displayMinimap - To display a small map on the top left of the screen with
 *                  the position of the player on it and his direction (FoV).
 * @param renderer: The pointer to the renderer of the SDL to display at.
 * @param worldMap: The 2D dynamically allocated array of the real map read
 *                  from the file.
 * @param mapWidth: The width of the map (number of columns).
 * @param mapHeight: The height of the map (number of rows).
 * @param posX: The x-coordinate of the player's position.
 * @param posY: The y-coordinate of the player's position.
 * @param dirX: The first coordinate of the direction vector.
 * @param dirY: The second coordinate of the direction vector.
 * @param planeX: The camera plane (half the width of the perspective).
 * @param planeY: The camera plane (half the height of the perspective).
 */
void displayMinimap(SDL_Renderer *renderer, int **maze, int width, int height,
                    double posY, double posX, double dirY, double dirX,
                    double planeY, double planeX)
{
    int scale = 6;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            SDL_Rect cell;
            cell.x = j * scale;
            cell.y = i * scale;
            cell.w = scale;
            cell.h = scale;

            if (maze[i][j] > 0)      // White for walls
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
            else           // Black for empty spaces
                SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
            SDL_RenderFillRect(renderer, &cell);
        }
    }

    // Draw player position
    SDL_SetRenderDrawColor(renderer, 0x20, 0x20, 0xFF, 0xFF); //Blue for player
    SDL_Rect player;
    player.x = (int)(posX * scale - (scale / 2.0));
    player.y = (int)(posY * scale - (scale / 2.0));
    player.w = scale;
    player.h = scale;
    SDL_RenderFillRect(renderer, &player);

    // Draw FoV lines
    double fovLength = 8.0; // Length of FoV lines in minimap units
    // Red for FoV lines
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x0A, 0x0A, 0xFF);

    // Calculate endpoints of the FoV lines
    double leftFovX = posX + (dirX - planeX) * fovLength;
    double leftFovY = posY + (dirY - planeY) * fovLength;
    double rightFovX = posX + (dirX + planeX) * fovLength;
    double rightFovY = posY + (dirY + planeY) * fovLength;

    // Scale endpoints to minimap
    int scaledPosX = (int)(posX * scale);
    int scaledPosY = (int)(posY * scale);
    int scaledLeftFovX = (int)(leftFovX * scale);
    int scaledLeftFovY = (int)(leftFovY * scale);
    int scaledRightFovX = (int)(rightFovX * scale);
    int scaledRightFovY = (int)(rightFovY * scale);

    if (scaledLeftFovX > (width * scale))
        scaledLeftFovX = (width * scale);
    if (scaledLeftFovY > (height * scale))
        scaledLeftFovY = (height * scale);
    if (scaledRightFovX > (width * scale))
        scaledRightFovX = (width * scale);
    if (scaledRightFovY > (height * scale))
        scaledRightFovY = (height * scale);

    SDL_RenderDrawLine(renderer, scaledPosX, scaledPosY, scaledLeftFovX,
                       scaledLeftFovY);
    SDL_RenderDrawLine(renderer, scaledPosX, scaledPosY, scaledRightFovX,
                       scaledRightFovY);

}
