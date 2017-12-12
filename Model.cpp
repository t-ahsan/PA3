#include <iostream>
#include "Astronaut.h"
#include "Person.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Cart_Point.h"
#include "Model.h"
#include "View.h"
#include "Alien.h"
#include <stdlib.h>
using namespace std;

Model::Model(){
	time = 0;
	count_down = 10;

	Cart_Point p1(5, 1);
	Cart_Point p2(10, 1);
	Cart_Point p3(1, 20);
	Cart_Point p4(10, 20);
	Cart_Point p5(5, 5);
	Cart_Point p6(7, 14);
	Cart_Point p7(7, 5);

	a1 = new Astronaut(1, p1);
	object_ptrs.push_back(a1);
	active_ptrs.push_back(a1);
	person_ptrs.push_back(a1);

	a2 = new Astronaut(2, p2);
	object_ptrs.push_back(a2); 
	active_ptrs.push_back(a2);
	person_ptrs.push_back(a2);

	o1 = new Oxygen_Depot(p3, 1);
	object_ptrs.push_back(o1);
	depot_ptrs.push_back(o1);
	active_ptrs.push_back(o1);

	o2 = new Oxygen_Depot(p4, 2);
	object_ptrs.push_back(o2);
	depot_ptrs.push_back(o2);
	active_ptrs.push_back(o2);

	s1 = new Space_Station();
	object_ptrs.push_back(s1);
	station_ptrs.push_back(s1);
	active_ptrs.push_back(s1);

	s2 = new Space_Station(p5, 2);
	object_ptrs.push_back(s2);
	station_ptrs.push_back(s2);
	active_ptrs.push_back(s2);

	x1 = new Alien(1, p6);
	object_ptrs.push_back(x1);
	alien_ptrs.push_back(x1);
	active_ptrs.push_back(x1);

	x2 = new Alien(2, p7);
	object_ptrs.push_back(x2);
	alien_ptrs.push_back(x2);
	active_ptrs.push_back(x2);

	cout << "Model default constructed" << endl;

}

void Model::make_new_object(char type, int id, Cart_Point p){
	if (type == 'a'){
		Astronaut* a = new Astronaut(id, p);
		object_ptrs.push_back(a);
		active_ptrs.push_back(a);
		person_ptrs.push_back(a);
	}
	if (type == 'x'){
		Alien* x = new Alien(id, p);
		object_ptrs.push_back(x);
		active_ptrs.push_back(x);
		alien_ptrs.push_back(x);
	}
	if (type == 'd'){
		Oxygen_Depot* o = new Oxygen_Depot(p, id);
		object_ptrs.push_back(o);
		active_ptrs.push_back(o);
		depot_ptrs.push_back(o);
	}
	if (type == 's'){
		Space_Station* s = new Space_Station(p, id);
		object_ptrs.push_back(s);
		active_ptrs.push_back(s);
		station_ptrs.push_back(s);
	}
}

void Model::make_active_ptr_list(){
	for(list<Game_Object*>::iterator it=active_ptrs.begin(); it != active_ptrs.end(); it++){
		if (!(*it) ->is_alive()){
			active_ptrs.erase(it);
			cout << "Dead Object removed" << endl;
		}
	}
}

Person* Model::get_Person_ptr(int id){
	for (list<Person*>::iterator it=person_ptrs.begin(); it != person_ptrs.end(); it++){
		if ((*it)->get_id() == id){
			return *it;
		}
	}
	return 0;
}

Oxygen_Depot* Model::get_Oxygen_Depot_ptr(int id){
	for (list<Oxygen_Depot*>::iterator it=depot_ptrs.begin(); it != depot_ptrs.end(); it++){
		if ((*it)->get_id() == id){
			return *it;
		}
	}
	return 0;
}

Space_Station* Model::get_Space_Station_ptr(int id){
	for (list<Space_Station*>::iterator it=station_ptrs.begin(); it != station_ptrs.end(); it++){
		if ((*it)->get_id() == id){
			return *it;
		}
	}
	return 0;
}

Alien * Model::get_Alien_ptr(int id){
	for (list<Alien*>::iterator it=alien_ptrs.begin(); it != alien_ptrs.end(); it++){
		if ((*it)->get_id() == id){
			return *it;
		}
	}
	return 0;	
}

bool Model::update(){
	time++;
	make_active_ptr_list();
	bool win;
	int events;	
	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	for (list<Space_Station*>::iterator it=station_ptrs.begin(); it != station_ptrs.end(); it++){
		if ((*it)->get_state() == 'u')
			count1++;
	}

	for (list<Person*>::iterator it=person_ptrs.begin(); it != person_ptrs.end(); it++){
		if ((*it)->get_state() == 'l')
			count2++;	
	}

	if (count1 == station_ptrs.size()){
		if (count2 == person_ptrs.size())
			win = true;
		else count_down--;
	}

	if ((win == true) || (count_down == 0)){
		exit(0);
	}

	for (list<Game_Object*>::iterator it=active_ptrs.begin(); it != active_ptrs.end(); it++)
	{
		if ((*it)->update())
			events++; 
	}
	if (events > 0)
		return true;
	else return false;

}

void Model::display(View &view){
	cout << "Time: " << time << endl;
	view.clear();
	for (list<Game_Object*>::iterator it=active_ptrs.begin(); it != active_ptrs.end(); it++){
			view.plot(*it);
	}
	view.draw();
}

void Model::show_status(){
	cout << "Time: " << time << endl;
	for (list<Game_Object*>::iterator it=object_ptrs.begin(); it != object_ptrs.end(); it++){
		(*it) ->show_status();
	}
}

Model::~Model(){
	for (list<Game_Object*>::iterator it=object_ptrs.begin(); it != object_ptrs.end(); it++){
		delete *it;
	}
	cout << "Model destructed" << endl;
 }
