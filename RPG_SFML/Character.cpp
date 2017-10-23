#include "Character.h"
#include "Game.h"
#include "TextureManager.h"
#include "CharacterController.h"

void Character::Draw()
{
	Game::Instance().GetMainWindow().draw(outfit);
}

Character::Character(float rotation, Vector2D<> position):
	Pawn(rotation, position)
{
	can_be_picked_up = false;
	Pawn::SetOutfit(std::string("T_RIGHT"));
	movement_speed = 600;
	fire_rate_reload = 0.0;
	picking_items_reload = 0.0;
}

Character::~Character()
{
}
