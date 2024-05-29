#include <iostream>
#include "GameEntity.h"
#include "Effect.h"
#include "Utils.h"

int main() {
    std::tuple<int, int> pos1 = Utils::generateRandomPos(10, 10);
    std::tuple<int, int> pos2 = Utils::generateRandomPos(10, 10);

    std::cout << "Position 1: (" << std::get<0>(pos1) << ", " << std::get<1>(pos1) << ")\n";
    std::cout << "Position 2: (" << std::get<0>(pos2) << ", " << std::get<1>(pos2) << ")\n";

    double distance = Utils::calculateDistance(pos1, pos2);
    std::cout << "Distance: " << distance << std::endl;

    return 0;
}
