#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "AudioHelper.hpp"
#include "CircularBullet.hpp"
#include "Group.hpp"
#include "CircularTurret.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "LOG.hpp"

const int CircularTurret::Price = 50;
int CircularTurret::BulletNum = 0;
CircularTurret::CircularTurret(float x, float y) :
    // TODO 3 (1/5): You can imitate the 2 files: 'PlugGunTurret.hpp', 'PlugGunTurret.cpp' to create a new turret.
    Turret("play/tower-base.png", "play/turret-3.png", x, y, 100, Price, 1.5) {
    // Move center downward, since we the turret head is slightly biased upward
    Anchor.y += 8.0f / GetBitmapHeight();
    BulletNum = 0;
}
void CircularTurret::CreateBullet() {

    Engine::Point diff = Engine::Point(0,0);
    // Change bullet position to the front of the gun barrel.
        for (int i = 1; i <= 4; i++) {
            float rotation = 2.0 * ALLEGRO_PI / 4.0 * (float)i;
            Engine::Point position;
            position.x = Position.x + 50.0 * cos(rotation);
            position.y = Position.y + 50.0 * sin(rotation);
            getPlayScene()->BulletGroup->AddNewObject(new CircularBullet(position, Position, rotation, this));
            CircularTurret::BulletNum = 4;
        }
}

void CircularTurret::Update(float deltaTime){
    Sprite::Update(deltaTime);
	PlayScene* scene = getPlayScene();
	imgBase.Position = Position;
	imgBase.Tint = Tint;
	if (!Enabled) {
        BulletNum = -1;
        return;
	}
	if (BulletNum <= 0) {
        CreateBullet();
	}
}
