//
//  SpringClass.cpp
//  SpringMass
//
//  Created by Jan Śnieg on 16/01/2018.
//

#include "SpringClass.hpp"

SpringClass::pointIndex SpringClass::getPointIndex() {return index;}
void SpringClass::setPointIndex(int point1, int point2)
{
    index.point1 = point1;
    index.point2 = point2;
}

SpringClass::SpringClass(int point1, int point2)
{
    setPointIndex(point1, point2);
}

SpringClass::~SpringClass()
{
    
}
void SpringClass::drawSpring(PointClass p1, PointClass p2)
{
    ofSetColor(173, 13, 13);
    ofDrawLine(p1.getPosition().x[1], p1.getPosition().y[1], p2.getPosition().x[1], p2.getPosition().y[1]);
}
