#include "raylib.h"

int main()
{
    // Window width and height
    const int windowWidth{1400};
    const int windowHeight{720};

    // initialize the window
    InitWindow(windowWidth, windowHeight, "Runner");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Start drawing 
        BeginDrawing();
        ClearBackground(WHITE);

        // Stop drawing 
        EndDrawing();
    }
    CloseWindow();
}