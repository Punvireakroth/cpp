#include "raylib.h"

struct AnimData
{
    Rectangle rec;
    Vector2 pos;
    int frame;
    float updateTime;
    float runningTime;
};

// function check if sprite is on the ground
bool isOnGround(AnimData data, int windowHeight){
    return data.pos.y >= windowHeight - data.rec.height;
}

// update pain animation frame
AnimData updateAnimData(AnimData data, float deltaTime, int maxFrame)
{
    // update running time
    data.runningTime += deltaTime;
    if (data.runningTime >= data.updateTime){
        data.runningTime = 0.0;
        // update animation 
        data.rec.x = data.frame * data.rec.width;
        data.frame++;
        if(data.frame > maxFrame){
            data.frame = 0;
        }
    }
    return data;
}
int main()
{
    // Window width and height

    int windowDimensions[2];
    windowDimensions[0] = 1000;
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
        nebulea[i].pos.x = windowDimensions[0] + i * 400;
    }
    
    // finish line variable 
    float finishLine{nebulea[sizeOfNebulea - 1].pos.x};
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

    // load background
    Texture2D background = LoadTexture("textures/far-buildings.png");
    float bgX{};
    Texture2D midground = LoadTexture("textures/back-buildings.png");
    float mgX{};
    Texture2D foreground = LoadTexture("textures/foreground.png");
    float fgX{};

    bool collision{};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Delta time (time since last frame)
        const float dT{GetFrameTime()};
        // Start drawing 
        BeginDrawing();
        ClearBackground(WHITE);
        
        // move background
        bgX -= 20 * dT;
        if (bgX <= -background.width*2){
            bgX = 0.0;
        }
        mgX -= 40 * dT;
        if(mgX <= -midground.width*2){
            mgX = 0.0;
        }
        fgX -= 80 * dT;
        if(fgX <= -foreground.width*2){
            fgX = 0.0;
        }
        // draw the background 
        Vector2 bg1Pos{bgX,0.0};
        DrawTextureEx(background, bg1Pos, 0.0, 4.0, WHITE);
        Vector2 bg2Pos{bgX + background.width*4.0, 0.0};
        DrawTextureEx(background, bg2Pos, 0.0, 4.0, WHITE);

        Vector2 mg1Pos{mgX,0.0};
        DrawTextureEx(midground, mg1Pos, 0.0, 4.0, WHITE);
        Vector2 mg2Pos{mgX + background.width*4.0, 0.0};
        DrawTextureEx(midground, mg2Pos, 0.0, 4.0, WHITE);

        Vector2 fg1Pos{fgX,0.0};
        DrawTextureEx(foreground, fg1Pos, 0.0, 4.0, WHITE);
        Vector2 fg2Pos{fgX + background.width*4.0, 0.0};
        DrawTextureEx(foreground, fg2Pos, 0.0, 4.0, WHITE);
        // check if sprite on the ground 
        if(isOnGround(scarfyData, windowDimensions[1]))
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
        // update finish line
        finishLine += nebVel * dT;
        // update velocity
        scarfyData.pos.y += velocity * dT;

        // update pain animation
       if(!isOnAir)
       {
        scarfyData = updateAnimData(scarfyData, dT, 5);
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

        for (AnimData nebula : nebulea)
        {
            float pad{20};
            Rectangle nebRec{
                nebula.pos.x + pad,
                nebula.pos.y + pad,
                nebula.rec.width - 2 * pad,
                nebula.rec.height - 2 * pad
            };
            Rectangle scarfyRec {
                scarfyData.pos.x,
                scarfyData.pos.y,
                scarfyData.rec.width,
                scarfyData.rec.height
            };

            if(CheckCollisionRecs(nebRec, scarfyRec)){
                collision = true;
            }
        }

        if(collision){
            // hit obstacle lose the game
        }else{
            for(int i = 0; i < sizeOfNebulea; i++){
            // draw obstacle
            DrawTextureRec(nebula, nebulea[i].rec, nebulea[i].pos, WHITE);
            }
       
            //draw texture pain naruto
            DrawTextureRec(scarfy, scarfyData.rec, scarfyData.pos, WHITE);
        }
        
        // Stop drawing 
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    UnloadTexture(background);
    UnloadTexture(midground);
    UnloadTexture(foreground);
    CloseWindow();
}