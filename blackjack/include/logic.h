#include <iostream>
#include <vector>
#ifndef LOGIC_H
#define LOGIC_H

class Logic {
private:
  int hit_[21][11] =  { {0} } ;
  int stay_[21][11] =  { {0} } ;
  const std::string DEFAULT_STAY_FILE = "stay.dat";
  const std::string DEFAULT_HIT_FILE = "hit.dat";
public:
    Logic(bool new_data = false);
    Logic(std::string stay_file, std::string hit_file);
    ~Logic(){};
    void update_odds(int p, int b, bool did_win, bool did_hit);
    bool hit_or_stay();
    bool hit_or_stay(int p, int b);
    void compare(int p1, int b1, int p2, int b2);
    void load();
    void load(std::string stay_file, std::string hit_file);
    void save(bool pretty_on = false);
    void save(std::string stay_file, std::string hit_file,
              bool pretty_on = false);
    void print();
};
#endif
  
