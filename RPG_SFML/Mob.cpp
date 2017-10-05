#include "Mob.h"
#include "Game.h"
#include "TextureManager.h"
#include "CharacterController.h"

void Mob::Draw()
{
	Game::Instance().GetMainWindow().draw(outfit);
}

Mob::Mob(float rotation, Vector2D<> position) :
	Pawn(rotation, position)
{
	can_be_picked_up = false;
	Pawn::SetOutfit(std::string("T_RIGHT"));
	movement_speed = 150;
}

Mob::~Mob()
{
}
