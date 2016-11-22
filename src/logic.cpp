#include <iostream>
#include "database.h";
#include "logic.h";

void Logic::update_odds(int p, int b, bool did_win, bool did_hit) {
  if (did_hit) {
   if(did_win) {
      hit_[p][b]++;
    }
  }
  else {
    if(did_win) {
      stay_[p][b]++;
    }
  }
}

bool Logic::hit_or_stay(int p, int b) {
  int stay_odds = stay_[p][b];
  int hit_odds = hit_[p][b];
  int median = (stay_odds + hit_odds) / 2;
  int r = (math.ran() % 100);
  if (r > median) {
    return false;
  }
  return true;
}

void Logic::load() {

}
