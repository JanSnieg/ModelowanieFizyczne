#include "ofApp.hpp"

void ofApp::setup()
{
    srand(time(NULL));
    ofSetFrameRate(60);
    spamParticle();
    ofBackground(35, 42, 70);
//    ofSetColor(255, 255, 255);
//    ofDrawPlane(0, 0, 0, 1000, 1000);
}

void ofApp::draw()
{
    ofDrawBitmapStringHighlight("Number of Particles: " + ofToString(particleVector.size()), 20, 20, 20);
    ofDrawBitmapStringHighlight("Fps: " + ofToString(ofGetFrameRate(), 2), 20, 40, 20);
    cam.begin();
    ofSetColor(80,85,50);
    ofDrawBox(0, -300, 0, 10000, 0, 10000);
    for (int i =0; i<particleVector.size(); i++)
    {
        particleVector[i].drawParticle();
    }
    cam.end();
}

void ofApp::update()
{
    for(int i =0; i<6; i++)
        spamParticle();
    for (int i =0; i<particleVector.size(); i++)
    {
        if (particleVector[i].getColor().g < 180)
            particleVector[i].updateForce();
        particleVector[i].updateVelocity();
        particleVector[i].updatePosition();
        particleVector[i].updateColor();
        if (particleVector[i].side <= 1)
            particleVector.erase(particleVector.begin()+i);
    }
    //TODO do stop on spacekey clicked
}

void ofApp::spamParticle()
{
    Particle2D *particle = new Particle2D();
    particleVector.push_back(*std::move(particle));
}
