#include "player.h"


// ==================================================================================================

/* Все четыре конструктора с раными параметрами, я объявляю для удобства
	т.к. кто то может сначало создать объект класса GameObject и потом передать его как параметр
	а кто то сразу использует анонимные конструкторы
*/

player::player(){}

player::player(Vector Coordinate, Vector Size, Vector Speed): gm(Coordinate, Size, Speed){
	Joystick_Connected = Joystick_ID;
	Joystick_ID++;
}

player::player(Vector Coordinate, Vector Size): gm(Coordinate, Size){
	Joystick_Connected = Joystick_ID;
	Joystick_ID++;
}

player::player(GameObject u_gm): gm(u_gm){
	Joystick_Connected = Joystick_ID;
	Joystick_ID++;
}
// ==================================================================================================


// проверка на подключённый джойстик
bool player::isJoystickConnected(){
	return sf::Joystick::isConnected(Joystick_Connected);
}

// Функция которая покажет нам наш
void player::show(){
	
	// все необходимые команды для джойстика, думал это в отдельный класс вывести, но отказался от этой идеии, т.к. 
	// астракции если честно, тут хватает...
	int JoystickCommandUp = sf::Joystick::isButtonPressed(0, 0) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < 0;
	int JoystickCommandDown = sf::Joystick::isButtonPressed(0, 2) || sf::Joystick::getAxisPosition(0, sf::Joystick::Y) > 0;

	int KeyUP;
	int KeyDown;

	using namespace sf;{
		KeyUP = Keyboard::isKeyPressed(Keyboard::Key::W) || Keyboard::isKeyPressed(Keyboard::Key::Up);
		KeyDown = Keyboard::isKeyPressed(Keyboard::Key::S) || Keyboard::isKeyPressed(Keyboard::Key::Down);

	}

	if( (JoystickCommandDown || KeyDown) && gm.Coordinate.y > -1 + gm.Size.y)
		gm.SetPosition(gm.Speed.x, -gm.Speed.y);
	if( (JoystickCommandUp || KeyUP) && gm.Coordinate.y < 1 - gm.Size.y)
		gm.SetPosition(gm.Speed.x, gm.Speed.y);

	gm.draw();
}


GameObject player::GetObject(){
	return gm;
}