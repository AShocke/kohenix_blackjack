/* Author: Aisosa Efemwonkieke
 */
#include <iostream>
#include <fstream>
#include "../include/database.h"

void Database::save(int state[21][11]) {
    std::ofstream o(DEFAULT_PATH.c_str(), std::ios::out);
    if (o.is_open()) {
	for (int x = 0; x < 21; x++) {
	    for (int y = 0; y < 11; y++) {
		o << x << " " << y << " " << state[x][y] << "\n";
	    }
	}
	std::cout << "File was saved succesfully\n";
    } 
    else { 
	std::cout << "Error: Could not open file \'" << DEFAULT_PATH << "' for writing.\n";
	return;
    }
    o.close();
}

void Database::save(int state[21][11], std::string filename) {
    std::string filepath = LOAD_DIRECTORY + filename;
    std::ofstream o;
    o.open(filepath);
    if (o.is_open()) {
	for (int x = 0; x < 21; x++) {
	    for (int y = 0; y < 11; y++) {
		o << x << " " << y << " " << state[x][y] << "\n";
	    }
	}
	std::cout << filepath << " was saved succesfully\n";
    }
    else { 
	std::cout << "Error: Could not open file \'" << filepath << "' for writing.\n";
	return;
    }
    o.close();

}

void Database::save_pretty(int state[21][11]) {
    std::ofstream o;
    o.open(DEFAULT_PATH);
    if (o.is_open()) {
	for (int c = 1; c <= 11; c++) {
	    o << "\t" << c;
	}
	o << "\n\n";
	for (int x = 0; x < 21; x++) {
	    o << (x + 1);
	    for (int y = 0; y < 11; y++) {
		o << "\t" << state[x][y]; 
	    }
	    o << "\n\n";
	}
	std::cout << "File was saved succesfully\n";
    }
    else { 
	std::cout << "Error: Could not open file '" << DEFAULT_PATH << "' for writing.\n";
	return;
    }
    o.close();

}

void Database::save_pretty(int state[21][11], std::string filename) {
    std::string filepath = LOAD_DIRECTORY + filename;
    std::ofstream o;
    o.open(filepath);
    if (o.is_open()) {
	for (int c = 1; c <= 11; c++) {
	    o << "\t" << c;
	}
	o << "\n\n";
	for (int x = 0; x < 21; x++) {
	    o << (x + 1);
	    for (int y = 0; y < 11; y++) {
		o << "\t" << state[x][y]; 
	    }
	    o << "\n\n";
	}
	std::cout << filepath << "  was saved succesfully\n";
	o.close();
    } else {
	std::cout << "Error: Loading from file '" << filepath << "'for writing.\n"; 
    }
    o.close();
}   

void Database::load(int state[21][11]) {
    std::ifstream o;
    o.open(DEFAULT_PATH);
    if (o.is_open()) {
	for (int x = 0; x < 21; x++) {
	    for (int y = 0; y < 11; y++) {
		int p, b, v;
		o >> p >> b >> v;
		state[p][b] = v;
	    }
	}
    } else {
	std::cout << "Error: Loading from file '" << DEFAULT_PATH << "'for writing.\n"; 
    }

    o.close();
}

void Database::load(int state[21][11], std::string filename) {
    std::string filepath = LOAD_DIRECTORY + filename;
    std::ifstream o;
    o.open(filepath);
    if (o.is_open()) {
	for (int x = 0; x < 21; x++) {
	    for (int y = 0; y < 11; y++) {
		int p, b, v;
		o >> p >> b >> v;
		state[p][b] = v;
	    }
	}
    }
    else {
	std::cout << "Error: Loading from file '" << filepath << "'for writing.\n"; 
    }

    o.close();
}

