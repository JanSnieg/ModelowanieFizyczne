#include "ofApp.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(mass1.setup("Mass: ",30,10,300));
    gui.add(damping.setup("Damping: ",2,0.1,30));
    gui.add(k.setup("K: ",2,0.1,30));
    ofSetFrameRate(60);
    ofBackground(35, 42, 70);
}

//--------------------------------------------------------------
void ofApp::update(){
    updateBall();
    spring.mass = mass1;
    spring.damping = damping;
    spring.k = k;
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawBall();
    gui.draw();
}

void ofApp::updateBall()
{
    /// Mass 1 Spring Force
    float mass1SpringForceY = -spring.k*(spring.mass1PositionY - spring.anchorY);
    float mass1SpringForceX = -spring.k*(spring.mass1PositionX - spring.anchorX);
    
    // Mass 2 Spring Force
    float mass2SpringForceY = -spring.k*(spring.mass2PositionY - spring.mass1PositionY);
    float mass2SpringForceX = -spring.k*(spring.mass2PositionX - spring.mass1PositionX);
    
    // Mass 1 daming
    float mass1DampingForceY = spring.damping * spring.mass1VelocityY;
    float mass1DampingForceX = spring.damping * spring.mass1VelocityX;
    
    // Mass 2 daming
    float mass2DampingForceY = spring.damping * spring.mass2VelocityY;
    float mass2DampingForceX = spring.damping * spring.mass2VelocityX;
    
    // Mass 1 net force
    float mass1ForceY = mass1SpringForceY + spring.mass * spring.gravity - mass1DampingForceY - mass2SpringForceY + mass2DampingForceY;
    
    float mass1ForceX = mass1SpringForceX - mass1DampingForceX - mass2SpringForceX + mass2DampingForceX;
    
    // Mass 2 net force
    float mass2ForceY = mass2SpringForceY + spring.mass * spring.gravity - mass2DampingForceY;
    float mass2ForceX = mass2SpringForceX - mass2DampingForceX;
    
    // Mass 1 acceleration
    float mass1AccelerationY = mass1ForceY/spring.mass;float mass1AccelerationX = mass1ForceX/spring.mass;
    
    // Mass 2 acceleration
    float mass2AccelerationY = mass2ForceY/spring.mass;
    float mass2AccelerationX = mass2ForceX/spring.mass;
    
    // Mass 1 velocity
    spring.mass1VelocityY += mass1AccelerationY * spring.timeStep;
    spring.mass1VelocityX += mass1AccelerationX * spring.timeStep;
    
    // Mass 2 velocity
    spring.mass2VelocityY += mass2AccelerationY * spring.timeStep;
    spring.mass2VelocityX += mass2AccelerationX * spring.timeStep;
    
    // Mass 1 position
    spring.mass1PositionY += spring.mass1VelocityY * spring.timeStep;
    spring.mass1PositionX += spring.mass1VelocityX * spring.timeStep;
    
    // Mass 2 position
    spring.mass2PositionY += spring.mass2VelocityY * spring.timeStep;
    spring.mass2PositionX += spring.mass2VelocityX * spring.timeStep;
}

void ofApp::drawBall()
{
    //DRAWING
    ofSetColor(255, 255, 255);
    ofDrawRectangle(spring.anchorX-5, spring.anchorY-5, 10, 10);
    ofDrawLine(spring.anchorX, spring.anchorY, spring.mass1PositionX, spring.mass1PositionY);
    ofDrawCircle(spring.mass1PositionX, spring.mass1PositionY, 20);
    
    ofDrawLine(spring.mass1PositionX, spring.mass1PositionY, spring.mass2PositionX, spring.mass2PositionY);
    ofDrawCircle(spring.mass2PositionX, spring.mass2PositionY, 20);
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
