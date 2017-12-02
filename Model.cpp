#include <iostream>
#include "Astronaut.h"
#include "Person.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Cart_Point.h"
#include "Model.h"
#include "View.h"
#include <stdlib.h>
using namespace std;

Model::Model(){
	time = 0;
	count_down = 10;
	num_objects = 5;
	num_persons = 2;
	num_depots = 2;
	num_stations = 2;
	Cart_Point p1(5, 1);
	Cart_Point p2(10, 1);
	Cart_Point p3(1, 20);
	Cart_Point p4(10, 20);
	Cart_Point p5(5, 5);
	a1 = new Astronaut(1, p1);
	object_ptrs[0] = a1;
	person_ptrs[0] = a1;
	a2 = new Astronaut(2, p2);
	object_ptrs[1] = a2;
	person_ptrs[1] = a2;
	o1 = new Oxygen_Depot(p3, 1);
	object_ptrs[2] = o1;
	depot_ptrs[0] = o1;
	o2 = new Oxygen_Depot(p4, 2);
	object_ptrs[3] = o2;
	depot_ptrs[1] = o2;
	s1 = new Space_Station();
	object_ptrs[4] = s1;
	station_ptrs[0] = s1;
	s2 = new Space_Station(p5, 2);
	object_ptrs[5] = s2;
	station_ptrs[1] = s2;
	cout << "Model default constructed" << endl;
}

Person* Model::get_Person_ptr(int id){
	bool found;
	Person* p;
	for (int i = 0; i < 2; i++){
		if (person_ptrs[i]->get_id() == id){
			found = true;
			p = person_ptrs[i];
		}
	}
	if (found == true)
		return p;
	else return 0;
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id){
	bool found;
	Oxygen_Depot* o;
	for (int i = 0; i < 2; i++){
		if (depot_ptrs[i]->get_id() == id){
			found = true;
			o = depot_ptrs[i];
		}
	}
	if (found == true)
		return o;
	else return 0;
}

Space_Station* Model::get_Space_Station_ptr(int id){
	bool found;
	Space_Station* s;
	for (int i = 0; i < 2; i++){
		if (station_ptrs[i]->get_id() == id){
			found = true;
			s = station_ptrs[i];
		}
	}
	if (found == true)
		return s;
	else return 0;
}

bool Model::update(){
	time++;
	bool change, win;	
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	for (int i = 0; i < 2; i++){
		if (station_ptrs[i]->get_state() == 'u')
			count1++;
		if (person_ptrs[i]->get_state() == 'l')
			count2++;		
	}
	if (count1 == 2){
		if (count2 == 2)
			win = true;
		else count_down--;
	}

	if ((win == true) || (count_down == 0)){
		exit(0);
	}

	for (int i = 0; i < 6; i++){
		change = object_ptrs[i]->update();
		if (change)
			return true;
		else return false;
	}	

}

void Model::display(View &view){
	cout << "Time: " << time << endl;
	view.clear();
	for (int i = 0; i < 6; i++){
		view.plot(object_ptrs[i]);
	}
	view.draw();
}

void Model::show_status(){
	cout << "Time: " << time << endl;
	for (int i = 0; i < 6; i++){
		object_ptrs[i]->show_status();
	}
}

Model::~Model(){
	delete a1;
	delete a2;
	delete o1;
	delete o2;
	delete s1;
	delete s2;
	cout << "Model destructed" << endl;
 }
