/*
АНЕКДОТ:

Программист звонит в библиотеку.
    — Здравствуйте, Катю можно?
    — Она в архиве.
    — Разархивируйте ее пожалуйста. Она мне срочно нужна!
*/


#include "SFML/Graphics.hpp"
#include "GL/gl.h"
#include "random"
#include "time.h"

#include "iostream"

#include "player/player.h"
#include "Ball/Ball.h"

using namespace sf;


int main(){
    srand(time(0));

    float WindowW = 512, WindowH = 256;
    float dWindow = WindowH / WindowW;
    
    RenderWindow window(VideoMode( (int)WindowW, (int)WindowH), "Ping-Pong");
    window.setFramerateLimit(120);

    GameObject::SetDeltaWindow(dWindow);

    player player1(Vector(-.98,0), Vector(0.03, 0.25), Vector(0,0.0085));
    
    Ball ball(Vector(0,0), Vector(0.05, 0.05), Vector(0,0));


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();

        }
		
        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Весь процесс игры
        player1.show();
        ball.show();
        
        

        
        window.display();
    }

}
