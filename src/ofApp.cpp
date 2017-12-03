#include "ofApp.hpp"
#include <stdlib.h>

void ofApp::setup()
{
    ofSetFrameRate(60);
}

void ofApp::draw()
{
//        srand(time(NULL));
    for (int i=0; i<100; i++)
    {
        prepareParticle();
    }
//        ofSetColor((rand() % 100) + 100, 0, 0);
//        ofDrawBitmapString(particle.getPosition().x, 20, 20);
//        ofDrawBitmapString(particle.getPosition().y, 20, 40);
//        ofDrawRectangle(particle.getPosition().x, particle.getPosition().y, 20, 20);
//        particle.updatePosition();
}

void ofApp::update()
{
    
}

void ofApp::prepareParticle()
{
    srand(time(NULL));
    Particle2D particle = Particle2D::Particle2D();
    particle.setPosiotion((rand() % 100) + 500, ofGetHeight() - 20);
    particle.setVelocity(10.0, 0.0);
    ofSetColor((rand() % 100) + 100, 0, 0);
    ofDrawBitmapString(particle.getPosition().x, 20, 20);
    ofDrawBitmapString(particle.getPosition().y, 20, 40);
    ofDrawRectangle(particle.getPosition().x, particle.getPosition().y, 20, 20);
//    return particle;
}
