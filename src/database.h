// Saving and Loading the game state
#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
class Database {
 private:
     const std::string DEFAULT_PATH = "database/database.dat";
    const std::string LOAD_DIRECTORY = "database/";
    bool debug;
 public:
    Database(bool d = false){debug = d;}
    ~Database(){};
    void save(int state [21][11]);
     void save(int state[21][11], std::string filename); 
     /* Note that 'pretty' saving is just for display
      * and is not loaded from.
      */
     void save_pretty(int state[21][11]);
     void save_pretty(int state[21][11], std::string filename);
     void load(int state[21][11]);
     void load(int state[21][11], std::string filename);
};
#endif
