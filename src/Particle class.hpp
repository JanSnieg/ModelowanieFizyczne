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

class Particle2D
{
    
public:
    
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
    
    float dt = 0.01;
    
    Position getPosition();
    void setPosiotion(float, float);
    
    Velocity getVelocity();
    void setVelocity(float, float);
    
    Force getForce();
    void setForce(float, float);
    
    void updatePosition();
    void updateVelocity();
    void updateForce();
    
    Particle2D();
//    Particle2D(Position);
//    Particle2D(Position, Velocity);
//    Particle2D(Position, Velocity, Force);
    
};

#endif /* Particle_class_hpp */

//

