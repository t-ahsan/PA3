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
#include "Alien.h"
#include "Person.h"
#include "Input_Handling.h"
using namespace std;

int main()
{
  char input;
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2017" << endl;
  cout << "Programming Assignment 3" << endl;
  Model model;
  View view;

  do_output_command(model);
  model.display(view);

  while(input != 'q')
  {
    try{

    cout << "Enter command: ";
    cin >> input;
    

    if ((input != 'q') && (input != 'm') && (input != 'w') && (input != 's') && (input != 'l') && (input != 'g') && (input != 'd') && (input != 'r') && (input != 'o') && (input != 'a') && (input != 'n')){
      throw Invalid_Input("Not a valid command"); 
    }
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
        case 'd':
          do_deposit_command(model);
          break;
        case 'r':
          do_run_command(model);
          break;
        case 'o':
          do_output_command(model);
          break;
        case 'a':
          do_attack_command(model);
          break;
        case 'n':
          do_new_command(model);
          break;
      }
    }
    catch (Invalid_Input& except){
      cout << "Invalid input - " << except.msg_ptr << endl;
      continue;
    }

    model.display(view);
  }

  do_quit_command(model);
  return 0;

}
