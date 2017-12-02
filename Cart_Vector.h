#ifndef CARTVECTOR_H
#define CARTVECTOR_H
#include <iostream>
using namespace std;

class Cart_Vector{

public:	
	
	Cart_Vector();
	Cart_Vector(double inputx, double inputy);	
	double x;
	double y;

}; 

ostream &operator<< (ostream &output, const Cart_Vector);
Cart_Vector operator* (const Cart_Vector&, double d);
Cart_Vector operator/ (const Cart_Vector&, double d);


#endif