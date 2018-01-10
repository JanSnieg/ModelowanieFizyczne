//
//  PointClass.hpp
//  SpringMass
//
//  Created by Jan Śnieg on 10/01/2018.
//

#ifndef PointClass_hpp
#define PointClass_hpp

#include <stdio.h>
#include <vector>
#include "ofMain.h"

class PointClass
{
private:
    struct position
    {
        int x;
        int y;
    } pointPosiotion;
    
    struct velocity
    {
        float x;
        float y;
    } pointVelocity;
    
    struct force
    {
        float x;
        float y;
    } pointForce;

public:
    PointClass();
    ~PointClass();
    
    int side = 2;
    
    //getters
    position getPosition();
    velocity getVelocity();
    force getForce();
    
    //setters
    void setPosiotion(int x, int y);
    void setVelocity(float x, float y);
    void setForce(float x, float y);
    
    void drawPoint();
};

#endif /* PointClass_hpp */
