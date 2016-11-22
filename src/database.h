// Saving and Loading the game state
#include <iostream>
#include <string>
#ifndef DATABASE_H
#define DATABASE_H
const string load_path = "~/blackjack/database/";
class Database {
 private:
 public:
  Database(){};
  ~Database(){};
 
     void load(string filename);
     void save(int state [21][11]);
     void save(int state[21][11], string filename);
}
#endif
