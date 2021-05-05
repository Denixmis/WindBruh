#include "raylib.h"

#ifndef PARTICLE_H
#define PARTICLE_H

class Particle
{
    public:
        void Move();        
        void Show();        
      
    float startX;
    float startY;

    float xMin = 5;
    float xMax = 45;

    float yRange = 4;        
    
    float xSpeed = GetRandomValue(xMin, xMax);
    float ySpeed = GetRandomValue(-yRange, yRange);

    float divider; // divides square sizes

    float colorValue = 255 * ((xSpeed - xMin + 1) / (xMax - xMin + 1));
    Color recColor = (Color){colorValue, colorValue, colorValue, 255};

    float recSize = xSpeed / divider;
    Rectangle rec = (Rectangle){startX, startY, recSize, recSize};

    Particle(float startX, float startY, float divider);  
    Particle();
};
#endif