#ifndef CARTPOINT_H
#define CARTPOINT_H
#include <iostream>
#include "Cart_Vector.h"
using namespace std;

class Cart_Point{

public:	

	Cart_Point();
	Cart_Point(double inputx, double inputy);	
	double x;
	double y;

}; 

double cart_distance(Cart_Point p1, Cart_Point p2);
ostream &operator<< (ostream &output, const Cart_Point);
Cart_Point operator+ (const Cart_Point&, const Cart_Vector&);
Cart_Vector operator- (const Cart_Point&, const Cart_Point&);


#endif