#include "Level.h"
#include <iostream>
#include <vector>

typedef std::shared_ptr<Actor> actSmartPtr;

std::vector<actSmartPtr> Level::GetActorsInDistanceFromPoint(Vector2D<> point, float distance)
{
	std::vector<actSmartPtr> result;
	for (auto& actor : all_actors)
	{
		if (actor->GetPosition().CalculateDistance(point) <= distance)
		{
			result.push_back(actor);
		}
	}
	
	return result;
}

std::vector<actSmartPtr> Level::GetActorsInDistanceFromActor(actSmartPtr actor, float distance)
{
	std::vector<actSmartPtr> result;
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

actSmartPtr Level::GetClosestActorToPoint(Vector2D<> point)
{
	auto min_dist = 9999999999.0;
	actSmartPtr closest;
	for (auto& actor : all_actors)
	{
		if (actor->GetPosition().CalculateDistance(point) <= min_dist)
		{
			closest = actor;
		}
	}
	return closest;
}

actSmartPtr Level::GetClosestActorToActor(actSmartPtr actor)
{
	auto min_dist = 9999999999.0;
	auto position = actor->GetPosition();
	actSmartPtr closest = nullptr;

	for (auto& a : all_actors)
	{
		if ((a->GetPosition().CalculateDistance(position) <= min_dist) && (actor != a))
		{
			closest = a;
		}
	}
	return closest;
}

void Level::AddActor(actSmartPtr actor)
{
	if (actor)
	{
		if (!Exist(actor))
		{
			std::cout << "DODALEM ACTORA DO LEVELU Level::AddActor(...)\n" << std::endl;
			(this->all_actors).push_back(actor);		
		}
		else
		{
			std::cout << "NIE DODALEM\n " << std::endl;
		}
	}
}

void Level::RemoveActor(actSmartPtr actor)
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

bool Level::Exist(actSmartPtr actor) const
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
	/*for (auto actor : all_actors)
		all_actors.erase(actor);*/
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
	this->all_actors.reserve(100);
}

Level::~Level()
{
}