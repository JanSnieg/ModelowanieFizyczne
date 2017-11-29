#include "ofApp.h"
#include "Particle class.hpp"

void ofApp::setup()
{
    
}

void ofApp::draw()
{
    ofSetColor(255, 255, 255);
    Particle2D particle = Particle2D::Particle2D();
    particle.setPosiotion(300, 300);
    particle.setVelocity(10, 0);
    ofDrawRectangle(particle.getPosition().x, particle.getPosition().y, 500, 500);
    //particle.updatePosition();
}

void ofApp::update()
{
    
}
