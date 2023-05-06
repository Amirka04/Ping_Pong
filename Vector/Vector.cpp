#include "Vector.h"

Vector::Vector(){
}

Vector::Vector(float x, float y){
	this->x = x;
	this->y = y;
}

// перегрузка опреатора сложения
Vector Vector::operator+(Vector vec){
	return Vector(x + vec.x, y + vec.y);
}

// перегрузка оператора вычитания
Vector Vector::operator-(Vector vec){
	return Vector(x - vec.x, y - vec.y);
}

// перегружу оператор сложить и присвоить
void Vector::operator+=(Vector vec){
	x += vec.x;
	y += vec.y;
}

// перегружу оператор вычесть и присвоить
void Vector::operator-=(Vector vec){
	x -= vec.x;
	y -= vec.y;
}

// Понадобиться для установки размера :)
void Vector::operator*=(Vector vec){
	x *= vec.x;
	y *= vec.y;
}

// Конвертация координат в противоположное число
void Vector::Negative(){
	NegativeX();
	NegativeY();
}
// конвертация числа X в отрицательное число
void Vector::NegativeX(){
	x *= -1;
}
// конвертация числа Y в отрицательное число
void Vector::NegativeY(){
	y *= -1;
}




// перегружу оператор вывода для удобства
std::ostream &operator<<(std::ostream &out, Vector &vector ){
	out << "Vector(" << vector.x << ";" << vector.y << ")\n";
	return out;
}
