#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "FireBullet.hpp"
#include "Group.hpp"
#include "PlugGunTurret3.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

const int PlugGunTurret3::Price = 80;
PlugGunTurret3::PlugGunTurret3(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-2.png", x, y, 250, Price, 2.0) {
        // Turret(std::string imgBase, std::string imgTurret, float x, float y, float radius, int price, float coolDown)
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
}
void PlugGunTurret3::CreateBullet() {
    Engine::Point diff = Engine::Point(cos(Rotation - ALLEGRO_PI / 2), sin(Rotation - ALLEGRO_PI / 2));
    float rotation = atan2(diff.y, diff.x);
    Engine::Point normalized = diff.Normalize();
    // Change bullet position to the front of the gun barrel.
    Engine::Point tmp = Position;
    tmp.x -= 8;
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(tmp + normalized * 36, diff, rotation, this));
    tmp.x += 14;
    getPlayScene()->BulletGroup->AddNewObject(new FireBullet(tmp + normalized * 36, diff, rotation, this));
    // getPlayScene()->BulletGroup->AddNewObject(new FireBullet(Position + normalized * 36, diff, rotation, this));
    // TODO 4 (2/2): Add a ShootEffect here. Remember you need to include the class.
    AudioHelper::PlayAudio("gun.wav");
}
