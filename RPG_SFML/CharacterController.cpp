#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "CharacterController.h"
#include "Character.h"
#include "Projectile.h"
#include "ItemInstanceInInv.h"
#include "ItemInstanceOnMap.h"
#include "ProjectileController.h"
#include "Game.h"
#include "Level.h"

using namespace std;

void CharacterController::Update(float & frame_time)
{
	auto movement_speed = controlled_pawn->GetMovementSpeed();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (controlled_pawn->GetDirection() != UP)
		{
			controlled_pawn->SetDirection(UP);
			//controlled_pawn->SetOutfit(std::string("T_UP"));
		}
		controlled_pawn->Move(Vector2D<>(0.0, -movement_speed * frame_time));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (controlled_pawn->GetDirection() != DOWN)
		{
			controlled_pawn->SetDirection(DOWN);
			//controlled_pawn->SetOutfit(std::string("T_DOWN"));
		}
		controlled_pawn->Pawn::Move(Vector2D<>(0.0, movement_speed * frame_time));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (controlled_pawn->GetDirection() != LEFT)
		{
			controlled_pawn->SetDirection(LEFT);
			controlled_pawn->SetOutfit(std::string("T_LEFT"));
		}
		controlled_pawn->Pawn::Move(Vector2D<>(-movement_speed * frame_time, 0.0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (controlled_pawn->GetDirection() != RIGHT)
		{
			controlled_pawn->SetDirection(RIGHT);
			controlled_pawn->SetOutfit(std::string("T_RIGHT"));
		}
		controlled_pawn->Pawn::Move(Vector2D<>(movement_speed * frame_time, 0.0));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		auto point = controlled_pawn->GetPosition();
		auto to_pick_up = Game::Instance().GetCurrentLevel().GetClosestActorToActor(this->controlled_pawn);
		if (to_pick_up)
		{
			to_pick_up = std::static_pointer_cast<Pawn>(to_pick_up);

			if (to_pick_up->CanBePickedUp())
			{
				controlled_pawn->GetInventory().AddItemToInventory(ItemInstanceInInv(to_pick_up));
				Game::Instance().GetCurrentLevel().RemoveActor(to_pick_up);
			}
		}
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && controlled_pawn->reload <= 0.0)
	{
		auto x = controlled_pawn->GetPosition().GetFirst();
		auto y = controlled_pawn->GetPosition().GetSecond();
		auto cursor_pos_original = sf::Mouse::getPosition(Game::Instance().GetMainWindow());
		auto cursor_pos_fixed = Game::Instance().GetMainWindow().mapPixelToCoords(cursor_pos_original);
		auto cursor_x = cursor_pos_fixed.x;
		auto cursor_y = cursor_pos_fixed.y;
		auto cursor_pos_final = Vector2D<float>(cursor_x, cursor_y);

		float rotation = this->controlled_pawn->GetPosition().CalculateAngleRad(cursor_pos_final);

		auto projectile = std::make_shared<Projectile>(rotation, Vector2D<>(x, y));
		projectile->SetController(std::make_shared<ProjectileController>());
		Game::Instance().GetCurrentLevel().AddActor(projectile);
		controlled_pawn->reload = 0.05;
	}
}

bool CharacterController::Possess(std::shared_ptr<Pawn> controlled_pawn)
{	
	if (!this->controlled_pawn)
	{
		std::cout << "PASS CHARACTER ";
		this->controlled_pawn = std::static_pointer_cast<Character>(controlled_pawn);
		if (this->controlled_pawn)
		{
			std::cout << "PASS2 CHARACTER ";
		}
		return true;
	}
	return false;
}

inline bool CharacterController::IsPossesed()
{
	return controlled_pawn != nullptr;
}

CharacterController::CharacterController()
{
	//this->controlled_pawn = static_cast<Character*>(PawnController::controlled_pawn);	
}

CharacterController::~CharacterController()
{
}
