#include <iostream>
#include "Astronaut.h"
#include "Person.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "math.h"
using namespace std;

Astronaut::Astronaut():Person('A'){
	amount_moonstones = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;
	cout << "Astronaut default constructed" << endl;
}

Astronaut::Astronaut(int in_id, Cart_Point in_loc):Person(in_loc, in_id, 'A'){
	amount_moonstones = 0;
	amount_oxygen = 20;
	depot = NULL;
	home = NULL;
	cout << "Astronaut constructed" << endl;
}

bool Astronaut::update(){
	bool arrived;
	switch(state){
		case 's':
			return false;
			break;
		case 'm':
			arrived = update_location();			
			if (arrived == true){
				state = 's';
				return true;
			}
			else{
				amount_moonstones++;
				amount_oxygen--;
				return false;
			}
			break;
		case 'o':
			arrived = update_location();
			if (arrived == true){
				state = 'g';
				return true;
			}
			else return false;
			break;		
		case 'g':
			depot->extract_oxygen();
			state = 's';
			return true;
			break;
		case 'i':
			arrived = update_location();
			if (arrived == true){
				state = 'd';
				return true;
			}
			else return false;
			break;	
		case 'd':
			home->deposit_moonstones(amount_moonstones);
			amount_moonstones = 0;
			break;
		case 'l':
			arrived = update_location();
			if (arrived == true){
				home->add_astronaut();
				return true;
			}
			else return false;
			break;	
	}
}

void Astronaut::start_supplying(Oxygen_Depot* inputDepot){
	depot = inputDepot;
	setup_destination(depot->get_location());
	state = 'o';
	cout << "Astronaut " << id_num << "supplying from Oxygen_Depot " << depot->get_id() << endl;
	cout << display_code << id_num << " Yes, my Lord." << endl;
}

void Astronaut::start_depositing(Space_Station* inputStation){
	home = inputStation;
	setup_destination(home->get_location());
	state = 'i';
	cout << "Astronaut " << id_num << "depositing from Space_Station " << home->get_id() << endl;
	cout << display_code << id_num << " Yes, my Lord." << endl;
}

void Astronaut::go_to_station(Space_Station* inputStation){
	home = inputStation;
	setup_destination(home->get_location());
	cout << "Astronaut " << id_num << " locking into Space_Station " << home->get_id() << endl;

}

void Astronaut::show_status(){
	cout << "Astronaunt status: ";
	Person::show_status();
	switch(state){
		case 's':
			cout << " is stopped with " << amount_oxygen << " oxygen and " << amount_moonstones << " moonstones" << endl;
			break;
		case 'm':
			cout << " moving with speed " << speed << " to " << destination << " at each step of " << delta << endl;
			break;
		case 'o':
			cout << " is outbound to a Depot with " << amount_oxygen << " oxygen and " << amount_moonstones << " moonstones" << endl;
			break;		
		case 'g':
			cout << " getting oxygen from Depot" << endl;
			break;
		case 'i':
			cout << " is inbound to a Home with load " << amount_moonstones << " and " << amount_oxygen << " oxygen" << endl;
			break;	
		case 'd':
			cout << " depositing " << amount_moonstones << "moonstones" << endl;
			break;
		case 'l':
			if (amount_oxygen == 0)
				cout << " out of oxygen" << endl;
			else cout << " is locked at Space Station" << endl;
			break;	
	}

}

Astronaut::~Astronaut(){
	cout << "Astronaut destructed" << endl;
}





