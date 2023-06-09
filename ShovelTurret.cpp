#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "WoodBullet.hpp"
#include "Group.hpp"
#include "ShovelTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "ShootEffect.hpp"

const int ShovelTurret::Price = 0;
ShovelTurret::ShovelTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/target-invalid.png", x, y, 200, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void ShovelTurret::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    getPlayScene()->BulletGroup->AddNewObject(new WoodBullet(Position + normalized * 36, diff, rotation, this));
    getPlayScene()->EffectGroup->AddNewObject(new ShootEffect((Position + normalized * 36).x, (Position + normalized * 36).y));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    AudioHelper::PlayAudio("gun.wav");
}
