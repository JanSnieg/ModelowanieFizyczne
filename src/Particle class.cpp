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
    setPosiotion(0, 0);
}

void Particle2D::updatePosition()
{
    Position position = getPosition();
    Velocity velocity = getVelocity();
    float x = position.x + (velocity.x * dt);
    float y = position.y + (velocity.y * dt);
    setPosiotion(x, y);
}

//Particle2D::Particle2D(Particle2D::Position position)
//{
//    setPosiotion(position.x, position.y);
//}
//
//Particle2D::Particle2D(Particle2D::Position, Particle2D::Velocity)
//{
//    setPosiotion(p, <#float y#>)
//}
//
