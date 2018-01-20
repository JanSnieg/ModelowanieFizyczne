//
//  TrampolineClass.hpp
//  SpringMass
//
//  Created by Jan Śnieg on 16/01/2018.
//

#ifndef TrampolineClass_hpp
#define TrampolineClass_hpp

#include <stdio.h>
#include "PointClass.hpp"
#include "SpringClass.hpp"
#include "ofMain.h"


class TrampolineClass
{
public:
    int LENGTH = ofGetWidth();
    int DISTANCE = 10;
    float KS = 10;
    float KD = 0.1;
    std::vector<PointClass> pointsVector;
    std::vector<SpringClass> linesVector;
    
    TrampolineClass();
    ~TrampolineClass();
    PointClass getPointHook();
    
    void draw();
    void updateAll();
    float getDistance(PointClass p1, PointClass p2);
};

#endif /* TrampolineClass_hpp */
