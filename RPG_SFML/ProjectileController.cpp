#include "ProjectileController.h"
#include "Pawn.h"
#include <cmath>

void ProjectileController::Update(float & frame_time)
{
	auto angle = controlled_pawn->GetRotation();
	auto x = cos(angle) * controlled_pawn->GetMovementSpeed();
	auto y = sin(angle) * controlled_pawn->GetMovementSpeed();

	controlled_pawn->Pawn::Move(Vector2D<>(x * frame_time, y * frame_time));
}

ProjectileController::ProjectileController()
{
}


ProjectileController::~ProjectileController()
{
}
