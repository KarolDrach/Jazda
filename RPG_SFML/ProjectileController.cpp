#include "ProjectileController.h"
#include "Projectile.h"
#include "Pawn.h"
#include <memory>
#include <cmath>

void ProjectileController::Update(float & frame_time)
{
	auto angle = controlled_pawn->GetRotation();
	auto x = cos(angle) * controlled_pawn->GetMovementSpeed();
	auto y = sin(angle) * controlled_pawn->GetMovementSpeed();

	controlled_pawn->Pawn::Move(Vector2D<>(x * frame_time, y * frame_time));
}

bool ProjectileController::Possess(std::shared_ptr<Pawn> controlled_pawn)
{
	if (!this->controlled_pawn)
	{
		this->controlled_pawn = std::static_pointer_cast<Projectile>(controlled_pawn);
		return true;
	}
	return false;
}

inline bool ProjectileController::IsPossesed()
{
	return controlled_pawn != nullptr;
}

ProjectileController::ProjectileController()
{
}


ProjectileController::~ProjectileController()
{
}
