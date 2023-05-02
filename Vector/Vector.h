#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

static int Joystick_ID = 0;

class Vector{
public:
	Vector();
	Vector(float, float);

	Vector operator+(Vector);
	Vector operator-(Vector);

	void Negative();
	void NegativeX();
	void NegativeY();
	
	void operator+=(Vector);
	void operator-=(Vector);
	void operator*=(Vector);


	friend std::ostream &operator<<(std::ostream &out, Vector &vector );

	float x;
	float y;
};

std::ostream &operator<<(std::ostream &out, Vector &vector );


#endif
