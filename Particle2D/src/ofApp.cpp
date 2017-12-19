#include "ofApp.hpp"

void ofApp::setup()
{
    srand(time(NULL));
    ofSetFrameRate(60);
    spamParticle();
    ofBackground(35, 42, 70);
}

void ofApp::draw()
{
    ofDrawBitmapStringHighlight("Number of Particles: " + ofToString(particleVector.size()), 20, 20);
    ofDrawBitmapStringHighlight("Fps: " + ofToString(ofGetFrameRate(), 2), 20, 40);
    for (int i =0; i<particleVector.size(); i++)
    {
        particleVector[i].drawParticle();
    }
}

void ofApp::update()
{
    for(int i =0; i<10; i++)
        spamParticle();
    for (int i =0; i<particleVector.size(); i++)
    {
//        if (particleVector[i].getColor().g < 180)
        particleVector[i].updateForce();
        particleVector[i].updateVelocity();
        particleVector[i].updatePosition();
        particleVector[i].updateColor();
        if (particleVector[i].isDead)
            particleVector.erase(particleVector.begin()+i);
    }
}

void ofApp::spamParticle()
{
    Particle2D *particle = new Particle2D();
    particleVector.push_back(*std::move(particle));
}
