#include <iostream>
#include <string>
#include "Cart_Vector.h"
#include "Cart_Point.h"
#include "Game_Object.h"
#include "Astronaut.h"
#include "Oxygen_Depot.h"
#include "Game_Command.h"
#include "Space_Station.h"
#include "Model.h"
#include "View.h"
#include "Person.h"
using namespace std;

int main()
{
  char input = 'o';
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2017" << endl;
  cout << "Programming Assignment 3" << endl;
  Model model;
  View view;


  while(input != 'q')
  {
    switch(input)
    {
      case 'm': 
        do_move_command(model);
        break;
      case 'w':
        do_work_command(model);
        break;
      case 's':
        do_stop_command(model);
        break;
      case 'l':
        do_lock_command(model);
        break;
      case 'g':
        do_go_command(model);
        break;
      case 'r':
        do_run_command(model);
        break;
      case 'o':
        do_output_command(model);
        break;
      case 'q':
        do_quit_command(model);
        break;
    }
    model.display(view);
    cout << "Enter command: ";
    cin >> input; 
  }

  return 0;

}
