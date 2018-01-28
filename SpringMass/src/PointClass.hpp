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
        std::vector <float> x;
        std::vector <float> y;
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
    
    int side;
    float mass;
    float dt = 0.01;
    float g = 9.98;
    bool isHook = false;
    
    //getters
    position getPosition();
    velocity getVelocity();
    force getForce();
    
    //setters
    void setPosiotion(float x, float y, int i);
    void setVelocity(float x, float y);
    void setForce(float x, float y);
    
    void updatePosition();
    void updateVelocity();
    void updateForce();
    
    void updateAll();
    void preparePositionVector(int x, int y);
    
    void drawPoint();
};

#endif /* PointClass_hpp */
