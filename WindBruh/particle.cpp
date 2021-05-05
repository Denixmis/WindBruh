#include "raylib.h"
#include "particle.h"
#include "math.h"


Particle::Particle(){}
Particle::Particle(float startX, float startY, float divider)
{
    this->startX = startX;
    this->startY = GetRandomValue(0, startY);
   
    this->divider = divider;            
}

void Particle::Move()
{
    rec.x -= xSpeed;
    rec.y -= ySpeed;

    if(rec.x < 0)   // Checks if the particle is out of bounds
    {
        rec.x = startX;
        rec.y = (float)GetRandomValue(0, startY * 10);

        xSpeed = GetRandomValue(xMin, xMax);
        ySpeed = GetRandomValue(-yRange, yRange);

        rec.width = xSpeed / divider;
        rec.height = xSpeed / divider;

        colorValue = 255 * ((xSpeed - xMin + 1) / (xMax - xMin + 1));
        if(colorValue > 255)
        {
            colorValue = 255;
        }
        recColor = (Color){colorValue, colorValue, colorValue, 255};             
    }           
}

void Particle::Show()
{    
    DrawRectangleRec(rec, recColor);        
}



    
