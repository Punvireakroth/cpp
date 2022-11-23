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
    const int windowWidth{1400};
    const int windowHeight{720};

    // initialize the window
    InitWindow(windowWidth, windowHeight, "Runner");

    // acceleration due to gravity (pixel/s)/s
    const int gravity{1500};
    // Load Obstagcle 
    Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");

    // AnimData for nebula
    AnimData nebData{
        {0.0, 0.0, nebula.width/8.0, nebula.height/8.0},//x, y, width, height (Rec)
        {windowWidth, windowHeight - nebula.height/8}, // Vector2 x = width, y = height
        0, // frame
        1.0/2.0, // update time 
        0 //Running time
     };

    

    AnimData neb2Data{
        {0.0, 0.0, nebula.width/8.0, nebula.height/8.0}, // Rectangle x , y , width , height
        {windowWidth + 300, windowHeight - nebData.rec.height}, // Vector
        0,
        1.0/16.0,
        0.0
    };
    

    // nebula X velocity (pixel per second )
    int nebVel{-400};

    // Load texture of Pain Naruto
    Texture2D scarfy = LoadTexture("textures/pain.png");
    AnimData scarfyData;

    // pain variables
    scarfyData.rec.width = scarfy.width/6;
    scarfyData.rec.height = scarfy.height;
    scarfyData.rec.x = 0;
    scarfyData.rec.y = 0;
    scarfyData.pos.x = windowWidth/2 - scarfyData.rec.width/2;
    scarfyData.pos.y  = windowHeight - scarfyData.rec.height;
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
        if(scarfyData.pos.y >= windowHeight - scarfyData.rec.height)
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
        nebData.pos.x += nebVel * dT;

        // update velocity
        scarfyData.pos.y += velocity * dT;

        // update the second nebula position
        neb2Data.pos.x += nebVel * dT;

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

        //update animation frame of nebula
        nebData.runningTime += dT;
        if(nebData.runningTime >= nebData.updateTime){
            nebRunningTime = 0.0;
            nebData.rec.x = nebData.frame * nebData.rec.width;
            nebData.frame++;
            if(nebData.frame > 7){
                nebData.frame = 0;
            }
        }

        //update animation frame of nebula
        neb2Data.runningTime += dT;
        if(neb2Data.runningTime >= neb2Data.updateTime){
            neb2Data.runningTime = 0.0;
            neb2Data.rec.x = neb2Data.frame * neb2Data.rec.width;
            neb2Data.frame++;
            if(neb2Data.frame > 7){
                neb2Data.frame = 0;
            }
        }

        // draw nebula obstagcle
        DrawTextureRec(nebula, nebData.rec, nebData.pos, WHITE);
        // draw second nebula 
        DrawTextureRec(nebula, neb2Data.rec, neb2Data.pos, RED);
        //draw texture pain naruto
        DrawTextureRec(scarfy, scarfyData.rec, scarfyData.pos, WHITE);
        // Stop drawing 
        EndDrawing();
    }
    UnloadTexture(scarfy);
    UnloadTexture(nebula);
    CloseWindow();
}