#include "Cart_Vector.h"
#include <iostream>

Cart_Vector::Cart_Vector(){
  	x = 0.0;
  	y = 0.0;
}

Cart_Vector::Cart_Vector(double inputx, double inputy){
  	x = inputx;
  	y = inputy;
}

ostream &operator<< (ostream &output, const Cart_Vector v1){
  	output << "<" << v1.x << ", " << v1.y << ">";
  	return output;
}

Cart_Vector operator* (const Cart_Vector& v1, double d){
	Cart_Vector v2;
	v2.x = v1.x * d;
	v2.y = v1.y * d;
	return v2;
}

Cart_Vector operator/ (const Cart_Vector& v1, double d){
	Cart_Vector v2;
	v2.x = v1.x / d;
	v2.y = v1.y / d;
	return v2;
}
