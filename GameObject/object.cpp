#include "object.h"

/*
 Любой объект в моей игре будет иметь общий класс:
 GameObject - дословно игровой объект, где будут прописаны почти все общие характеристики
 игрового объекта ( игрок, мяч, платформа и т.п. )
*/


GameObject::GameObject(){
}

float GameObject::dWindow = 1;

GameObject::GameObject(Vector Coordinate, Vector Size, Vector Speed){
	this->Coordinate = Coordinate;
	this->Size = Size;
	this->Size.x *= dWindow;
	
	this->Speed = Speed;
	for(int i = 0; i < 4; i++){
		vec[i] *= this->Size;
		vec[i] += this->Coordinate;
	}
}


void GameObject::SetDeltaWindow(float deltaWindow){
	dWindow = deltaWindow;
}


// функция для рисования
void GameObject::draw(){
	glEnableClientState(GL_VERTEX_ARRAY);
		glColor3f(1,1,1);
		glVertexPointer(2, GL_FLOAT, 0, vec);
		glDrawArrays(GL_QUADS, 0, 4);
	glDisableClientState(GL_VERTEX_ARRAY);
}
