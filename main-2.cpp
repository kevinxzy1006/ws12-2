#include <iostream>
#include "Ship.h"
#include "Mine.h"
#include "Explosion.h"

int main() {
    Ship ship(5, 5);
    std::cout << "Ship initial position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";
    ship.move(1, 1);
    std::cout << "Ship new position: (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << ")\n";

    Mine mine(7, 7);
    std::cout << "Mine position: (" << std::get<0>(mine.getPos()) << ", " << std::get<1>(mine.getPos()) << ")\n";

    Explosion explosion = mine.explode();
    std::cout << "Mine exploded. New mine type: " << mine.getType() << "\n";
    
    explosion.apply(ship);
    std::cout << "Ship after explosion: Position (" << std::get<0>(ship.getPos()) << ", " << std::get<1>(ship.getPos()) << "), Type: " << ship.getType() << "\n";

    return 0;
}
