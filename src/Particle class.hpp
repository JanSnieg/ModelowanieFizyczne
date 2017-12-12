////
////  Particle class.hpp
////  newOFProject
////
////  Created by Jan Śnieg on 24/11/2017.
////
#pragma once

#ifndef Particle_class_hpp
#define Particle_class_hpp

#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "ofMain.h"

class Particle2D
{
    
private:
    
    //Structs that contains x and y axises
    struct Position
    {
        float x;
        float y;
    } particlePosition;
    
    struct Velocity
    {
        float x;
        float y;
    } particleVelocity;
    
    struct Force
    {
        float x;
        float y;
    } particleForce;
    
    struct Color
    {
        int r;
        int g;
        int b;
    } particleColor;
    
public:
    
    //Other variables
    bool isDead = false;
    bool wasDead = false;
    float dt = 0.01;
    int mass;
    float side;
    
    //Getters
    Position getPosition();
    Velocity getVelocity();
    Force getForce();
    Color getColor();
    
    //Setters
    void setVelocity(float, float);
    void setPosiotion(float, float);
    void setForce(float, float);
    void setColor(int r, int g, int b);
    
    //Physical methods
    void updatePosition();
    void updateVelocity();
    void updateForce();
    void updateColor();
    
    //Constructor(s)
    Particle2D();
//    Particle2D(Position);
//    Particle2D(Position, Velocity);
//    Particle2D(Position, Velocity, Force);
    
    //Usefull Ranom method
    int RandomMinMax (int min, int max);
    void drawParticle();
    void fadeOut();
    
};

#endif /* Particle_class_hpp */

//

