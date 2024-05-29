#include <iostream>
#include "Game.h"

int main() {
    Game game;
    game.initGame(3, 2, 10, 10);
    
    for (auto entity : game.get_entities()) {
        std::cout << "Entity Type: " << entity->getType() << ", Position: (" 
                  << std::get<0>(entity->getPos()) << ", " << std::get<1>(entity->getPos()) << ")\n";
    }

    game.gameLoop(10, 2.0);

    std::cout << "After game loop:\n";
    for (auto entity : game.get_entities()) {
        std::cout << "Entity Type: " << entity->getType() << ", Position: (" 
                  << std::get<0>(entity->getPos()) << ", " << std::get<1>(entity->getPos()) << ")\n";
    }

    return 0;
}
