#pragma once

//#include "ofMain.h"
#include "ofxGui.h"
#include "Particle class.hpp"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "ofxSimpleScreenRecorder.h"

class ofApp : public ofBaseApp{

	public:
    
        
        std::vector<Particle2D> particleVector;
    
		void setup();
        void update();
		void draw();
        void spamParticle();
        ofxSimpleScreenRecorder mRenderer;
        void keyReleased(int);
};
