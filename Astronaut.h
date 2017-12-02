#ifndef ASTRONAUT_H
#define ASTRONAUT_H
#include <iostream>
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Person.h"
using namespace std;


class Astronaut : public Person{

public:	

	Astronaut();
	Astronaut(int in_id, Cart_Point in_loc);
	bool update();
	void start_supplying(Oxygen_Depot* inputDepot);
	void start_depositing(Space_Station* inputStation);
	void go_to_station(Space_Station* inputStation);
	void show_status();
	~Astronaut();

private:

	double amount_moonstones;
	double amount_oxygen;
	Oxygen_Depot* depot;
	Space_Station* home;

}; 


#endif