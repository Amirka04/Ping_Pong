#include "object.h"
#include "iostream"
#include "cmath"

/*
 Любой объект в моей игре будет иметь общий класс:
 GameObject - дословно игровой объект, где будут прописаны почти все общие характеристики
 игрового объекта ( игрок, мяч, платформа и т.п. )
*/


GameObject::GameObject(){
}

float GameObject::dWindow = 1;

// инициализируем все элементы
GameObject::GameObject(Vector Coordinate, Vector Size, Vector Speed){
	this->Coordinate = Coordinate;
	this->Size = Size;
	this->Size.x *= dWindow;
	DefaultCoordinate = Coordinate;

	this->Speed = Speed;
	for(int i = 0; i < 4; i++){
		vec[i] *= this->Size;
		vec[i] += this->Coordinate;
	}
}

// инициализируем все элементы
GameObject::GameObject(Vector Coordinate, Vector Size){
	this->Coordinate = Coordinate;
	this->Size = Size;
	this->Size.x *= dWindow;
	DefaultCoordinate = Coordinate;

	for(int i = 0; i < 4; i++){
		vec[i] *= this->Size;
		vec[i] += this->Coordinate;
	}
}

// Что бы наши фигуры рисовались адекватно
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

// расчёт столкновений между 2-мя фигурами
bool GameObject::Collision(GameObject gm){

	// растояние по оси X и по оси Y
	float RustX = Coordinate.x - gm.Coordinate.x;
	float RustY = Coordinate.y - gm.Coordinate.y;
	
	/*
		Все объекты у нас равноудалены, а значит, что расстояние от одного края до центра, будет равно size/2
		А значит объекс Size нужно поделить на 2
	*/

	float SumSizeX = Size.x + gm.Size.x;
	float SumSizeY = Size.y + gm.Size.y;

	if( fabs(RustX) < SumSizeX && fabs(RustY) < SumSizeY)
		return 1;
	return 0;
}

// установка позиции
void GameObject::SetPosition(Vector DefCoord){
	Vector set_coord = DefCoord - Coordinate;
	Coordinate = DefCoord;

	for(int i = 0; i < 4; i++)
		vec[i] += set_coord;
}

// Вернуть прежнее значение
void GameObject::Reset(){
	SetPosition(DefaultCoordinate);
}

// Пересёк ли объект левую сторону
bool GameObject::IsLeft(){
	return Coordinate.x >= -1 + Size.x;
}

// Пересёк ли объект правую сторону
bool GameObject::IsRight(){
	return Coordinate.x <= 1 - Size.x;
}

// пересёк ли объект верхнюю сторону
bool GameObject::IsTop(){
	return Coordinate.y <= 1 - Size.y;;
}

// пересёк ли объект нижнюю сторону
bool GameObject::IsBottom(){
	return Coordinate.y >= -1 + Size.y;
}


void GameObject::Move(Vector dCoord){
	Coordinate += dCoord;
	for(int i = 0; i < 4; i++){
		vec[i] += dCoord;
	}
}