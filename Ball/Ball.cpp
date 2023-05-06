#include "Ball.h"

#include <iostream>
#include <cmath>


Ball::Ball():GameObject(Vector(0,0), Vector(0,0), Vector(0,0)){}

Ball::Ball(Vector coord, Vector size, Vector speed):GameObject(coord, size, speed){}

Ball::Ball(GameObject gm):GameObject(gm){}

// Установка угла 
void Ball::SetAngle(int angle){
    this->angle = angle * M_PI;
    Speed *= Vector( sin(angle), cos(angle) );
}


void Ball::show(){

    draw();
}