#include "raylib.h"



int main()
{
    // Window width and height
    const int windowWidth{1400};
    const int windowHeight{720};

    // initialize the window
    InitWindow(windowWidth, windowHeight, "Runner");

    // acceleration due to gravity (pixel/s)/s
    const int gravity{1500};
    // Load Obstagcle 
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
    Rectangle nebRec{0.0, 0.0, nebula.width/8.0, nebula.height/8.0}; //x, y, width, height 
    Vector2 nebPos{windowWidth, windowHeight - nebRec.height}; //x = width, y = height

    Rectangle neb2Rec{0.0, 0.0, nebula.width/8.0, nebula.height/8.0};
    Vector2 neb2Pos{windowWidth + 300, windowHeight - nebRec.height};

    int neb2Frame{};
    const float neb2UpdateTime{1.0/16.0};
    float neb2RunningTime;

    // nebula X velocity (pixel per second )
    int nebVel{-400};

    // Load texture of Pain Naruto
    Texture2D scarfy = LoadTexture("textures/pain.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = (windowWidth / 2) - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;

    // animation frame 
    int frame{};

    bool isOnAir; 
    // jump velocity (pixels/second)
    const int jumpVelocity = 700;

    // time between next animation
    const float updateTime = 1.0/12.0;
    float runningTime{};
    //nebula animation variable
    int nebFrame{};
    const float nebUpdateTime{1.0/12.0};
    float nebRunningTime{};

    int velocity{0};
    SetTargetFPS(60);



    while (!WindowShouldClose())
    {
        // Delta time (time since last frame)
        const float dT{GetFrameTime()};
        // Start drawing 
        BeginDrawing();
        ClearBackground(WHITE);
        
        // check if sprite on the ground 
        if(scarfyPos.y >= windowHeight - scarfyRec.height)
        {
            // ractangle is on the ground 
            velocity = 0;
            isOnAir = false;
        }else{
            // rectangle is in the air 
            // apply gravity
            velocity += gravity * dT;
            isOnAir = true;
        }


        if(IsKeyPressed(KEY_SPACE))
        {
            if(isOnAir == false)
            {
                velocity -= jumpVelocity;
            }
        }
        // update nebula position
        nebPos.x += nebVel * dT;

        // update velocity
        scarfyPos.y += velocity * dT;

        // update the second nebula position
        neb2Pos.x += nebVel * dT;

        // update running time
        runningTime += dT;
        if(runningTime >= updateTime){
            runningTime = 0.0;
             //update animation frame
            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if(frame > 5){
                frame = 0;
            }else if(isOnAir == true){
                // do not update run animation frame when sprite is on the air
                scarfyRec.x = scarfyRec.width;
            }
        }

        //update animation frame of nebula
        nebRunningTime += dT;
        if(nebRunningTime >= nebUpdateTime){
            nebRunningTime = 0.0;
            nebRec.x = nebFrame * nebRec.width;
            nebFrame++;
            if(nebFrame > 7){
                nebFrame = 0;
            }
        }

        //update animation frame of nebula
        neb2RunningTime += dT;
        if(neb2RunningTime >= neb2UpdateTime){
            neb2RunningTime = 0.0;
            neb2Rec.x = neb2Frame * neb2Rec.width;
            neb2Frame++;
            if(neb2Frame > 7){
                neb2Frame = 0;
            }
        }

        // draw nebula obstagcle
        DrawTextureRec(nebula, nebRec, nebPos, WHITE);
        // draw second nebula 
        DrawTextureRec(nebula, neb2Rec, neb2Pos, RED);
        //draw texture pain naruto
        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);
        // Stop drawing 
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
}