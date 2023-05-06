#ifndef BALL_H
#define BALL_H

#include "../GameObject/object.h"


class Ball: public GameObject{
    public:
        Ball();
        Ball(GameObject);
        Ball(Vector, Vector, Vector);

        void SetAngle(int);
        void show();

    protected:
        int angle = 0;
        
        

};


#endif