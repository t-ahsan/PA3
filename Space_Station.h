#ifndef SPACESTATION_H
#define SPACESTATION_H
#include <iostream>
#include "Game_Object.h"
using namespace std;

class Space_Station : public Game_Object{

private:

	double amount_moonstones;
	int number_astronauts;
	int upgrade_count;

public:	

	Space_Station();
	Space_Station(Cart_Point inputLoc, int inputId);
	void deposit_moonstones (double deposit_amount);
	bool add_astronaut();
	int get_astronauts();
	bool update();
	void show_status();
	~Space_Station();

}; 


#endif