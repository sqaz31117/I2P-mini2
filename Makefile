# Makefile for Windows
CXX = g++
CXXFLAGS = -std=c++11 -IC:\allegro\include -O2
LDFLAGS = -lm -Wall -Wextra
LDLIBS = -LC:\allegro\lib -lallegro_monolith.dll
exe = TowerDefense.exe
obj = Allegro5Exception.o AudioHelper.o Bullet.o Collider.o DirtyEffect.o Enemy.o ExplosionEffect.o GameEngine.o Group.o IControl.o IObject.o IScene.o Image.o ImageButton.o LOG.o Label.o LoseScene.o Plane.o PlayScene.o PlugGunTurret.o PlugGunTurret2.o Point.o RedNormalEnemy.o GreenNormalEnemy.o Resources.o ShootEffect.o Slider.o Sprite.o StageSelectScene.o StartScene.o SettingScene.o Turret.o TurretButton.o WinScene.o WoodBullet.o FireBullet.o main.o
.PHONY: all clean

all: $(obj)
	$(CXX) -o $(exe) $(obj) $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	del $(exe) $(obj)