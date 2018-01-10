#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetFrameRate(60);
    ofBackground(35, 42, 70);
    for (int i=0; i<ofGetWidth(); i+=10)
    {
        PointClass *point = new PointClass();
        point->setPosiotion(i, 500);
        pointsVector.push_back(*std::move(point));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (int i=0; i<pointsVector.size(); i++)
        pointsVector[i].drawPoint();
}

void ofApp::connectPoints()
{
    for (int i=0; i<pointsVector.size(); i++)
    {
        for (int j=1; j<pointsVector.size(); j++)
        {
            
        }
    }
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
