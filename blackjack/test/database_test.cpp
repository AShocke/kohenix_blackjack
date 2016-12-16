#include <iostream>
#include "../include/logic.h"

const std::string STAY_TEST = "stay.test";
const std::string HIT_TEST = "hit.test";
int main() {
    Logic l(true);
    l.save(STAY_TEST, HIT_TEST, true);
    l.save();
    std::cout << "Done\n";
}

