#ifndef OBJECT_H
#define OBJECT_H 1

#include "../Vector/Vector.h"
#include "GL/gl.h"

class player;

class GameObject: public Vector{
	protected:
		Vector Size{0,0};
		Vector Coordinate{0,0};
		Vector Speed{0,0};
		Vector *vec = new Vector[]{ {1, 1}, {-1,1}, {-1,-1}, {1,-1} };

		static float dWindow;

		/* Объявлю класс дружественным, что бы он имел доступ к его закрытым членам*/
		friend player;
		
	public:
		GameObject();
		GameObject(Vector, Vector, Vector);
		GameObject(Vector, Vector);


		static void SetDeltaWindow(float);
		void draw();

		bool Collision(GameObject);

		void Move();
		void SetPosition(float, float);
};


#endif