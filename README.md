
# Particle System in OpenFrameworks

MiniProject about particle system

## Getting Started

First of all I've wrote a particle class that contains x, y and z axes in all three ways: Position, Velocity and Force.
Then that class needed getters and setters, so I've implemented that.
Secound thing I've done was to implement struct 'Color' with R,G,B and A. I've used it to generate yellow particles, and to control when particles will dissolve, and come back as smoke.
I have added methods like uploadPosition, velocity and force to step by step change pasrticle behaviour.

### Introduction to Particle class

To see what I mean I will give a simple code that cointains struct Position from Particle class.hpp.
This struct cointains 3 vectors, because I've implemented Verlet method, and for this every particle need to have 3 positions: (n-1, n and n+1).

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

In method spamParticle I'm creating object from Particle class and pushing it to vector.
Then I use it to spam particles in ofApp::update(), to be sure that fire will keep burning.
Next I'm going throught every object in vector and updating its variables.
Finally I'm deleteing particles that are burned out.

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
}

void ofApp::spamParticle()
{
    Particle2D *particle = new Particle2D();
    particleVector.push_back(*std::move(particle));
}

```

Drawing is made in ofApp::draw(), which is pretty simple. Justy informatory I'm making two strings that contais number of particle in vector, and fps.
Next I'm drawing box, on which fire is burning, than drawing every particle in for loop.
cam is ofEasyCam, and is needed to coordinate in 3D scene.

```
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
```

### Physics, and maths

All physics and maths are in 'update' methods and Particle2D::preparePositionVector().
I'm preparing position for Verlet mathod in 3 steps:

```
void Particle2D::preparePositionVector()
{
    //First position, initial position
    particlePosition.x.push_back(RandomMinMax(-75, 75));
    //Secound position
    particlePosition.x.push_back(particlePosition.x[0] + dt * dt * (particleForce.x/mass));
    //Third position, Verlet method
    particlePosition.x.push_back(2 * particlePosition.x[1] - particlePosition.x[0] + dt * dt * (particleForce.x/mass));
}
```
and doing it in all 3 axises.

Next intersing thing is in update position (again Verlet) and it's like that:
```
float x = 2 * particlePosition.x[1] - particlePosition.x[0] + dt * dt * (particleForce.x/mass);
.
.
.
setPosiotion(x, y, z, 2);
setPosiotion(particlePosition.x[2], particlePosition.y[2],particlePosition.z[2], 1);
setPosiotion(particlePosition.x[1], particlePosition.y[1], particlePosition.z[1], 0);
```
And this is how I know that I will always have position vector that contains 3 positions of x, y and z.
Updating velocity is simple and not worthy mentioning, but updateForce is nice, based on one of ofExamples.
```
float fakeWindX = ofSignedNoise(getPosition().x[1] * 0.003, getPosition().y[1] * 0.006, ofGetElapsedTimef() * 0.6);
float x = fakeWindX * 40 + ofSignedNoise(uniqueValue, getPosition().y[1]) * 20;
float z = fakeWindX * 40 + ofSignedNoise(uniqueValue, getPosition().z[1]) * 20;
setForce(x, getForce().y, z);
```
I've used ofSignedNoise to make fire act like real fire, but if I will do this part of physics again I will do it better way making some Curl noises.

### Color
In my little animation color is one of main variables that is deciding if particle is fading out or changeing into smoke so I will show how I did it.
First method is:
```
void Particle2D::updateColor()
{
    if(getColor().g <= 0 || isDead)
        fadeOut();
    else
    {
        int g = getColor().g;
        int randomNumber = RandomMinMax(1, 3);
        g -= randomNumber;
        setColor(getColor().r, g, getColor().b, getColor().a);
    }
}
```
Here I'm just changing green color in RGB, because if g is smaller particle will become more and more redish and if it's red secound method will do fading out.
```
void Particle2D::fadeOut()
{
    int a = getColor().a;
    if (visible > 0 )
    {
        a -= 5;
        setColor(getColor().r, getColor().g, getColor().b, a);
        visible --;
    }
    else
    {
        isDead = true;
        smokeOn();
    }
}
```
'Visible' variable is random int from 100 to 130.
So here I'm just making my particles transparent, and if theye are fully transparent they will become smoke:
```
void Particle2D::smokeOn()
{
    if (wasDead)
    {
        int randomNumber = RandomMinMax(10, 15);
        int r = getColor().r;
        int g = getColor().g;
        int b = getColor().b;
        int a = getColor().a;
        r += randomNumber;
        g += randomNumber;
        b += randomNumber;
        if (a < 255)
            a += 10;
        setColor(r, g, b, a);
        if (side > 0)
            side -= 0.1;
    }
    else if (isDead)
    {
        setColor(100, 100, 100, getColor().a);
        wasDead = true;
    }
}
```
And this is everything I wanted to mantion here.

### Problems

Main problem here was to make particle variables easy to get and change.
I've did all setters, getters and structs in first week so next days will become more efficient.
And it was much easier to do coloring, fading out and just uplifting particles. This took me like one day.
In the end I've wored on physics and maths, and that was chalenging, but all in all it is looking good.

## Thanks

My name is Paweł Olszowy, and I'm thankig you for you attention.
This is miniproject made on my classes.
