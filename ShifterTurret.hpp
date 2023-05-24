#ifndef SHIFTERTURRET_HPP
#define SHIFTERTURRET_HPP
#include "Turret.hpp"

class ShifterTurret : public Turret {
public:
    static const int Price;
    ShifterTurret(float x, float y);
    void CreateBullet() override;
};
#endif // SHIFTERTURRET_HPP
