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
        std::vector <float> x;
        std::vector <float> y;
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
        int a;
    } particleColor;
    
public:
    
    //Other variables
    bool isDead = false;
    bool wasDead = false;
    float dt = 0.1;
    float mass;
    float side;
    int visible;
    
    //Getters
    Position getPosition();
    Velocity getVelocity();
    Force getForce();
    Color getColor();
    
    //Setters
    void setPosiotion(float, float, int);
    void setVelocity(float, float);
    void setForce(float, float);
    void setColor(int r, int g, int b, int a);
    
    //Physical methods
    void updatePosition();
    void updateVelocity();
    void updateForce();
    void updateColor();
    
    //Constructor(s)
    Particle2D();
    ~Particle2D();
    
    void preparePositionVector();
    
    //Usefull Ranom method
    int RandomMinMax (int min, int max);
    void drawParticle();
    void fadeOut();
    void smokeOn();
    
};

#endif /* Particle_class_hpp */

//

