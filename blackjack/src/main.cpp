#include <iostream>
#include "../include/training.h"

int main() {
    std::cout << "**Blacjack Trainer**\nHow many iterations?: ";
    long long int it;
    std::cin >> it;
    std::cout << "new data? [(N)/y]: ";
    char ans;
    std::cin >> ans;
    if (ans == 'y' || ans == 'Y') {

    }
    run_game(it);
    return 0;
}
