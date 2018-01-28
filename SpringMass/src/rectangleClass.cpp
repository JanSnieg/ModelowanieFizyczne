//
//  rectangleClass.cpp
//  SpringMass
//
//  Created by Jan Śnieg on 10/01/2018.
//

#include "rectangleClass.hpp"
RectangleClass::position RectangleClass::getPosition() {return rectanglePosition;}
RectangleClass::velocity RectangleClass::getVelocity() {return rectangleVelocity;}
RectangleClass::force RectangleClass::getForce() {return rectangelForce;}

void RectangleClass::setPosiotion(int x, int y)
{
    rectanglePosition.x = x;
    rectanglePosition.y = y;
}

void RectangleClass::setVelocity(float x, float y)
{
    rectangleVelocity.x = x;
    rectangleVelocity.y = y;
}

void RectangleClass::setForce(float x, float y)
{
    rectangelForce.x = x;
    rectangelForce.y = y;
}

void RectangleClass::setMass(float m)
{
    mass = m;
}

void RectangleClass::updatePosition()
{
    rectanglePosition.x += rectangleVelocity.x * dt;
    rectanglePosition.y += rectangleVelocity.y * dt;
}

void RectangleClass::updateVelocity()
{
    rectangleVelocity.x += rectangelForce.x * dt;
    rectangleVelocity.y += rectangelForce.y * dt;
}

void RectangleClass::updateForce()
{
    rectangelForce.y = g * mass;
}

void RectangleClass::drawRectangle()
{
    ofSetColor(173, 13, 13);
    ofDrawRectangle(getPosition().x, getPosition().y, side, side);
}

RectangleClass::RectangleClass()
{
    setPosiotion(ofGetWidth()/2, 0);
    setVelocity(0.1,g);
    setForce(0.1, g);
    setMass(100);
}

RectangleClass::~RectangleClass()
{
    
}
