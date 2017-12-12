#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H
#include "Model.h"

void do_move_command(Model& model);
void do_work_command(Model& model);
void do_deposit_command(Model& model);
void do_stop_command(Model& model);
void do_lock_command(Model& model);
void do_go_command(Model& model);
void do_run_command(Model& model);
void do_quit_command(Model& model);
void do_output_command(Model &model);
void do_attack_command(Model &model);
void do_new_command(Model &model);


#endif