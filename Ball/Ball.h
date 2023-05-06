#ifndef BALL_H
#define BALL_H

#include "../GameObject/object.h"


class Ball: public GameObject{
    public:
        Ball();
        Ball(GameObject);
        Ball(Vector, Vector, Vector);

        // Установка угла 
        void SetAngle(int);

        // показ
        void show();

        void sign_speedX();
        void sign_speedY();

    protected:
        int angle = 0;
        
        

};


#endif