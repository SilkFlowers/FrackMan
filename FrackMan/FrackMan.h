//
//  FrackMan.h
//  FrackMan
//
//  Created by hongshuhong on 2/14/16.
//  Copyright © 2016 David Smallberg. All rights reserved.
//

/* PLEASE REFER TO PG 52 & 53 OF SPEC */

#ifndef FrackMan_h
#define FrackMan_h

// It must have an Image ID of IID_PLAYER
#include "GameConstants.h"
#include "StudentWorld.h"
#include "Nugget.h"
#include "Actor.h"
#include <vector>

using namespace std;

class StudentWorld;
/* The fact that it depends on Actor is TENTATIVE. we might change this! */
// It (or its base class) must make itself visible via a call to setVisible(true);
class FrackMan : public Human{
    
static const int START_Y = 60;
static const int START_X = 30;
static const int GOLD_TICKS = 100;
static const int INIT_HITPOINT = 10;
static const int INIT_WATER = 5;
static const int INIT_SONAR = 1;
static const int INIT_NUGGET = 0;

public:
    // It must have a simple constructor and destructor that
    // initializes/deinitializes the FrackMan – see the FrackMan section
    // for more details on where to initially place the FrackMan on the screen.
    
    // from pg 28: The FrackMan must always start at location x=30, y=60
    FrackMan(StudentWorld* w) : Human(INIT_HITPOINT, w, IID_PLAYER, START_X, START_Y){
        /* The FrackMan, in its default state:
         a. Is given 10 hit points
         b. Is given 5 units of water to squirt with his squirt gun (he may pick up
         additional Water in the oil field)
         c. Is given 1 sonar charge
         d. Starts out with zero gold nuggets
         e. Should start facing rightward*/
        water = INIT_WATER;
        sonar = INIT_SONAR;
        nugget = INIT_NUGGET;
    };
    virtual ~FrackMan(){};
    
    /* It must have a limited version of a doSomething() method that lets
    the user pick a direction by hitting a directional key. If the player
    hits a directional key during the current tick, it updates the
    FrackMan’s location to the target square, removing any Dirt
    objects that overlap with the FrackMan’s 4x4 graphic image. To
    move the FrackMan, all this doSomething() method has to do is
    properly adjust the player’s X,Y coordinates using GraphObject’s
    moveTo() method and our graphics system will automatically
    animate its movement it around the oil field!
     */
    virtual void doSomething();
    
    Direction keyToDir(int keyPressed){
        switch(keyPressed){
            case KEY_PRESS_LEFT:
                return left;
                break;
            case KEY_PRESS_RIGHT:
                return right;
                break;
            case KEY_PRESS_UP:
                return up;
                break;
            case KEY_PRESS_DOWN:
                return down;
                break;
        }
        return none;
    }
    /* getters */
    int getWater(){
        return water;
    }
    int getSonar(){
        return sonar;
    }
    int getNugget(){
        return nugget;
    }
    /* setters */
    void increaseNugget(int amt){
        nugget += amt;
    }
    void increaseSonar(int amt){
        sonar += amt;
    }
    void increaseWater(int amt){
        water += amt;
    }
    virtual void changeState(Direction dir);

private:
    // You may add any public/private methods and private member
    // variables to your player class as you see fit, so long as you use
    // good object oriented programming style (e.g., you must not duplicate functionality across classes).
    int water;
    int sonar;
    int nugget;
};


#endif /* FrackMan_h */
