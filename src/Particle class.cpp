////
////  Particle class.cpp
////  newOFProject
////
////  Created by Jan Śnieg on 24/11/2017.
////

#include "Particle class.hpp"

Particle2D::Position Particle2D::getPosition()
{
    Position position;
    return position;
}

Particle2D::Velocity Particle2D::getVelocity()
{
    Velocity velocity;
    return velocity;
}

Particle2D::Force Particle2D::getForce()
{
    Force force;
    return force;
}

void Particle2D::setPosiotion(float x, float y)
{
    Position position;
    position.x = x;
    position.y = y;
}

void Particle2D::setVelocity(float x, float y)
{
    Velocity velocity;
    velocity.x = x;
    velocity.y = y;
}

void Particle2D::setForce(float x, float y)
{
    Force force;
    force.x = x;
    force.y = y;
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
