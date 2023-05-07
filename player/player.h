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

		void show();
		void ResetPlayer();

		void BOT();
	protected:
		bool isBot = 0;
		
};


#endif