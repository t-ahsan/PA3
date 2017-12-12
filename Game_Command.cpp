#include <iostream>
#include "Model.h"
#include "Game_Command.h"
#include "Cart_Point.h"
#include "Input_Handling.h"
using namespace std;

void do_move_command(Model& model){
	int id, x, y;
	if (id > 9 || id < 0){
		throw Invalid_Input("Not a valid id number, re-enter command");
	}
	char type;
	cin >> id >> x >> y;
	cout << "Specify whether you would like to move an Alien(x) or Astronaut(a): ";
	cin >> type;
	Cart_Point newlocation(x,y);
	if (type == 'a'){
		Person* a = model.get_Person_ptr(id);
		if (a == 0)
			throw Invalid_Input("Invalid ID number entered, re enter command");
		a->start_moving(newlocation);
	}
	else if (type == 'x'){
		Alien* x = model.get_Alien_ptr(id);
		if (x == 0)
			throw Invalid_Input("Invalid ID number entered, re enter command");
		x->start_moving(newlocation);
	}
	else{
		throw Invalid_Input("Not a valid type to move, re enter command");
	}
}

void do_work_command(Model& model){
	int id1, id2; 
	cin >> id1 >> id2; 
	Person * a = model.get_Person_ptr(id1);
	Oxygen_Depot* o = model.get_Oxygen_Depot_ptr(id2);
	if (a == 0 || o == 0)
		throw Invalid_Input("Invalid ID number entered, re enter command");
	a->start_supplying(o);
}

void do_deposit_command(Model& model){
	int id1, id2; 
	cin >> id1 >> id2;
	Person* a = model.get_Person_ptr(id1);
	Space_Station* s = model.get_Space_Station_ptr(id2);
	if (a == 0 || s == 0)
		throw Invalid_Input("Invalid ID number entered, re enter command");
	a->start_depositing(s);
}

void do_stop_command(Model& model){
	int id;
	char type;
	cin >> id;
	cout << "Specify whether you would like to stop an Alien(x) or Astronaut(a): ";
	cin >> type;
	if (type == 'a'){
		Person* a = model.get_Person_ptr(id);
		if (a == 0)
			throw Invalid_Input("Invalid ID number entered, re enter command");
		a->stop();
	}
	else if (type == 'x'){
		Alien* x = model.get_Alien_ptr(id);
		if (x == 0)
			throw Invalid_Input("Invalid ID number entered, re enter command");
		x ->stop();
	}
	else{
		throw Invalid_Input("Not a valid type to stop, re enter command");
	}
}

void do_lock_command(Model& model){
	int id1, id2; 
	cin >> id1 >> id2; 
	Person* a = model.get_Person_ptr(id1);
	Space_Station* s = model.get_Space_Station_ptr(id2);
	if (a == 0 || s == 0)
		throw Invalid_Input("Invalid ID number entered, re enter command");
	a->go_to_station(s);
}

void do_go_command(Model& model){
	cout << "Advancing one tick" << endl;
	model.update();
	do_output_command(model);
}

void do_run_command(Model& model){
	cout << "Advancing to next event" << endl;
	bool updated;
	for (int i = 0; i < 5; i++){
		updated = model.update();
		if (updated){
			do_output_command(model);
			break;
		}
	}
}

void do_quit_command(Model& model){
	cout << "Terminating Program" << endl;
}

void do_output_command(Model &model){
  model.show_status();
}

void do_attack_command(Model &model){
	int id1, id2; 
	cin >> id1 >> id2;
	Alien* x = model.get_Alien_ptr(id1);
	Person* a = model.get_Person_ptr(id2);
	if (x == 0 || a == 0)
		throw Invalid_Input("Invalid ID number entered, re enter command");
	x->start_attack(a);
}

void do_new_command(Model &model){
	char type;
	int id, x, y;
	cin >> type >> id >> x >> y;
	if (type == 'a'){
		if (model.get_Person_ptr(id) == 0)
			model.make_new_object(type, id, Cart_Point(x, y));
		else throw Invalid_Input("A Person with this ID number exists, re enter command");
	}
	else if (type == 'x'){
		if (model.get_Alien_ptr(id) == 0)
			model.make_new_object(type, id, Cart_Point(x, y));
		else throw Invalid_Input("An Alien with this ID number exists, re enter command");
	}
	else if (type == 'd'){
		if (model.get_Oxygen_Depot_ptr(id) == 0)
			model.make_new_object(type, id, Cart_Point(x, y));
		else throw Invalid_Input("A Depot with this ID number exists, re enter command");
	}
	else if (type == 's'){
		if (model.get_Space_Station_ptr(id) == 0)
			model.make_new_object(type, id, Cart_Point(x, y));
		else throw Invalid_Input("A Station with this ID number exists, re enter command");
	}
	else throw Invalid_Input("Invalid Object chosen to create, re enter command");
}
