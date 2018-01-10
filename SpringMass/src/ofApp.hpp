#pragma once

#include "ofMain.h"
#include "PointClass.hpp"
#include <cstdlib>
#include <iostream>


class ofApp : public ofBaseApp{

	public:
    
    std::vector<PointClass> pointsVector;
    
		void setup();
		void update();
		void draw();
    
        void connectPoints();

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
