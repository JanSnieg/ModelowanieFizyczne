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
Particle2D::Color Particle2D::getColor()        {return particleColor;}

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

void Particle2D::setColor(int r, int g, int b)
{
    particleColor.r = r;
    particleColor.g = g;
    particleColor.b = b;
}

//Constructor(s)
Particle2D::Particle2D()
{
    //Random side size from 5 to 20
    side = RandomMinMax(8, 18);
    
    //Mass will be coralated with surface of cube
    mass = side * side;
    
    //Setting fire color
    setColor(RandomMinMax(220, 255), RandomMinMax(200, 240), RandomMinMax(30, 40));
    
    //Random x position on bottom of scene
    setPosiotion(RandomMinMax(400, 500), 768 - side);
    
    //Set initial velocity in Vertical axis
    setVelocity(0, RandomMinMax(100, 200));
    
    //Set initial Force in Horizontal axis
    setForce(RandomMinMax(1, 5), 0);
}

//Physical part
void Particle2D::updatePosition()
{
    float x = particlePosition.x + (particleVelocity.x * dt);
    
    // TODO: Implement wave particle behavior
//    float y = sin((particlePosition.y * M_PI)/180);
//    y *= particleVelocity.y + (particleVelocity.y * dt);
    float y = particlePosition.y - (particleVelocity.y *dt);
    setPosiotion(x, y);
}

void Particle2D::updateVelocity()
{
    float x = particleForce.x * dt;
    float y = particleForce.y * dt;
    setVelocity(x, y);
}

void Particle2D::updateForce()
{
    // TODO: Implement a wind Force
}

void Particle2D::updateColor()
{
    if(getColor().g <= 0 || isDead)
    {
        isDead = true;
        fadeOut();
    }
    else
    {
        side -= 0.02;
        int g = getColor().g;
        g -= 2;
        setColor(getColor().r, g, getColor().b);
    }
}

int Particle2D::RandomMinMax(int min, int max)
{
    return (std::rand() % (max - min)) + min;
}

void Particle2D::drawParticle()
{
    ofSetColor(getColor().r, getColor().g, getColor().b);
    ofDrawRectangle(getPosition().x, getPosition().y, side, side);
}

void Particle2D::fadeOut()
{
    if (wasDead)
    {
        int r = getColor().r;
        int g = getColor().g;
        int b = getColor().b;
        r += 3;
        g += 3;
        b += 3;
        setColor(r, g, b);
        if (side > 0)
            side -= 0.1;
    }
    else if (isDead)
    {
        setColor(120, 120, 120);
//        side = 10;
        wasDead = true;
    }
    
}
