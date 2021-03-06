#include "Projectile.h"
#include "Game.h"

void Projectile::Draw()
{
	Game::Instance().GetMainWindow().draw(outfit);
}

Projectile::Projectile(float rotation, Vector2D<>position):
	Pawn(rotation, position)
{
	Pawn::SetOutfit(std::string("FIREBALL"));
	movement_speed = 1000;
}

Projectile::~Projectile()
{
}
