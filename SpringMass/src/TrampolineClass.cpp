//
//  TrampolineClass.cpp
//  SpringMass
//
//  Created by Jan Śnieg on 16/01/2018.
//

#include "TrampolineClass.hpp"

void TrampolineClass::draw()
{
    for(int i=0; i<pointsVector.size(); i++)
        pointsVector[i].drawPoint();
}

void TrampolineClass::updateAll()
{
    for(int i=0; i<pointsVector.size(); i++)
    {
        pointsVector[i].updateAll();
    }
    
    for (int i=1; i<pointsVector.size()-1; i++)
    {
        float dist = getDistance(pointsVector[linesVector[i].getPointIndex().point1], pointsVector[linesVector[i].getPointIndex().point2]);
        if (!pointsVector[linesVector[i].getPointIndex().point1].isHook || !pointsVector[linesVector[i].getPointIndex().point2].isHook)
        {
            if (dist > 0 || dist <= 1.5 * DISTANCE)
            {
                float positionX1 = pointsVector[linesVector[i].getPointIndex().point1].getPosition().x[1];
                float positionX2 = pointsVector[linesVector[i].getPointIndex().point2].getPosition().x[1];
                float positionY1 = pointsVector[linesVector[i].getPointIndex().point1].getPosition().y[1];
                float positionY2 = pointsVector[linesVector[i].getPointIndex().point2].getPosition().y[1];
                float velocityX = pointsVector[linesVector[i].getPointIndex().point1].getVelocity().x - pointsVector[linesVector[i].getPointIndex().point2].getVelocity().x;
                float velocityY = pointsVector[linesVector[i].getPointIndex().point1].getVelocity().y - pointsVector[linesVector[i].getPointIndex().point2].getVelocity().y;
                float force = (dist - linesVector[i].length) * KS + (velocityX * (positionX1 - positionX2) + velocityY * (positionY1 - positionY2)) * KD /dist;
                float ForceX = ((positionX1 - positionX2)/dist) * force;
                float ForceY = ((positionY1 - positionY2)/dist) * force;
                float oldForceX1 = pointsVector[linesVector[i].getPointIndex().point1].getForce().x;
                float oldForceX2 = pointsVector[linesVector[i].getPointIndex().point2].getForce().x;
                float oldForceY1 = pointsVector[linesVector[i].getPointIndex().point1].getForce().y;
                float oldForceY2 = pointsVector[linesVector[i].getPointIndex().point2].getForce().y;
                oldForceX1 -= ForceX;
                oldForceX2 += ForceX;
                oldForceY1 -= ForceX;
                oldForceY2 += ForceX;
                pointsVector[linesVector[i].getPointIndex().point1].setForce(oldForceX1, oldForceY1);
                pointsVector[linesVector[i].getPointIndex().point2].setForce(oldForceX2, oldForceY2);
            }
        }
    }
}

float TrampolineClass::getDistance(PointClass p1, PointClass p2)
{
    float x = p1.getPosition().x[1] - p2.getPosition().x[1];
    float y = p1.getPosition().y[1] - p2.getPosition().y[1];
    float distance = sqrt((x * x) + (y * y));
    return distance;
}

TrampolineClass::TrampolineClass()
{
    for (int i=0; i<LENGTH; i+=DISTANCE)
    {
        PointClass *point = new PointClass();
        point->preparePositionVector(i, 500);
        pointsVector.push_back(*std::move(point));
    }
    for (int i=1; i<pointsVector.size(); i++)
    {
        linesVector.push_back(SpringClass(i-1, i));
        linesVector[i-1].length = DISTANCE;
    }
    pointsVector[0].isHook = true;
    pointsVector[pointsVector.size()-1].isHook = true;
}

TrampolineClass::~TrampolineClass()
{
    
}

