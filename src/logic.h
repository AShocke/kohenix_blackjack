#include <iostream>
#ifndef LOGIC_H
#define LOGIC_H

class Logic {
private:
  int hit_[21][11] = { {100} };
  int stay_[21][11] = { {100} };
public:
  void update_odds(int p, int b, bool did_win);
  bool hit_or_stay(int p, int b);
  void compare(int p1, int b2, int p2, int b2); 
  void load();
}
#endif
  
