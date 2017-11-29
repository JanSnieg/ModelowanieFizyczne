#include "ofApp.h"
void ofApp::setup()
{

}

void ofApp::draw()
{
    ofBackground(0,0,0);
    drawCircle(ofGetWidth()/2, ofGetHeight()/2, 600);
}

void ofApp::drawCircle(float x, float y, float radius)
{
    srand( time( NULL ) );
    ofSetColor(std::rand()%255,std::rand()%255 , std::rand()%255);
    ofDrawEllipse(x, y, radius, radius);
    if(radius > 2)
    {
        drawCircle(x + radius/2, y, radius/2);
        drawCircle(x - radius/2, y, radius/2);
    }
}

void ofApp::update()
{
    
}
