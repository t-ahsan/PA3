#include <iostream>
#include "Game_Object.h"
#include "Oxygen_Depot.h"
using namespace std;

Oxygen_Depot::Oxygen_Depot(){
	amount_oxygen = 50;
	update_count = 0;
	display_code = 'O';
	state = 'f';
	cout << "Oxygen_Depot default constructed" << endl;
}

Oxygen_Depot::Oxygen_Depot(Cart_Point inputLoc, int inputId){
	amount_oxygen = 50;
	update_count = 0;
	display_code = 'O';
	state = 'f';
	id_num = inputId;
	location = inputLoc;
}

bool Oxygen_Depot::is_empty(){
	if (amount_oxygen == 0)
		return true;
	else return false;
}

double Oxygen_Depot::extract_oxygen(double amount_to_extract){
	if (amount_oxygen >= amount_to_extract){
		amount_oxygen = amount_oxygen - amount_to_extract;
		return amount_to_extract;
	}
	else{
		double temp = amount_oxygen;
		amount_oxygen = 0;
		return temp;
	}

}

bool Oxygen_Depot::update(){
	if (amount_oxygen == 0 && update_count == 0){
		update_count++;
		state = 'e';
		display_code = 'o';
		cout << "Oxygen_Depot " << id_num << " has been depleted" << endl;
		return true;
	}
	else return false;
}

void Oxygen_Depot::show_status(){
	cout << "Oxygen Depot Status: " << display_code << id_num << " at location " << location << " contains " << amount_oxygen << endl;
}

Oxygen_Depot::~Oxygen_Depot(){
	cout << "Oxygen Depot destructed" << endl;
}