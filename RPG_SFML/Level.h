#pragma once
#include <vector>
#include <memory>
#include "Actor.h"

class Level
{
	typedef std::shared_ptr<Actor> actSmartPtr;
	std::vector<actSmartPtr> all_actors;
public:
	std::vector<actSmartPtr>& GetAllActors() { return all_actors; }
	std::vector<actSmartPtr> GetActorsInDistanceFromPoint(Vector2D<> point, float distance);
	std::vector<actSmartPtr> GetActorsInDistanceFromActor(actSmartPtr actor, float distance);
	actSmartPtr GetClosestActorToPoint(Vector2D<> point);
	actSmartPtr GetClosestActorToActor(actSmartPtr actor);

	void AddActor(actSmartPtr actor);
	void RemoveActor(actSmartPtr actor);
	bool Exist(actSmartPtr actor) const;
//	std::vector<Actor*> all_actors;
//public:
//	std::vector<Actor*>& GetAllActors() { return all_actors; }
//	std::vector<Actor*> GetActorsInDistanceFromPoint(Vector2D<> point, float distance);
//	std::vector<Actor*> GetActorsInDistanceFromActor(Actor* actor, float distance);
//	Actor* GetClosestActorToPoint(Vector2D<> point);
//	Actor* GetClosestActorToActor(Actor* actor);
//
//	void AddActor(Actor* actor);
//	void RemoveActor(Actor* actor);
//	bool Exist(Actor* actor) const;
	void ClearAllActors();
	void UpdateAll(float &frame_time);
	void DrawAll(float &frame_time) const;
	Level();
	~Level();
};

