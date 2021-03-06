#pragma once

#include "ofMain.h"
#include "TrampolineClass.hpp"
#include "rectangleClass.hpp"
#include <cstdlib>
#include <iostream>
#include "ofxGui.h"
#include <stdlib.h>


class ofApp : public ofBaseApp{

	public:
    
    TrampolineClass trampoline = TrampolineClass();
    RectangleClass rectangle = RectangleClass();
    ofxFloatSlider rectangleMass;
    ofxPanel gui;
    
		void setup();
		void update();
		void draw();
    
        void moveRectangle();
        void moveTrampoline();

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
