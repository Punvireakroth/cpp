#include "raylib.h"

struct AnimData
{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float updateTime;
    float runningTime;
};


int main()
{
    // Window width and height

    int windowDimensions[2];
    windowDimensions[0] = 1400;
    windowDimensions[1] = 720;

   
    // initialize the window
    InitWindow(windowDimensions[0], windowDimensions[1], "Runner");

    // acceleration due to gravity (pixel/s)/s
    const int gravity{1500};
    // Load Obstacle 
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");

    const int sizeOfNebulea{6};
    AnimData nebulea[sizeOfNebulea]{};

    for(int i = 0; i < sizeOfNebulea; i++)
    {
        nebulea[i].rec.x = 0.0;
        nebulea[i].rec.y = 0.0;
        nebulea[i].rec.width = nebula.width/8;
        nebulea[i].rec.height = nebula.height/8;
        nebulea[i].pos.y = windowDimensions[1] - nebula.height/8;
        nebulea[i].frame = 0;
        nebulea[i].runningTime = 0.0;
        nebulea[i].updateTime = 0.0;
        // set position of nebula 
        nebulea[i].pos.x = windowDimensions[0] + i * 300;
    }
    

    // nebula X velocity (pixel per second )
    int nebVel{-300};

    // Load texture of Pain Naruto
    Texture2D scarfy = LoadTexture("textures/pain.png");
    AnimData scarfyData;

    // pain variables
    scarfyData.rec.width = scarfy.width/6;
    scarfyData.rec.height = scarfy.height;
    scarfyData.rec.x = 0;
    scarfyData.rec.y = 0;
    scarfyData.pos.x = windowDimensions[0]/2 - scarfyData.rec.width/2;
    scarfyData.pos.y  = windowDimensions[1] - scarfyData.rec.height;
    scarfyData.frame = 0;
    scarfyData.updateTime = 1.0/12.0;
    scarfyData.runningTime = 0.0;

   


    // jump velocity (pixels/second)
    bool isOnAir; 

    const int jumpVelocity = 700;    

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
        if(scarfyData.pos.y >= windowDimensions[1] - scarfyData.rec.height)
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
        for(int i = 0; i < sizeOfNebulea; i++){
            // update nebula's position
            nebulea[i].pos.x += nebVel * dT;
        }

        // update velocity
        scarfyData.pos.y += velocity * dT;

        // update running time
        scarfyData.runningTime += dT;
        if(scarfyData.runningTime >= scarfyData.updateTime){
            scarfyData.runningTime = 0.0;
             //update animation frame
            scarfyData.rec.x = scarfyData.frame * scarfyData.rec.width;
            scarfyData.frame++;
            if(scarfyData.frame > 5){
                scarfyData.frame = 0;
            }else if(isOnAir == true){
                // do not update run animation frame when sprite is on the air
                scarfyData.rec.x = scarfyData.rec.width;
            }
        }

        for(int i = 0; i < sizeOfNebulea; i++){
             //update animation frame of nebula
            nebulea[i].runningTime += dT;
            if(nebulea[i].runningTime >= nebulea[i].updateTime){
                nebulea[i].runningTime = 0.0;
                nebulea[i].rec.x = nebulea[i].frame * nebulea[i].rec.width;
                nebulea[i].frame++;
                    if(nebulea[i].frame > 7){
                        nebulea[i].frame = 0;
                    }
            }
        }

       
        for(int i = 0; i < sizeOfNebulea; i++){
            // draw obstacle
            DrawTextureRec(nebula, nebulea[i].rec, nebulea[i].pos, WHITE);
        }
       
        //draw texture pain naruto
        DrawTextureRec(scarfy, scarfyData.rec, scarfyData.pos, WHITE);
        // Stop drawing 
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
}