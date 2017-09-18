#pragma once
#include <vector>
#include <memory>
#include "Actor.h"

class Level
{
	std::vector<Actor*> all_actors;
public:
	std::vector<Actor*>& GetAllActors() { return all_actors; }
	std::vector<Actor*> GetActorsInDistanceFromPoint(Vector2D<> point, float distance);
	void AddActor(Actor* actor);
	void RemoveActor(Actor* actor);
	bool Exist(Actor* actor) const;
	void ClearAllActors();
	void UpdateAll(float &frame_time);
	void DrawAll(float &frame_time) const;
	Level();
	~Level();
};

