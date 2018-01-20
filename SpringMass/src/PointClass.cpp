//
//  PointClass.cpp
//  SpringMass
//
//  Created by Jan Śnieg on 10/01/2018.
//

#include "PointClass.hpp"

PointClass::position PointClass::getPosition() {return pointPosiotion;}
PointClass::velocity PointClass::getVelocity() {return pointVelocity;}
PointClass::force PointClass::getForce() {return pointForce;}

void PointClass::setPosiotion(float x, float y, int i)
{
    pointPosiotion.x[i] = x;
    pointPosiotion.y[i] = y;
}

void PointClass::setVelocity(float x, float y)
{
    pointVelocity.x = y;
    pointVelocity.y = y;
}

void PointClass::setForce(float x, float y)
{
    pointForce.x = x;
    pointForce.y = y;
}

void PointClass::drawPoint()
{
    ofSetColor(255, 255, 255);
    ofDrawRectangle(getPosition().x[1], getPosition().y[1], side*3, side);
}

void PointClass::updatePosition()
{
    float x = 2 * pointPosiotion.x[1] - pointPosiotion.x[0] + dt * dt * (pointForce.x/mass);
    float y = 2 * pointPosiotion.y[1] - pointPosiotion.y[0] + dt * dt * (pointForce.y/mass);
    
    setPosiotion(x, y, 2);
    setPosiotion(pointPosiotion.x[2], pointPosiotion.y[2], 1);
    setPosiotion(pointPosiotion.x[1], pointPosiotion.y[1], 0);
}

void PointClass::updateVelocity()
{
    float x = getVelocity().x + getForce().x * dt;
    float y = getVelocity().y + getForce().y * dt;
    setVelocity(x, y);
}

void PointClass::updateForce()
{
    pointForce.y = g * mass;
}

void PointClass::updateAll()
{
    updatePosition();
    updateVelocity();
    updateForce();
}

void PointClass::preparePositionVector(float x, float y)
{
    //First position, initial position
    pointPosiotion.x.push_back(x);
    pointPosiotion.y.push_back(y);
    
    //Secound position
    pointPosiotion.x.push_back(pointPosiotion.x[0] + dt * dt * (pointForce.x/mass));
    pointPosiotion.y.push_back(pointPosiotion.y[0] + dt * dt * (pointForce.y/mass));
    
    //Third position, Verlet method
    pointPosiotion.x.push_back(2 * pointPosiotion.x[1] - pointPosiotion.x[0] + dt * dt * (pointForce.x/mass));
    pointPosiotion.y.push_back(2 * pointPosiotion.y[1] - pointPosiotion.y[0] + dt * dt * (pointForce.y/mass));
}

PointClass::PointClass()
{
    mass = 0.1;
    side = 2;
    setForce(0, g);
}
PointClass::~PointClass()
{
    
}
