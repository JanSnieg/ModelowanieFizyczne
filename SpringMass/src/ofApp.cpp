#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
    gui.setup();
    gui.add(rectangleMass.setup("Rectangle mass",10,10,300));
    ofSetFrameRate(60);
    ofBackground(35, 42, 70);
}

//--------------------------------------------------------------
void ofApp::update()
{
    moveRectangle();
    moveTrampoline();
    rectangle.setMass(rectangleMass);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (int i=0; i<trampoline.pointsVector.size(); i++)
        trampoline.pointsVector[i].drawPoint();
    trampoline.draw();
    rectangle.drawRectangle();
    gui.draw();
}

void ofApp::moveRectangle()
{
    rectangle.updatePosition();
    rectangle.updateVelocity();
    rectangle.updateForce();
}

void ofApp::moveTrampoline()
{
    for (int i=0; i<trampoline.pointsVector.size(); i++)
    {
        float distance = std::abs(rectangle.getPosition().y - trampoline.pointsVector[i].getPosition().y[1]);
        if (distance == 1)
        {
            float forceX = trampoline.pointsVector[i].getForce().x;
            float forceY = trampoline.pointsVector[i].getForce().y;
            trampoline.pointsVector[i].setForce(forceX + rectangle.getForce().x, forceY + rectangle.getForce().y);
        }
    }
    trampoline.updateAll();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
