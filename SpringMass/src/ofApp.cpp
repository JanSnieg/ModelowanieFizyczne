#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
    gui.setup();
    gui.add(rectangleMass.setup("Rectangle mass",10,10,300));
    ofSetFrameRate(30);
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
//    for (int i=0; i<trampoline.pointsVector.size(); i++)
//    {
////        float x = trampoline.pointsVector[i].getPosition().x[1] - rectangle.getPosition().x;
////        float y = rectangle.getPosition().y + rectangle.side - trampoline.pointsVector[i].getPosition().y[1];
////        float distance = sqrt((x * x) + (y * y));
//        if (y == 0)
//        {
//            float forceX = trampoline.pointsVector[i].getForce().x;
//            float forceY = trampoline.pointsVector[i].getForce().y;
//            trampoline.pointsVector[i].setPosiotion(rectangle.getPosition().x, rectangle.getPosition().y, 1);
//            trampoline.pointsVector[i].setForce(forceX + rectangle.getForce().x, forceY + rectangle.getForce().y);
//        }
//    }
//    if (rectangle.getPosition().y - trampoline.pointsVector[7].getPosition().y[1] >= 1)
//    {
//        float forceX = trampoline.pointsVector[7].getForce().x;
//        float forceY = trampoline.pointsVector[7].getForce().y;
//        trampoline.pointsVector[7].setPosiotion(rectangle.getPosition().x, rectangle.getPosition().y, 1);
////        trampoline.pointsVector[7].setForce(forceX + rectangle.getForce().x, forceY + rectangle.getForce().y);
//        float force = rectangle.getForce().y;
//        force -= trampoline.pointsVector[7].getForce().y;;
//        rectangle.setForce(0, force);
//    }
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
