#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Particle class.hpp"
#include <cstdlib>

class ofApp : public ofBaseApp{

	public:
		void setup();
        void update();
		void draw();
        void prepareParticle();
};
