#include <iostream>
#include "../logic.h"

const std::string STAY_TEST = "stay.test";
const std::string HIT_TEST = "hit.test";
int main() {
    Logic l;
    l.save(STAY_TEST, HIT_TEST, true);
    std::cout << "Done\n";
}

