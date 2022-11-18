#include "raylib.h"

int main()
{
    // Window width and height
    const int windowWidth{1400};
    const int windowHeight{720};

    // initialize the window
    InitWindow(windowWidth, windowHeight, "Runner");


    //rect dimension 
    const int width{50};
    const int height{80};
    int posY{windowHeight - height};
    int velocity{-10};
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        // Start drawing 
        BeginDrawing();
        ClearBackground(WHITE);
        
        if(IsKeyPressed(KEY_SPACE))
        {
            posY += velocity;
        }

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);
        // Stop drawing 
        EndDrawing();
    }
    CloseWindow();
}