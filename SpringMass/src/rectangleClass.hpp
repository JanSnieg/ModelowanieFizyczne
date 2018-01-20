//
//  rectangleClass.hpp
//  SpringMass
//
//  Created by Jan Śnieg on 10/01/2018.
//

#ifndef rectangleClass_hpp
#define rectangleClass_hpp

#include <stdio.h>
#include "ofMain.h"

class RectangleClass
{
    struct position {int x, y;} rectanglePosition;
    struct velocity {float x,y;} rectangleVelocity;
    struct force    {float x,y;} rectangelForce;
    
public:
    
    int side = 20;
    float mass;
    float g = 9.98;
    float dt = 0.01;
    
    RectangleClass();
    ~RectangleClass();
    
    //getters
    position getPosition();
    velocity getVelocity();
    force getForce();
    
    //setters
    void setPosiotion(int x, int y);
    void setVelocity(float x, float y);
    void setForce(float x, float y);
    void setMass(float m);
    
    //updaters
    void updatePosition();
    void updateVelocity();
    void updateForce();
    
    void drawRectangle();
};

#endif /* rectangleClass_hpp */
