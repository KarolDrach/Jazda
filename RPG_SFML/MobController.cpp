#include "MobController.h"
#include "Mob.h" 
#include "Game.h"
#include "Pawn.h"
#include <memory>
#include <iostream>

void MobController::Update(float & frame_time)
{
	auto &actors = Game::Instance().GetCurrentLevel().GetAllActors();
	Actor* closest_actor = nullptr;
	float min_distance = 99999.0;
	
	for (auto actor : actors)
	{
		if (actor != this->controlled_pawn)
		{
			auto act_dist = this->controlled_pawn->GetPosition().CalculateDistance(actor->GetPosition());
			if (act_dist < min_distance)
			{
				min_distance = act_dist;
				closest_actor = actor;
			}
		}	
	}

	if (closest_actor)
	{
		float dist = this->controlled_pawn->GetPosition().CalculateDistance(closest_actor->GetPosition());
		if (dist > 100.0 && dist < 400.0)
		{
			auto angle = controlled_pawn->GetPosition().CalculateAngleRad(closest_actor->GetPosition());
			auto x = cos(angle) * controlled_pawn->GetMovementSpeed();
			auto y = sin(angle) * controlled_pawn->GetMovementSpeed();

			controlled_pawn->Pawn::Move(Vector2D<>(x * frame_time, y * frame_time));
		}
	}
}

bool MobController::Possess(Pawn * controlled_pawn)
{
	if (!this->controlled_pawn)
	{
		this->controlled_pawn = static_cast<Mob*>(controlled_pawn);
		return true;
	}
	return false;
}

inline bool MobController::IsPossesed()
{
	return controlled_pawn != nullptr;
}

MobController::MobController()
{
}


MobController::~MobController()
{
}
