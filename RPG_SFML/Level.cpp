#include "Level.h"
#include <iostream>
#include <vector>

std::vector<Actor*> Level::GetActorsInDistanceFromPoint(Vector2D<> point, float distance)
{
	std::vector<Actor*> result;
	for (auto& actor : all_actors)
	{
		if (actor->GetPosition().CalculateDistance(point) <= distance)
		{
			result.push_back(actor);
		}
	}
	
	return result;
}

std::vector<Actor*> Level::GetActorsInDistanceFromActor(Actor * actor, float distance)
{
	std::vector<Actor*> result;
	auto position = actor->GetPosition();

	for (auto& a : all_actors)
	{
		if (a->GetPosition().CalculateDistance(position) <= distance && a != actor)
		{
			result.push_back(a);
		}
	}

	return result;
}

Actor * Level::GetClosestActorToPoint(Vector2D<> point)
{
	auto min_dist = 9999999999.0;
	Actor* closest;
	for (auto& actor : all_actors)
	{
		if (actor->GetPosition().CalculateDistance(point) <= min_dist)
		{
			closest = actor;
		}
	}
	return closest;
}

Actor * Level::GetClosestActorToActor(Actor * actor)
{
	auto min_dist = 9999999999.0;
	auto position = actor->GetPosition();
	Actor* closest = nullptr;

	for (auto& a : all_actors)
	{
		if ((a->GetPosition().CalculateDistance(position) <= min_dist) && (actor != a))
		{
			closest = a;
		}
	}
	return closest;
}

void Level::AddActor(Actor* actor)
{
	if (actor)
	{
		if (!Exist(actor))
		{
			std::cout << "DODALEM" << std::endl;
			(this->all_actors).push_back(actor);		
		}
		else
		{
			std::cout << "NIE DODA" << std::endl;
		}
	}
}

void Level::RemoveActor(Actor* actor)
{
	if (Exist(actor))
	{
		auto DelActor = std::find(all_actors.begin(), all_actors.end(), actor);
		if (DelActor != all_actors.end())
		{
			all_actors.erase(DelActor);
		}
	}
}

bool Level::Exist(Actor* actor) const
{
	if (actor)
	{
		auto SeekActor = std::find(all_actors.begin(), all_actors.end(), actor);
		if (SeekActor != all_actors.end())
		{
			return true;
		}
	}
	
	return false;
}

void Level::ClearAllActors()
{
	for (auto actor : all_actors)
		delete actor;
}

void Level::UpdateAll(float & frame_time)
{
	int cnt = 0;
	for (auto actor : all_actors)
	{
		if (actor)
			actor->Update(frame_time);
		cnt++;
	}

	auto iter = all_actors.begin();
	while (iter != all_actors.end())
	{
		if ((*iter)->GetPosition().GetFirst() > 1980 || (*iter)->GetPosition().GetFirst() < 0 ||
			(*iter)->GetPosition().GetSecond() > 1080 || (*iter)->GetPosition().GetSecond() < 0)
			iter = all_actors.erase(iter);
		else
			iter++;
	}
	
	//std::cout << "E " << cnt << std::endl;
}

void Level::DrawAll(float & frame_time) const
{
	for (auto actor : all_actors)
	{
		if(actor)
			actor->Draw();
	}	
}

Level::Level()
{
}

Level::~Level()
{
}