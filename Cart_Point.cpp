#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "math.h"
#include <iostream>

Cart_Point::Cart_Point(){
    x = 0.0;
    y = 0.0;
}

Cart_Point::Cart_Point(double inputx, double inputy){
    x = inputx;
    y = inputy;
}

double cart_distance(Cart_Point p1, Cart_Point p2){
    double distance = sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
    return distance;
}

ostream &operator<< (ostream &output, const Cart_Point p1){
    output << "(" << p1.x << ", " << p1.y << ")";
    return output;
}

Cart_Point operator+ (const Cart_Point& p1, const Cart_Vector& v1){
    Cart_Point p2;
    p2.x = p1.x + v1.x;
    p2.y = p1.y + v1.y;
    return p2;
}

Cart_Vector operator- (const Cart_Point& p1, const Cart_Point& p2){
    Cart_Vector v1;
    v1.x = p1.x - p2.x;
    v1.y = p1.y - p2.y;
    return v1;
}


