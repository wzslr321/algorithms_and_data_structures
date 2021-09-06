#include <cstdlib>
#include <iostream>

namespace Animals {
enum Animals { chicken, dog, cat, elephant, duck, snake, max_animals };
}

int main() {
    int animalsLegs[Animals::max_animals]{2, 4, 4, 4, 4, 0};

    std::cout << "Elephant has " << animalsLegs[Animals::elephant]
              << " legs. \n";

    return EXIT_SUCCESS;
}
