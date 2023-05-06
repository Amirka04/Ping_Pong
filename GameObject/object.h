#ifndef OBJECT_H
#define OBJECT_H 1

#include "../Vector/Vector.h"
#include "GL/gl.h"

class player;

class GameObject: public Vector{
	protected:
		Vector Size{0,0};					// Размер
		Vector Coordinate{0,0};				// Координаты
		Vector DefaultCoordinate{0,0};		// Координаты которые мы поставили при инициализации обычных координат
		Vector Speed{0,0};					// Скорость
		Vector *vec = new Vector[]{ {1, 1}, {-1,1}, {-1,-1}, {1,-1} };	// массив вершин для рисования

		static float dWindow;				// Установка статического типа, для хранения отношения между высотой и длиной окна, что бы объекты не были шире 
											// вместе с окном

		/* Объявлю класс дружественным, что бы он имел доступ к его закрытым членам*/
		friend player;

	public:
		GameObject();
		GameObject(Vector, Vector, Vector);
		GameObject(Vector, Vector);

		// проверка, не вышел ли объект за пределы всех сторон экрана
		bool IsLeft();
		bool IsRight();
		bool IsTop();
		bool IsBottom();

		// вернуть все значения в исходное состояние
		void Reset();

		// статическая ф-я - метод, для установки разницы окна
		static void SetDeltaWindow(float);

		// рисование 
		void draw();

		// Расчёт столкновения между объектами
		bool Collision(GameObject);

		// движение персонажа
		void Move(Vector);

		// указание позиции
		void SetPosition(Vector);
};


template <class T>
int number_sign(T num){
	if(num <= 0)
		return -1;
	return 1;
}

#endif