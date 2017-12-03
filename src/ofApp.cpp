#include "ofApp.hpp"


void ofApp::setup()
{
    ofSetFrameRate(60);
}

void ofApp::draw()
{
    for (int i=0; i<100; i++)
    {
        prepareParticle();
    }
}

void ofApp::update()
{
    Particle2D partilce = prepareParticle();
    partilce.updatePosition();
}

Particle2D ofApp::prepareParticle()
{
    Particle2D particle = Particle2D::Particle2D();
    ofSetColor((rand() % 100) + 100, 0, 0);
    
    stringstream ss;
    ss << "x: \t" << ofToString(particle.getPosition().x) << "\n";
    ss << "y: \t" << ofToString(particle.getPosition().y) << "\n";
    ss << "mass: \t" << ofToString(particle.mass) << "\n";
    ss << "side: \t" << ofToString(particle.side) << "\n";
    ofDrawBitmapString(ss.str().c_str(), 20, 20);
    
    ofDrawRectangle(particle.getPosition().x, particle.getPosition().y, particle.side, particle.side);
    return particle;
}
