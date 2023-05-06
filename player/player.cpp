#include "player.h"


// ==================================================================================================

/* Все четыре конструктора с раными параметрами, я объявляю для удобства
	т.к. кто то может сначало создать объект класса GameObject и потом передать его как параметр
	а кто то сразу использует анонимные конструкторы
*/

player::player(){}

player::player(Vector Coordinate, Vector Size, Vector Speed): gm(Coordinate, Size, Speed){}

player::player(Vector Coordinate, Vector Size): gm(Coordinate, Size){}

player::player(GameObject u_gm): gm(u_gm){}
// ==================================================================================================


// проверка на подключённый джойстик
bool player::isJoystickConnected(){
	return sf::Joystick::isConnected(Joystick_Connected);
}

// Функция которая покажет нам наш
void player::show(){
	int KeyUP = 0;
	int KeyDown = 0;
	int KeyReset = 0;

	using namespace sf;{
		KeyUP = Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up);
		KeyDown = Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down);
		KeyReset = Keyboard::isKeyPressed(Keyboard::Key::R);
	}

	if( KeyDown && gm.IsBottom() )
		gm.Move( Vector(gm.Speed.x, -gm.Speed.y) );
	if( KeyUP && gm.IsTop() )
		gm.Move( Vector(gm.Speed.x, gm.Speed.y) );
	if(KeyReset)
		gm.Reset();

	glColor3f(1,1,1);
	gm.draw();
}


void BotGame(){	
}


// получение объекта gm 
GameObject player::GetObject(){
	return gm;
}


