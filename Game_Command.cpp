#include <iostream>
#include "Model.h"
#include "Game_Command.h"
#include "Cart_Point.h"
using namespace std;

void do_move_command(Model& model){
	int id, x, y;
	cin >> id >> x >> y;
	Cart_Point newlocation(x,y);
	Person* a = model.get_Person_ptr(id);
	a->start_moving(newlocation);
}

void do_work_command(Model& model){
	int id1, id2; 
	cin >> id1 >> id2; 
	Person * a = model.get_Person_ptr(id1);
	Oxygen_Depot* o = model.get_Oxygen_Depot_ptr(id2);
	a->start_supplying(o);
}

void do_deposit_command(Model& model){
	int id1, id2; 
	cin >> id1 >> id2;
	Person* a = model.get_Person_ptr(id1);
	Space_Station* s = model.get_Space_Station_ptr(id2);
	a->start_depositing(s);
}

void do_stop_command(Model& model){
	int id;
	cin >> id;
	Person* a = model.get_Person_ptr(id);
	a->stop();
}

void do_lock_command(Model& model){
	int id1, id2; 
	cin >> id1 >> id2; 
	Person* a = model.get_Person_ptr(id1);
	Space_Station* s = model.get_Space_Station_ptr(id2);
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

void do_output_command(Model &model)
{
  model.show_status();
}
