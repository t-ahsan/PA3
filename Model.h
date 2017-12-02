#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include "Astronaut.h"
#include "Person.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "View.h"
using namespace std;


class Model{

public:	

	Model();
	Person * get_Person_ptr(int id);
	Oxygen_Depot * get_Oxygen_Depot_ptr(int id);
	Space_Station * get_Space_Station_ptr(int id);  
	bool update();
	void display(View &view);
	void show_status();
	~Model();

private:

	int time;
	int count_down;
	Game_Object* object_ptrs[10]; 
	int num_objects;
	Person* person_ptrs[10];
	int num_persons;
	Oxygen_Depot* depot_ptrs[10];
	int num_depots;
	Space_Station* station_ptrs[10];
	int num_stations; 
	Astronaut *a1, *a2;
	Oxygen_Depot *o1, *o2;
	Space_Station *s1, *s2;

}; 


#endif