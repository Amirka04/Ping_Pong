#include "player.h"


// ==================================================================================================

/* Все четыре конструктора с раными параметрами, я объявляю для удобства
	т.к. кто то может сначало создать объект класса GameObject и потом передать его как параметр
	а кто то сразу использует анонимные конструкторы
*/

player::player(){}

player::player(Vector Coordinate, Vector Size, Vector Speed): GameObject(Coordinate, Size, Speed){}

player::player(Vector Coordinate, Vector Size): GameObject(Coordinate, Size){}

player::player(GameObject u_gm): GameObject(u_gm){}
// ==================================================================================================

// проверка на подключённый джойстик
bool player::isJoystickConnected(){
	return sf::Joystick::isConnected(Joystick_Connected);
}

// Функция которая покажет нам наш
void player::show(){
	int KeyUP = 0;
	int KeyDown = 0;
	
	using namespace sf;{
		KeyUP = Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up);
		KeyDown = Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down);
	}

	if( KeyDown && !IsBottom() )
		Move( Vector(Speed.x, -Speed.y) );
	if( KeyUP && !IsTop() )
		Move( Vector(Speed.x, Speed.y) );
	
	glColor3f(1,1,1);
	draw();
}

void player::ResetPlayer(){
	Reset();
}

GameObject player::GetObject(){
	return GameObject(Coordinate, Size, Speed);
}

