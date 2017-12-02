#ifndef OXYGENDEPOT_H
#define OXYGENDEPOT_H
#include <iostream>
#include "Game_Object.h"
using namespace std;

class Oxygen_Depot : public Game_Object{

private:

	double amount_oxygen;
	int update_count;

public:	

	Oxygen_Depot();
	Oxygen_Depot(Cart_Point inputLoc, int inputId);
	bool is_empty();
	double extract_oxygen(double amount_to_extract = 20.0);
	bool update();
	void show_status();
	~Oxygen_Depot();

}; 


#endif