#include "Character.h"
#include "Game.h"
#include "TextureManager.h"
#include "CharacterController.h"

void Character::Draw()
{
	Game::Instance().GetMainWindow().draw(outfit);
}

Character::Character(PawnController* controller, float rotation, Vector2D<> position):
	Pawn(controller, rotation, position)
{
	Pawn::SetOutfit(std::string("T_RIGHT"));
	movement_speed = 600;
}

Character::~Character()
{
}
