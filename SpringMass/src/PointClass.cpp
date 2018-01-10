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

void PointClass::setPosiotion(int x, int y)
{
    pointPosiotion.x = x;
    pointPosiotion.y = y;
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
    ofDrawRectangle(getPosition().x, getPosition().y, side*3, side);
}

PointClass::PointClass()
{
    
}
PointClass::~PointClass()
{
    
}
