#ifndef ALIEN_H
#define ALIEN_H
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Space_Station.h"
#include "Oxygen_Depot.h"
#include "Game_Object.h"


class Alien : public Game_Object{

public:	

	Alien();
	Alien(int in_id, Cart_Point in_loc);
	void start_attack(Person* in_target);
	bool update();
	void show_status();
	void start_moving(Cart_Point dest);
	void stop();
	~Alien();

protected: 

	bool update_location();
	void setup_destination(Cart_Point dest);

private:

	int attack_strength;
	double range;
	Person* target;
	double speed;
	Cart_Point destination;
	Cart_Vector delta;

}; 


#endif