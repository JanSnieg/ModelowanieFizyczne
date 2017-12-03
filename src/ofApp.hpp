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
        Particle2D prepareParticle();
};
