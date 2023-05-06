#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "../GameObject/object.h"

using uint = unsigned int;

/*
	Игрок - игровой объект, а значит, он будет наследовать и обладать общими свойствами игрового объекта, такие как:
	Координаты
	Размер
	Скорость
	Пока что это общие характеристики
*/

class player: public GameObject{
	public:
		player();
		player(Vector, Vector, Vector);
		player(Vector, Vector);
		player(GameObject);

		bool isJoystickConnected();
		void show();

		// что бы мы просчитывать коллизию
		// нам нужно будет вернуть класс GameObject 
		GameObject GetObject();
		
		// void Bot_ON();
		
		
	protected:
		bool Joystick_Connected = 0;
		uint JoysticID = 0;
		GameObject gm;
		bool isBotON = 0;
};


#endif