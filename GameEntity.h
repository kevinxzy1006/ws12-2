#ifndef GAMEENTITY_H
#define GAMEENTITY_H

#include <tuple>

class GameEntity {
protected:
    std::tuple<int, int> position;
    char type;

public:
    GameEntity(int x, int y, char type) : position(std::make_tuple(x, y)), type(type) {}

    std::tuple<int, int> getPos() const {
        return position;
    }

    char getType() const {
        return type;
    }
};

#endif // GAMEENTITY_H
