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
private:
    
    struct Posicion
    {
        float x;
        float y;
    };
    
    struct Velocity
    {
        float x;
        float y;
    };
    
    struct Force
    {
        float x;
        float y;
    };
    
public:
    
    Posicion getPosition();
    Posicion setPosiotion();
    
    Velocity getVelocity();
    Velocity setVelocity();
    
    Force getForce();
    Force setForce();
    
};

#endif /* Particle_class_hpp */

//

