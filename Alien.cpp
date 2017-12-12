#include <iostream>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Game_Object.h"
#include "Person.h"
#include "Alien.h"
#include "math.h"
using namespace std;

Alien::Alien():Game_Object('X'){
	state = 's';
	attack_strength = 2;
	range = 2.0;
	target = NULL;
	speed = 5;
	cout << "Default alien constructed" << endl;
}

Alien::Alien(int in_id, Cart_Point in_loc):Game_Object(in_loc, in_id, 'X'){
	state = 's';
	attack_strength = 2;
	range = 2.0;
	target = NULL;
	speed = 5;
	cout << "Default alien constructed" << endl;
}

void Alien::start_attack(Person* in_target){
	Cart_Point tar_loc = in_target->get_location();
	if ((fabs(tar_loc.x - location.x) <= range) && (fabs(tar_loc.y - location.y) <= range)){
		target = in_target;
		target->take_hit(attack_strength);
		cout << "SMASH!!" << endl;
		state = 'a';
	}

	else cout << "Target is out of range :(" << endl;
}

bool Alien::update_location(){
	if ((fabs(destination.x - location.x) <= fabs(delta.x)) && (fabs(destination.y - location.y) <= fabs(delta.y))){
		location.x = destination.x;
		location.y = destination.y;
		cout << display_code << id_num << ": arrived" << endl;
		return true;
	}	
	else{
		location.x = location.x + delta.x;
		location.y = location.y + delta.y;
		cout << display_code << id_num << ": moved to " << location << endl;
		return false;
	}
}

void Alien::setup_destination(Cart_Point dest){
	this ->destination = dest;
	delta.x = (destination.x-location.x)*(speed/cart_distance(destination, location));
	delta.y = (destination.y-location.y)*(speed/cart_distance(destination, location));
}

void Alien::start_moving(Cart_Point dest){
	this ->setup_destination(dest);
	state = 'm';
	cout << "Moving " << id_num << " to " << dest << endl;
	cout << display_code << id_num << ": On my way!" << endl;
}

void Alien::stop(){
	state = 's';
	cout << "Stopping " << display_code << id_num << endl;
}

bool Alien::update(){
	bool arrived;
	switch(state){
		case 's':
			return false;
			break;
		case 'm':
			arrived = this -> update_location();			
			if (arrived == true){
				state = 's';
				return true;
			}
			else return false;
			break;
		case 'a':
			Cart_Point tar_loc = target ->get_location();
			if ((fabs(tar_loc.x - location.x) <= range) && (fabs(tar_loc.y - location.y) <= range)){
				if (target->get_state() == 'x'){
					cout << "I have triumphed!!" << endl;
					state = 's';
					return true;
				}
				else{
					cout << "DESTROY!!" << endl;
					target->take_hit(attack_strength);
					return false;
				}
			}
			else{
				cout << "Target is out of range :(" << endl;
				state = 's';
				return true;
			}
			break;
	}
}

void Alien::show_status(){
	cout << "Alien Status: ";
	Game_Object::show_status();
	switch(state){
		case 's':
			cout << " is stopped" << endl;
			break;
		case 'm':
			cout << " moving with speed " << speed << " to " << destination << " at each step of " << delta << endl;
			break;
		case 'a':
			cout << " is attacking the target" << endl;
			break;
	}
}

Alien::~Alien(){
	cout << "Alien destructed" << endl;
}