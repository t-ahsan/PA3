#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include "Astronaut.h"
#include "Person.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "View.h"
#include "Cart_Point.h"
#include "Alien.h"
#include <list>
using namespace std;


class Model{

public:	

	Model();
	Person * get_Person_ptr(int id);
	void make_active_ptr_list();
	void make_new_object(char type, int id, Cart_Point p);
	Oxygen_Depot * get_Oxygen_Depot_ptr(int id);
	Space_Station * get_Space_Station_ptr(int id); 
	Alien * get_Alien_ptr(int id); 
	bool update();
	void display(View &view);
	void show_status();
	~Model();

private:

	int time;
	int count_down;
	list<Game_Object*> object_ptrs;
	list<Game_Object*> active_ptrs;  
	list<Person*> person_ptrs;
	list<Oxygen_Depot*> depot_ptrs;
	list<Space_Station*> station_ptrs;
	list<Alien*> alien_ptrs;
	Astronaut *a1, *a2;
	Oxygen_Depot *o1, *o2;
	Space_Station *s1, *s2;
	Alien *x1, *x2;

}; 


#endif