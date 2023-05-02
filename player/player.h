#ifndef PLAYER_H
#define PLAYER_H

#include "SFML/Graphics.hpp"
#include "../GameObject/object.h"




/*
	Игрок - игровой объект, а значит, он будет наследовать и обладать общими свойствами игрового объекта, такие как:
	Координаты
	Размер
	Скорость
	Пока что это общие 
*/
class player: public GameObject{
	public:
		player();
		player(Vector, Vector, Vector);
		player(Vector, Vector);
		player(GameObject);

		void Move();

	protected:
		bool Joystick_Connected = 0;


};



#endif