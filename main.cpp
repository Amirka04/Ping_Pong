#include "SFML/Graphics.hpp"
#include "GL/gl.h"

#include "Vector/Vector.h"

using namespace sf;


int main(){

    RenderWindow window(VideoMode(512, 128), "Ping-Pong");

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed)
                window.close();
        }

        glClearColor(0,0,0,0);
        glClear(GL_COLOR_BUFFER_BIT);

        // Весь процесс игры



        window.display();

    }



}

