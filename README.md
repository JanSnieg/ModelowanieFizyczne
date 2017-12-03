
# Particle System in OpenFrameworks

MiniProject about particle system

## Getting Started

First of all I've wrote a particle class that contains x and y axes in all three ways: Position, Velocity and Force.
Than that class needed getters and setters, so I've implemented that.
Next step will be to add 'uploadPosition' etc. which will upload all three of dependences. Of course that will be physiclly correct.

### Examples

To see what I mean I will give a simple code that cointains struct Position from Particle class.hpp:

```
struct Position
    {
        float x;
        float y;
    } particlePosition;
```

and getter in Particle class.cpp

```
Particle2D::Position Particle2D::getPosition()
{
    return particlePosition;
}
```

### ofApp.cpp

Here I will try to explain and show what I did in main cpp file that is drawing scene.
First think is method prepareParticle().
First I'm creating new particle, than I'm setting its position in bottom-center of scene.
Veleociti is now not used.
Then I'm setting color of object to some kind of red (it will be fire so red is GOOD! :)).
Then some informative strings that contains x and y of particle.
Finally drawing Rectangle in position I've set few steps before, and with width, and hight of 20px.

```
{
    srand(time(NULL));
    Particle2D particle = Particle2D::Particle2D();
    particle.setPosiotion((rand() % 100) + 500, ofGetHeight() - 20);
    particle.setVelocity(10.0, 0.0);
    ofSetColor((rand() % 100) + 100, 0, 0);
    ofDrawBitmapString(particle.getPosition().x, 20, 20);
    ofDrawBitmapString(particle.getPosition().y, 20, 40);
    ofDrawRectangle(particle.getPosition().x, particle.getPosition().y, 20, 20);
}
```
