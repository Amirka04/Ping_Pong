#include "Ball.h"

#include <iostream>
#include <cmath>


Ball::Ball():GameObject(Vector(0,0), Vector(0,0), Vector(0,0)){}

Ball::Ball(Vector coord, Vector size, Vector speed):GameObject(coord, size, speed){}

Ball::Ball(GameObject gm):GameObject(gm){}

// Установка угла 
void Ball::SetAngle(int angle){
    this->angle = angle;
    Speed *= Vector( sin(angle), cos(angle) );
}

void Ball::sign_speedX(){
    Speed.NegativeX();
}

void Ball::sign_speedY(){
    Speed.NegativeY();
}

// показываем наш объект
void Ball::show(){
    if(IsRight() || IsLeft())
        Speed.NegativeX();
    if(IsBottom() || IsTop())
        Speed.NegativeY();


    Move( Speed );
    draw();
}