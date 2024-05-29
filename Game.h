#ifndef GAME_H
#define GAME_H

#include <vector>
#include <cstdlib>
#include "Ship.h"
#include "Mine.h"
#include "Utils.h"

class Game {
private:
    std::vector<GameEntity*> entities;

public:
    std::vector<GameEntity*>& get_entities() {
        return entities;
    }

    void set_entities(const std::vector<GameEntity*>& new_entities) {
        entities = new_entities;
    }

    std::vector<GameEntity*> initGame(int numShips, int numMines, int gridWidth, int gridHeight) {
        entities.clear();
        for (int i = 0; i < numShips; ++i) {
            auto [x, y] = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Ship(x, y));
        }
        for (int i = 0; i < numMines; ++i) {
            auto [x, y] = Utils::generateRandomPos(gridWidth, gridHeight);
            entities.push_back(new Mine(x, y));
        }
        return entities;
    }

    void gameLoop(int maxIterations, double mineDistanceThreshold) {
        for (int iter = 0; iter < maxIterations; ++iter) {
            for (auto entity : entities) {
                if (entity->getType() == 'S') {
                    static_cast<Ship*>(entity)->move(1, 0);
                }
            }

            for (auto entity : entities) {
                if (entity->getType() == 'M') {
                    for (auto other : entities) {
                        if (other->getType() == 'S') {
                            if (Utils::calculateDistance(entity->getPos(), other->getPos()) < mineDistanceThreshold) {
                                Explosion explosion = static_cast<Mine*>(entity)->explode();
                                explosion.apply(*other);
                            }
                        }
                    }
                }
            }

            bool allShipsDestroyed = true;
            for (auto entity : entities) {
                if (entity->getType() == 'S') {
                    allShipsDestroyed = false;
                    break;
                }
            }

            if (allShipsDestroyed) {
                break;
            }
        }
    }

    ~Game() {
        for (auto entity : entities) {
            delete entity;
        }
    }
};

#endif // GAME_H
