#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <stdio.h>      /* printf */
#include <math.h>

class ofApp : public ofBaseApp{

	public:
        //INITIALIZATION
    struct miniSpring
    {
        float gravity = 10;
        float mass = 100;
        float radious = sqrt(mass)/M_PI;
        // Mass 1
        float mass1PositionY = 600;
        float mass1PositionX = 400;
        float mass1VelocityY = 0;
        float mass1VelocityX = 0;
        
        // Mass 2
        float mass2PositionY = 300;
        float mass2PositionX = 200;
        float mass2VelocityY = 0;
        float mass2VelocityX = 0;
        
        float timeStep = 0.05;
        float anchorX = ofGetWidth()/2;
        float anchorY = 40;
        float k = 7;
        float damping = 10;} spring;
    
        ofxFloatSlider mass1;
        ofxFloatSlider damping;
        ofxFloatSlider k;
        ofxPanel gui;
    
    bool isHolding1 = false;
    bool isHolding2 = false;
    
		void setup();
		void update();
		void draw();
    
    void updateBall();
        void drawBall();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
