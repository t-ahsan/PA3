#include "Game_Object.h"
#include "Cart_Point.h"
#include "View.h"
#include <iostream>
using namespace std;

View::View(){
	size = 11;
	scale = 2;
	origin.x = 0;
	origin.y = 0;
}

void View::clear(){
	for (int i = 0; i < view_maxsize; i++){
		for (int j = 0; j < view_maxsize; j++){
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::plot(Game_Object *ptr){
	char* obj;
	int ix = 0;
	int iy = 0;
	Cart_Point loc = ptr-> get_location();
	if (get_subscripts(ix, iy, loc)){
		ptr->drawself(grid[ix][iy]);
	}
}

void View::draw(){
    int array[view_maxsize/2 + 1];
    for (int i = 0; i < view_maxsize/2; i++)
    {
        array[i] = 2*i;
    }
    array[view_maxsize/2] = view_maxsize;

    for (int i = size -1; i >= 0; i--)
    {
        if (i%2 == 0)
        {
            cout << array[i];
            if (array[i] < 10)
            {
                cout << " ";
            }
        }
        else
        {
            cout << "  ";
        }

        for (int j = 0 ; j < size; j++)
        {
            cout << grid[j][i][0];
            cout << grid[j][i][1];
            
        }
        cout << endl;
    }
    cout << "  ";

    for (int i = 0; i <= size; i++)
    {
        if (i%2 == 0)
        {
            cout << array[i];
            if (array[i] < 10)
            {
                cout << " ";
            }
        }
        else
        {
            cout << "  ";
        }
    }
    cout << endl;
}

bool View::get_subscripts(int &ix, int &iy, Cart_Point location){
	ix = (location.x - origin.x)/scale;
	iy = (location.y - origin.y)/scale;
	if ((ix > view_maxsize) || (iy > view_maxsize)){
		cout << "An object is outside the display" << endl;
		return false;
	}
	else return true;
}