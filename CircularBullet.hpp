#ifndef CIRCULARBULLET_H_INCLUDED
#define CIRCULARBULLET_H_INCLUDED
#include "Bullet.hpp"

class Enemy;
class Turret;
namespace Engine {
    struct Point;
}  // namespace Engine

class CircularBullet : public Bullet {
private:
    Engine::Point Tower_Position;
    float Phi;
public:
    static int Now_Time;
    explicit CircularBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent);
    void OnExplode(Enemy* enemy) override;
    void Update(float deltaTime) override;
};


#endif // CIRCULARBULLET_H_INCLUDED
