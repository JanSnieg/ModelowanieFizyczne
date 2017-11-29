#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <cstdlib>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void drawCircle(float x, float y, float radius);

};
