
# Spring Mass System in OpenFrameworks

MiniProject about spring mass system

## Getting Started

I've created struct "miniSpring". I've decided that I will not do class again and milion of methods, becouse it's not working for me the way it supposed to.
This struct have basic variables like gravity, mass, starting position of balls, timeStep etc.

### About miniSpring

Below you can see exact structure of my struct.

```
struct miniSpring {
    float gravity = 10;
    float mass = 100;
        // Mass 1
    float mass1PositionY = 600;
    float mass1PositionX = 400;
    float mass1VelocityY = 0;
    float mass1VelocityX = 0;
        
        // Mass 2
    float mass2PositionY = 300;
    float mass2PositionX = 200;
    float mass2VelocityY = 0;
    float mass2VelocityX = 0;
        
    float timeStep = 0.05;
    float anchorX = ofGetWidth()/2;
    float anchorY = 20;
    float k = 7;
    float damping = 10;} spring;
```

### updateBall()

I've created method updateBall() that does all physics for balls and springs.
Below you can see example for one of two balls:

```
        // Mass 1 Spring Force
    float mass1SpringForceY = -spring.k*(spring.mass1PositionY - spring.anchorY);
    float mass1SpringForceX = -spring.k*(spring.mass1PositionX - spring.anchorX);
    
        // Mass 1 daming
    float mass1DampingForceY = spring.damping * spring.mass1VelocityY;
    float mass1DampingForceX = spring.damping * spring.mass1VelocityX;
    
        // Mass 1 net force
    float mass1ForceY = mass1SpringForceY + spring.mass * spring.gravity - mass1DampingForceY - mass2SpringForceY + mass2DampingForceY;
    float mass1ForceX = mass1SpringForceX - mass1DampingForceX - mass2SpringForceX + mass2DampingForceX;
    
        // Mass 1 acceleration
    float mass1AccelerationY = mass1ForceY/spring.mass;float mass1AccelerationX = mass1ForceX/spring.mass;
    
        // Mass 1 velocity
    spring.mass1VelocityY += mass1AccelerationY * spring.timeStep;
    spring.mass1VelocityX += mass1AccelerationX * spring.timeStep;
    
        // Mass 1 position
    spring.mass1PositionY += spring.mass1VelocityY * spring.timeStep;
    spring.mass1PositionX += spring.mass1VelocityX * spring.timeStep;
    
```

### drawBall()

In this function I'm drawing masses, springs and anchor.


```
        //DRAWING
    ofSetColor(255, 255, 255);
    ofDrawRectangle(spring.anchorX-5, spring.anchorY-5, 10, 10);
    ofDrawLine(spring.anchorX, spring.anchorY, spring.mass1PositionX, spring.mass1PositionY);
    ofDrawCircle(spring.mass1PositionX, spring.mass1PositionY, 20);
    
    ofDrawLine(spring.mass1PositionX, spring.mass1PositionY, spring.mass2PositionX, spring.mass2PositionY);
    ofDrawCircle(spring.mass2PositionX, spring.mass2PositionY, 20);
```

### ofxPanel

Here I will tell, and show how I've done Sliders that changes mass, k and dampling.
first of all I've imported "ofxGui.h", that in ofApp.hpp, I'm making 3 sliders and oxfPanel to hold them together.

```
    ofxFloatSlider mass1;
    ofxFloatSlider damping;
    ofxFloatSlider k;
    ofxPanel gui;
```
Then in ofApp.cpp in setup(): 

```
    gui.setup();
    gui.add(mass1.setup("Mass: ",30,10,300));
    gui.add(damping.setup("Damping: ",2,0.1,30));
    gui.add(k.setup("K: ",2,0.1,30));
```
This is how thif method works:```gui.add(slider.setup(inicial, start, end));```
After this I need to draw it. To do that I've added ```gui.draw();``` in ofApp::update();

### Problems

Main problem was that I had to do this in two days, becouse I couldn't finished my first project I've been doing for 3 weeks.

## Thanks

My name is Paweł Olszowy, and thank you for your attention.
This is miniproject made for my classes.

