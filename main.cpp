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
    player Bot(Vector(.98,0), Vector(0.03, 0.25), Vector(0,0.006));
    

    Ball ball( Vector(0,0), Vector(0.06, 0.06), Vector(0.009,0.009) );
    ball.SetAngle( 90 + rand() % 180 );


    int ScorePlayer = 0, MyGameScore = 0;

    system("clear");
    std::cout << "\033[92mGame ON!!\033[0m" << std::endl;

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
        
        Bot.BOT();
        Bot.draw();
        Bot.following( ball.GetGameObject() );
        
        ball.show();


        // после столкновения об игрока отскакивает
        if( ball.Collision( player1.GetGameObject() ) || ball.Collision( Bot.GetGameObject() ) )
            ball.sign_speedX();


        if( ball.IsLeft() || ball.IsRight() ){
            if(ball.IsLeft())
                MyGameScore++;
            else
                ScorePlayer++;
            
            ball.Reset();
            player1.Reset();
            ball.SetAngle( 90 + rand() % 180 );

            system("clear");
            std::cout << "Ты -> " << ScorePlayer << " : " << MyGameScore << " <- Бот" << std::endl;
        }




        window.display();
    }

}
