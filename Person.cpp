#include <iostream>
#include "Game_Object.h"
#include "Person.h"
#include "math.h"
using namespace std;

Person::Person(){
	speed = 5;
	cout << "Person default constructed" << endl;
}

Person::Person(char in_code){
	speed = 5;
	state = 's';
	display_code = in_code;
	cout << "Person constructed" << endl;
}

Person::Person(Cart_Point in_loc, int in_id, char in_code):Game_Object(in_loc, in_id, in_code){
	speed = 5;
	cout << "Person constructed" << endl;
}

void Person::start_moving(Cart_Point dest){
	setup_destination(dest);
	state = 'm';
	cout << "Moving " << id_num << " to " << dest << endl;
	cout << display_code << id_num << ": On my way!" << endl;
}

void Person::stop(){
	state = 's';
	cout << "Stopping " << display_code << id_num << endl;
}

void Person::show_status(){
	Game_Object::show_status();
}

bool Person::update_location(){

	if ((fabs(destination.x - location.x) <= fabs(delta.x)) && (fabs(destination.y - location.y) <= fabs(delta.y))){
		location.x = destination.x;
		location.y = destination.y;
		cout << display_code << id_num << ": arrived" << endl;
		return true;
	}	
	else{
		location.x = location.x + delta.x;
		location.y = location.y + delta.y;
		cout << display_code << id_num << ": moved" << endl;
		return false;
	}
}

void Person::setup_destination(Cart_Point dest){
	destination = dest;
	delta.x = (destination.x-location.x)*(speed/cart_distance(destination, location));
	delta.y = (destination.y-location.y)*(speed/cart_distance(destination, location));
}

void Person::start_supplying(Oxygen_Depot* inputDepot){
	cout << "Sorry, I can't work a depot" << endl;
}

void Person::start_depositing(Space_Station* inputStation){
	cout << "Sorry, I can't work a station" << endl;
}

void Person::go_to_station(Space_Station* inputStation){
	cout << "Sorry, I can't lock into a station" << endl;
}

Person::~Person(){
	cout << "Person destructed" << endl;
}
