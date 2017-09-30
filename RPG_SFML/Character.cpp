#include "Character.h"
#include "Game.h"
#include "TextureManager.h"
#include "CharacterController.h"

void Character::Draw()
{
	Game::Instance().GetMainWindow().draw(outfit);
}

Character::Character(const std::shared_ptr<PawnController>& controller, float rotation, Vector2D<> position):
	Pawn(controller, rotation, position)
{
	can_be_picked_up = false;
	Pawn::SetOutfit(std::string("T_RIGHT"));
	movement_speed = 600;
	std::cout << "TUTAJ! " << movement_speed << "\n";
}

Character::~Character()
{
}
