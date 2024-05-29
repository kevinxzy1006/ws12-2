#ifndef EFFECT_H
#define EFFECT_H

#include "GameEntity.h"

class Effect {
public:
    virtual void apply(GameEntity& entity) = 0;
    virtual ~Effect() = default;
};

#endif // EFFECT_H
