#include "raylib.h"
#include "particle.h" 

#include <iostream>
#include <algorithm>

int main(void)
{
    // Variables
    int arraySize = 800;
   
    const int screenWidth = 1200;
    const int screenHeight = 800;

    Particle particles[arraySize];    

    InitWindow(screenWidth, screenHeight, "Wind bruh");
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
        
    for(int i = 0; i <= arraySize - 1; i++) 
    {       
        particles[i] = Particle((float)screenWidth, (float)screenHeight,  2.5f);    // Making the particles             
    }
       

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {        
        BeginDrawing();

        ClearBackground(BLACK);

        for(int i = 0; i < arraySize - 1; i++) 
        {
            particles[i].Show();    // Drawing particles
        }  

        EndDrawing();

        for(int i = 0; i < arraySize - 1; i++) 
        {
            particles[i].Move();    // Moving particles
        }  
                       
    }
    
    CloseWindow();        // Close window and OpenGL context    
    return 0;
}