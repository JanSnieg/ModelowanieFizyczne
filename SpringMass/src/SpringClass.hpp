//
//  SpringClass.hpp
//  SpringMass
//
//  Created by Jan Śnieg on 16/01/2018.
//

#ifndef SpringClass_hpp
#define SpringClass_hpp

#include <stdio.h>
#include "ofMain.h"
#include "PointClass.hpp"

class SpringClass
{
    struct pointIndex
    {
        int point1, point2;
    } index;
    
    
public:
    float length;
    //getters
    pointIndex getPointIndex();
    //setters
    void setPointIndex(int point1, int point2);
    void drawSpring(PointClass p1, PointClass p2);
    

    SpringClass(int point1, int point2);
    ~SpringClass();
};

#endif /* SpringClass_hpp */
