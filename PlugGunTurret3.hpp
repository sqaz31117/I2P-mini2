#ifndef UPGRADEGUNTURRET_H_INCLUDED
#define UPGRADEGUNTURRET_H_INCLUDED
#include "Turret.hpp"

class PlugGunTurret3 : public Turret {
public:
    static const int Price;
    PlugGunTurret3(float x, float y);
    void CreateBullet() override;
};


#endif // UPGRADEGUNTURRET_H_INCLUDED
