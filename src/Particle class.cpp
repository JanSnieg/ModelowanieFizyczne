////
////  Particle class.cpp
////  newOFProject
////
////  Created by Jan Śnieg on 24/11/2017.
////

#include "Particle class.hpp"

//Getters
Particle2D::Position Particle2D::getPosition()  {return particlePosition;}
Particle2D::Velocity Particle2D::getVelocity()  {return particleVelocity;}
Particle2D::Force Particle2D::getForce()        {return particleForce;}

//Setters
void Particle2D::setPosiotion(float x, float y)
{
    particlePosition.x = x;
    particlePosition.y = y;
}

void Particle2D::setVelocity(float x, float y)
{
    particleVelocity.x = x;
    particleVelocity.y = y;
}

void Particle2D::setForce(float x, float y)
{
    particleForce.x = x;
    particleForce.y = y;
}

//Constructor(s)
Particle2D::Particle2D()
{
    //Random side size from 5 to 20
    side = RandomMinMax(5, 20);
    
    //Mass will be coralated with surface of cube
    mass = side * side;
    
    // TODO: change it to be more like fire
    lifeTime = RandomMinMax(10, 50);
    
    //Random x position on bottom of scene
    setPosiotion(RandomMinMax(500, 600), 768 - side);
    
    //Set initial velocity in Vertical axis
    setVelocity(0, RandomMinMax(5, 20));
    
    //Set initial Force in Horizontal axis
    setForce(RandomMinMax(5, 20), 0);
}

//Physical part
void Particle2D::updatePosition()
{
    float x = particlePosition.x + (particleVelocity.x * dt);
    
    // TODO: Implement wave particle behavior
    float y = sin((particlePosition.y * M_PI)/180);
    y *= particleVelocity.y + (particleVelocity.y * dt);
    setPosiotion(x, y);
}

void Particle2D::updateVelocity()
{
    float x = particleForce.x * dt;
    float y = particleForce.y * dt;
    setForce(x, y);
}

void Particle2D::updateForce()
{
    // TODO: Implement a wind Force
}

int Particle2D::RandomMinMax(int min, int max)
{
    srand(time(NULL));
    return (std::rand() % (max - min)) + min;
}
