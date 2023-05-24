#include <allegro5/base.h>
#include <random>
#include <string>
#include <cmath>

#include "Bullet.hpp"
#include "Collider.hpp"
#include "Enemy.hpp"
#include "GameEngine.hpp"
#include "Group.hpp"
#include "IObject.hpp"
#include "IScene.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"
#include "Sprite.hpp"
#include "Turret.hpp"
#include "CircularTurret.hpp"

#include "DirtyEffect.hpp"
//#include "Enemy.hpp"
#include "CircularBullet.hpp"
//#include "Group.hpp"
//#include "PlayScene.hpp"
//#include "Point.hpp"
#include "LOG.hpp"

class Turret;

int CircularBullet::Now_Time = 0;
CircularBullet::CircularBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
    Bullet("play/bullet-7.png", 300, 2, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {
    Tower_Position = forwardDirection;
    Phi = rotation;
    //Engine::LOG(Engine::INFO) << ""
    // TODO 3 (2/5): You can imitate the 2 files: 'WoodBullet.hpp', 'WoodBullet.cpp' to create a new bullet.
}
void CircularBullet::OnExplode(Enemy* enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-3.png", dist(rng), enemy->Position.x, enemy->Position.y));
    CircularTurret::BulletNum--;
}

void CircularBullet::Update(float deltaTime){
	// Can be improved by Spatial Hash, Quad Tree, ...
	// However simply loop through all enemies is enough for this program.
	if (parent->GetObjectIterator()->first == false) {
        if (this->GetObjectIterator()->first = true) {
            this->GetObjectIterator()->first = false;
            getPlayScene()->BulletGroup->RemoveObject(this->GetObjectIterator());
        }
        return;
	}
	Now_Time++;
	Position.x = Tower_Position.x + 100.0 * cos(((float)Now_Time*0.005 + Phi));
	Position.y = Tower_Position.y + 100.0 * sin(((float)Now_Time*0.005 + Phi));
	//Sprite::Update(deltaTime);
	// Engine::LOG(Engine::INFO) << deltaTime;
	//Engine::LOG(Engine::INFO) << "(" << Position.x << "," << Position.y << ")";

	PlayScene* scene = getPlayScene();
	for (auto& it : scene->EnemyGroup->GetObjects()) {
		Enemy* enemy = dynamic_cast<Enemy*>(it);
		if (!enemy->Visible)
			continue;
		if (Engine::Collider::IsCircleOverlap(Position, CollisionRadius, enemy->Position, enemy->CollisionRadius)) {
			OnExplode(enemy);
			enemy->Hit(damage);

			getPlayScene()->BulletGroup->RemoveObject(objectIterator);
			return;
		}
	}
}
