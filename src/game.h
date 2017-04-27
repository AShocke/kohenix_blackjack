#ifndef TRAINING_H
#define TRAINING_H
#include <string>
const int BLACKJACK = 21;
const std::string STAY_FILE = "STAY.DND";
const std::string HIT_FILE = "HIT.DND";
void run_game(long int count, bool new_data = false); // returns number of succesful games played
#endif

