#include <iostream>
#include "game.h"

int main() {
    std::cout << "\n\n**Blacjack Trainer**\nHow many iterations?: ";
    long int it;
    std::cin >> it;
    std::cout << "new data? [(N)/y]: ";
    char ans;
    std::cin >> ans;
    if (ans == 'y' || ans == 'Y') {
	run_game(it, true);
    }
    else {
	run_game(it);
    }
    return 0;
}
