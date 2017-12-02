#include <iostream>
#include "Game_Object.h"
#include "Space_Station.h"
using namespace std;

Space_Station::Space_Station(){
	upgrade_count = 0;
	amount_moonstones = 0;
	display_code = 's';
	state = 'o';
	number_astronauts = 0;
	Cart_Point p1 (0,0);
	location = p1;
	id_num = 1;
	cout << "Space_Station default constructed" << endl;
}

Space_Station::Space_Station(Cart_Point inputLoc, int inputId){
	upgrade_count = 0;
	id_num = inputId;
	location = inputLoc;
	amount_moonstones = 0;
	display_code = 's';
	state = 'o';
	number_astronauts = 0;
	cout << "Space_Station constructed" << endl;
}

void Space_Station::deposit_moonstones (double deposit_amount){
	amount_moonstones = amount_moonstones + deposit_amount;
}

bool Space_Station::add_astronaut(){
	if (state == 'u'){
		number_astronauts++;
		return true;
	}
	else return false;
}

int Space_Station::get_astronauts(){
	return number_astronauts;
}

bool Space_Station::update(){
	if ((amount_moonstones >= 10) && (upgrade_count == 0)){
		upgrade_count++;
		state = 'u';
		display_code = 'S';
		cout << display_code << id_num << " has been upgraded" << endl;
		return true;
	}
	return false;
}

void Space_Station::show_status(){
	cout << "Space Station Status: ";
	Game_Object::show_status();
	cout << " contains " << amount_moonstones << " moon stones and contains " << number_astronauts << " astronauts" << endl;
}

Space_Station::~Space_Station(){
	cout << "Space Station destructed" << endl;
}