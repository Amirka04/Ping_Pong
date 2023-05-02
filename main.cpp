/*
АНЕКДОТ:

Программист звонит в библиотеку.
    — Здравствуйте, Катю можно?
    — Она в архиве.
    — Разархивируйте ее пожалуйста. Она мне срочно нужна!

© https://anekdoty.ru/pro-programmistov/

*/


#include "SFML/Graphics.hpp"
#include "GL/gl.h"

#include "player/player.h"


using namespace sf;


int main(){

    float WindowW = 512, WindowH = 256;
    float dWindow = WindowH / WindowW;
    
    RenderWindow window(VideoMode( (int)WindowW, (int)WindowH), "Ping-Pong");
    window.setFramerateLimit(120);

    GameObject::SetDeltaWindow(dWindow);


    player player1(Vector(-0.95,0), Vector(0.02, 0.25), Vector(0,0.006));
    

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
        // player2.draw();



        window.display();
    }



}
