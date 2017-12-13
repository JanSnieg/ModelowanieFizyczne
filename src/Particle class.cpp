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
void Particle2D::setPosiotion(float x, float y, int i)
{
    particlePosition.x[i] = x;
    particlePosition.y[i] = y;
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

void Particle2D::setColor(int r, int g, int b, int a)
{
    particleColor.r = r;
    particleColor.g = g;
    particleColor.b = b;
    particleColor.a = a;
}

//Constructor(s)
Particle2D::Particle2D()
{
    //Random side size from 5 to 20
    side = RandomMinMax(10, 14);
    
    //Mass will be coralated with surface of cube
    mass = (side * side)/200;
    
    //Setting fire color
    setColor(RandomMinMax(220, 255), RandomMinMax(200, 240), RandomMinMax(30, 40), 255);
    
    //Set initial velocity in Vertical axis
    setVelocity(0, RandomMinMax(-200, -190));
    
    //Set initial Force in Horizontal axis
    setForce(0, RandomMinMax(-70, -60));
    
    //Random x position on bottom of scene
    preparePositionVector();
    
    visible = RandomMinMax(100, 130);
}

Particle2D::~Particle2D()   {}

void Particle2D::preparePositionVector()
{
    //First position, initial position
    particlePosition.x.push_back(RandomMinMax(400, 600));
    particlePosition.y.push_back(ofGetHeight()-side);
    
    //Secound position
    particlePosition.x.push_back(particlePosition.x[0] + dt * dt * (particleForce.x/mass));
    particlePosition.y.push_back(particlePosition.y[0] + dt * dt * (particleForce.y/mass));
    
    //Third position, Verlet method
    particlePosition.x.push_back(2 * particlePosition.x[1] - particlePosition.x[0] + dt * dt * (particleForce.x/mass));
    particlePosition.y.push_back(2 * particlePosition.y[1] - particlePosition.y[0] + dt * dt * (particleForce.y/mass));
}

//Physical part
void Particle2D::updatePosition()
{
    float x = 2 * particlePosition.x[1] - particlePosition.x[0] + dt * dt * (particleForce.x/mass);
    float y = 2 * particlePosition.y[1] - particlePosition.y[0] + dt * dt * (particleForce.y/mass);
//    float x = particlePosition.x + (particleVelocity.x * dt);
//    float y = particlePosition.y - (particleVelocity.y *dt);
    setPosiotion(x, y, 2);
    setPosiotion(particlePosition.x[2], particlePosition.y[2],1);
    setPosiotion(particlePosition.x[1], particlePosition.y[1],0);
}

void Particle2D::updateVelocity()
{
//    float x = (particlePosition.x[2] - particlePosition.x[0]) / (2 * dt);
//
//    float y = (particlePosition.y[2] - particlePosition.y[0]) / (2 * dt);
    float x = particleVelocity.x + (particleForce.x * dt);
    float y = particleVelocity.y + (particleForce.y * dt);
    setVelocity(x, y);
}

void Particle2D::updateForce()
{
    //Curl noise
    // TODO: Implement a wind Force
    int scale = RandomMinMax(90, 100);
    int speed = RandomMinMax(90, 100);
    
    int x = RandomMinMax(-100, 100);
    int y = RandomMinMax(-100, 100);
    
    int dx = getPosition().x[1] - x;
    int dy = getPosition().y[1] - y;
    
    int factor = 1 / (1 + (dx*dx + dy*dy)/scale);
    
    int vortexVx = -dy * speed;
    int vortexVy = dx * speed;
    
    int vx = getVelocity().x;
    int vy = getVelocity().y;
    
    vx += (vortexVx - vx) * factor;
    vy += (vortexVy - vy) * factor;
    
    setVelocity(vx, vy);
}

void Particle2D::updateColor()
{
    if(getColor().g <= 0 || isDead)
        fadeOut();
    else
    {
        int g = getColor().g;
        int randomNumber = RandomMinMax(1, 3);
        g -= randomNumber;
        setColor(getColor().r, g, getColor().b, getColor().a);
    }
}

int Particle2D::RandomMinMax(int min, int max)
{
    return (std::rand() % (max - min)) + min;
}

void Particle2D::drawParticle()
{
    ofSetColor(getColor().r, getColor().g, getColor().b, getColor().a);
    ofDrawRectangle(getPosition().x[1], getPosition().y[1], side, side);
}

void Particle2D::fadeOut()
{
    int a = getColor().a;
    if (visible > 0 )
    {
        a -= 5;
        setColor(getColor().r, getColor().g, getColor().b, a);
        visible --;
    }
    else
    {
        isDead = true;
        smokeOn();
    }
}
void Particle2D::smokeOn()
{
    if (wasDead)
    {
        int randomNumber = RandomMinMax(10, 15);
        int r = getColor().r;
        int g = getColor().g;
        int b = getColor().b;
        int a = getColor().a;
        r += randomNumber;
        g += randomNumber;
        b += randomNumber;
        if (a < 255)
            a += 10;
        setColor(r, g, b, a);
        if (side > 0)
            side -= 0.1;
    }
    else if (isDead)
    {
        setColor(100, 100, 100, getColor().a);
        wasDead = true;
    }
}
