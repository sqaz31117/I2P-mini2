#ifndef CIRCULARTURRET_H_INCLUDED
#define CIRCULARTURRET_H_INCLUDED
#include "Turret.hpp"

class CircularTurret : public Turret {
public:
    static const int Price;
    static int BulletNum;
    CircularTurret(float x, float y);
    void CreateBullet() override;
    virtual void Update(float deltaTime) override;
};


#endif // CIRCULARTURRET_H_INCLUDED
