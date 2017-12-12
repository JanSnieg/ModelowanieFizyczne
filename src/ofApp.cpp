#include "ofApp.hpp"

void ofApp::setup()
{
    srand(time(NULL));
    ofSetFrameRate(60);
    for(int i =0; i<10; i++)
        spamParticle();
    ofBackground(35, 42, 70);
}

void ofApp::draw()
{
    for (int i =0; i<particleVector.size(); i++)
    {
        particleVector[i].drawParticle();
    }
}

void ofApp::update()
{
    spamParticle();
    for (int i =0; i<particleVector.size(); i++)
    {
        particleVector[i].updatePosition();
        particleVector[i].updateColor();
    }
    //TODO do stop on spacekey clicked
}

void ofApp::spamParticle()
{
    Particle2D particle = Particle2D::Particle2D();
    particleVector.push_back(std::move(particle));
}
