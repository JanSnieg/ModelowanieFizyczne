
# Particle System in OpenFrameworks

MiniProject about particle system

## Getting Started

First of all I've wrote a particle class that contains x, y and z axes in all three ways: Position, Velocity and Force.
Then that class needed getters and setters, so I've implemented that.
Secound thing I've done was to implement struct 'Color' with R,G,B and A. I've used it to generate yellow particles, and to control when particles will dissolve, and come back as smoke.
I have added methods like uploadPosition, velocity and force to step by step change pasrticle behaviour.

### Examples

To see what I mean I will give a simple code that cointains struct Position from Particle class.hpp.
This struct cointains 3 vectors, becouse I've implemented verlet method, and for this every particle need to have 3 positions: (n-1, n and n+1).

```
struct Position
    {
        std::vector <float> x;
        std::vector <float> y;
        std::vector <float> z;
    } particlePosition;
```

Getter in Particle class.cpp

```
Particle2D::Position Particle2D::getPosition()
{
    return particlePosition;
}
```

### ofApp.cpp

In method spamParticle I'm creating object from Particle class.
Then 


```
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

```
