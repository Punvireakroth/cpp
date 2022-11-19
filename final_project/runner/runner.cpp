#include "raylib.h"

int main()
{
    // Window width and height
    const int windowWidth{1400};
    const int windowHeight{720};

    // initialize the window
    InitWindow(windowWidth, windowHeight, "Runner");

    // acceleration due to gravity (pixel/frame)/frame
    const int gravity{1};

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    Vector2 scarfyPos;
    

    bool isOnAir; 
    const int jumpVelocity = 20;

    //rect dimension 
    const int width{50};
    const int height{80};

    int posY{windowHeight - height};
    int velocity{0};
    SetTargetFPS(60);



    while (!WindowShouldClose())
    {
        // Start drawing 
        BeginDrawing();
        ClearBackground(WHITE);
        
        // check if sprite on the ground 
        if(posY >= windowHeight - height)
        {
            // ractangle is on the ground 
            velocity = 0;
            isOnAir = false;
        }else{
            // rectangle is in the air 
            // apply gravity
            velocity += gravity;
            isOnAir = true;
        }


        if(IsKeyPressed(KEY_SPACE))
        {
            if(isOnAir == false)
            {
                velocity -= jumpVelocity;
            }
        }

        
        posY += velocity;
        // Draw a rectangle
        DrawRectangle(windowWidth/2, posY, width, height, BLUE);
        // Stop drawing 
        EndDrawing();
    }
    CloseWindow();
}