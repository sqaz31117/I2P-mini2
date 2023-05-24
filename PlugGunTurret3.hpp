#ifndef PlugGunTurret3_H_INCLUDED
#define PlugGunTurret3_H_INCLUDED
#include "Turret.hpp"

class PlugGunTurret3 : public Turret {
public:
    static const int Price;
    PlugGunTurret3(float x, float y);
    void CreateBullet() override;
};


#endif // PlugGunTurret3_H_INCLUDED
