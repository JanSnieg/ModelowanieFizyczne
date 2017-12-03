////
////  Particle class.cpp
////  newOFProject
////
////  Created by Jan Śnieg on 24/11/2017.
////

#include "Particle class.hpp"

Particle2D::Position Particle2D::getPosition()
{
    return particlePosition;
}

Particle2D::Velocity Particle2D::getVelocity()
{
    return particleVelocity;
}

Particle2D::Force Particle2D::getForce()
{
    return particleForce;
}

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

Particle2D::Particle2D()
{
    side = RandomMinMax(5, 20);
    //Random side size from 5 to 20
    mass = side * side;
    //Mass will be coralated with surface of cube
    lifeTime = RandomMinMax(10, 50);
    // TODO: change it to be more like fire
    setPosiotion(RandomMinMax(500, 600), 768 - side);
    //Random x position on bottom of scene
    setVelocity(0, RandomMinMax(5, 20));
    //Set velocity in Vertical axis
    setForce(RandomMinMax(5, 20), 0);
    //Set Force in Horizontal axis
}

void Particle2D::updatePosition()
{
    // TODO: Implement wave particle behavior
    float y = sin((particlePosition.y * M_PI)/180);
    
    float x = particlePosition.x + (particleVelocity.x * dt);
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
