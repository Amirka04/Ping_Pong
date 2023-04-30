#include "SFML/Graphics.hpp"
#include "GL/gl.h"

#include "GameObject/object.h"

using namespace sf;


int main(){
    float WindowW = 512, WindowH = 256;
    float dWindow = WindowH / WindowW;
    RenderWindow window(VideoMode( (int)WindowW, (int)WindowH), "Ping-Pong");

    GameObject::SetDeltaWindow(dWindow);

    GameObject gm(Vector(-.9,0), Vector(0.02,0.25), Vector(0,0));


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();
        }

        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Весь процесс игры
        gm.draw();


        window.display();
    }



}

