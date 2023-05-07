#ifndef OBJECT_H
#define OBJECT_H 1

#include "../Vector/Vector.h"
#include "GL/gl.h"


class GameObject: public Vector{
	protected:
		Vector Size{0,0};					// Размер
		Vector Coordinate{0,0};				// Координаты
		Vector DefaultCoordinate{0,0};		// Координаты которые мы поставили при инициализации обычных координат
		Vector Speed{0,0};					// Скорость
		Vector DefaultSpeed{0,0};			// Начальная скорость с которой всё начиналось
		Vector *vec = new Vector[]{ {1, 1}, {-1,1}, {-1,-1}, {1,-1} };	// массив вершин для рисования

		static float dWindow;				// Установка статического типа, для хранения отношения между высотой и длиной окна, что бы объекты не были шире 
											// вместе с окном


	public:
		GameObject();
		GameObject(Vector, Vector, Vector);
		GameObject(Vector, Vector);

		~GameObject();
		// ===========================================================================================
		// проверка, не вышел ли объект за пределы всех сторон экрана
		bool IsLeft();
		bool IsRight();
		bool IsTop();
		bool IsBottom();
		// ===========================================================================================

		GameObject GetGameObject();

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

		// ф-я следования за объектом
		void following(GameObject);

		// указание позиции
		void SetPosition(Vector);
};


#endif