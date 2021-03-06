#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <random>
#include "logic.h"
#include "database.h"
/*
 * The ai's main source of decision is from an array which is accessed by the dealers shown hand
 * and the ai's current hand. This array decides whether the ai will hit or stay.
 * If the ai won after hitting, then it will add one point to the weights.
 */
Logic::Logic(bool new_data, bool d) {
    debug = d;
    if (new_data) {
        for (int x = 0; x < 21; x++) {
            for (int y = 0; y < 11; y++) {
                stay_[x][y] = 50;
                hit_[x][y] = 50;
            }
        }
    }
    else {
        load();
    }
}
Logic::Logic(std::string stay_file, std::string hit_file, bool d) {
    debug = d;
    load(stay_file, hit_file);
    print();
}

void Logic::print() {
    std::cout << "\tSTAY\t\n\n";
    for (int c = 1; c <= 11; c++) {
	std::cout << "\t" << c;
	}
    std::cout << "\n\n";
	for (int x = 0; x < 21; x++) {
	    std::cout << (x + 1);
	    for (int y = 0; y < 11; y++) {
		std::cout << "\t" << stay_[x][y]; 
	    }
	    std::cout << "\n\n";
	}
	std::cout << "\n\nHIT\t\n\n";
	for (int c = 1; c <= 11; c++) {
	    std::cout << "\t" << c;
	}
	std::cout << "\n\n";
	for (int x = 0; x < 21; x++) {
	    std::cout << (x + 1);
	    for (int y = 0; y < 11; y++) {
		std::cout << "\t" << hit_[x][y]; 
	    }
	    std::cout << "\n\n";
	}
}


void Logic::update_odds(int p, int b, bool did_win, bool did_hit) {
  if (did_hit) {
   if(did_win) {
       hit_[p][b]++;
       stay_[p][b]--;
    }
  }
  else {
    if(did_win) {
      stay_[p][b]++;
      hit_[p][b]--;
    }
  }
}

/* 
 * using the stay and hit odds to calculate whether to hit or not
 */
bool Logic::hit_or_stay(int p, int d) {
    int stay_odds = stay_[p][d];
    //std::cout << stay_odds << "\n";
    int hit_odds = hit_[p][d];
    //std::cout << hit_odds << "\n";
    int sum_of_odds = stay_odds + hit_odds;
    //std::cout << "sum_of_odds: " << sum_of_odds << "\n";
    std::random_device gen;
    std::mt19937 rng(gen());
    std::uniform_int_distribution<int> ran(0, sum_of_odds);
    int r = ran(rng);
    //std::cout << "r: " <<  r << "\n";
    if (r > stay_odds) {
        if (debug) {std::cout << "HIT!\n";}
        return true;
    }
    if (debug) {std::cout << "STAY!\n";}
    return false;
}

void Logic::load() {
    Database dat;
    dat.load(stay_, DEFAULT_STAY_FILE );
    dat.load(hit_, DEFAULT_HIT_FILE);
}
void Logic::load(std::string stay_file, std::string hit_file) {
    Database dat;
    dat.load(stay_, stay_file);
    dat.load(hit_, hit_file);
}

void Logic::save(bool pretty_on) {
    Database dat;
    dat.save(stay_, DEFAULT_STAY_FILE); 
    dat.save(hit_, DEFAULT_HIT_FILE);
    if (pretty_on) {
	std::string stay_pretty = "pretty_" + DEFAULT_STAY_FILE;
	std::string hit_pretty = "pretty_" + DEFAULT_HIT_FILE;
	dat.save_pretty(stay_, stay_pretty);
	dat.save_pretty(hit_, hit_pretty);
    }
}
void Logic::save(std::string stay_file, std::string hit_file, bool pretty_on) {
    Database dat;
    std::string stay_pretty = "pretty_" + stay_file;
    std::string hit_pretty = "pretty_" + hit_file;
    dat.save(stay_, stay_file); 
    dat.save(hit_, hit_file);
    if (pretty_on) {
	dat.save_pretty(stay_, stay_pretty);
	dat.save_pretty(hit_, hit_pretty);
    }
}
