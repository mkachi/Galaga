#pragma once

#include "../framework/Sprite.h"
#include "../framework/Scene.h"

enum class EnemyState
{
	Die,
	SpawnAction,
	Idle,
};

enum class Direction 
{ 
	Left, Right 
};

class Enemy
{
private:
	Sprite*		_sprite;
	Vector2		_position;
	Direction	_direction;
	EnemyState	_state;

	// Enemy가 스폰될 때 X좌표의 값이 도착지점보다 큰가?
	bool		_spawnBigX;

	void spawnAction(Timer& timer);
	void idleAction(Timer& timer);

public:
	Enemy(Scene* scene, Vector2 position, Direction direction);
	~Enemy();

	void setState(EnemyState state);
	EnemyState getState() { return _state; }

	void update(Timer& timer);

};