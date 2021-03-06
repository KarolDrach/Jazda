#include <memory>
#include <iostream>
#include "Pawn.h"
#include "PawnController.h"
#include "TextureManager.h"

Pawn::Pawn(float rotation, Vector2D<> position) :
			Actor(rotation, position)
{
	direction = LEFT;
	can_be_picked_up = false;
}

void Pawn::Update(float & frame_time)
{
	if (this->controller)
		(this->controller)->Update(frame_time);
}

inline void Pawn::SetPosition(Vector2D<>& position)
{
	Actor::SetPosition(position);
	outfit.setPosition((this->position).GetFirst(), (this->position).GetSecond());
}

void Pawn::SetOutfit(std::string outfit_name)
{
	auto texture_to_load = TextureManager::GetTexture(outfit_name);
	if (texture_to_load != nullptr)
	{
		outfit.setTexture(*texture_to_load);
		auto x = texture_to_load->getSize().x;
		auto y = texture_to_load->getSize().y;
		outfit.setOrigin(x/2, y);
		outfit.setPosition(position.GetFirst(), position.GetSecond());
	}
}

void Pawn::SetController(std::shared_ptr<PawnController> controller)
{
	this->controller = controller;
	this->controller->Possess(std::enable_shared_from_this<Pawn>::shared_from_this());
}

void Pawn::Move(Vector2D<>& vector)
{
	Actor::Move(vector);
	outfit.setPosition((this->position).GetFirst(), (this->position).GetSecond());
}

Pawn::~Pawn()
{
	/*if (this->controller)
		delete controller;*/
}

void Pawn::Draw()
{
}

Pawn::Pawn()
{
	can_be_picked_up = false;
}



//OLD_
//
//#include "Pawn.h"
//
//Pawn::Pawn(PawnController * controller) : controller(nullptr)
//{
//	if (controller && controller->Possess(this))
//	{
//		this->controller = controller;
//	}
//}
//
//void Pawn::SetController(PawnController * controller)
//{
//	if (controller != this->controller)
//	{
//		if (controller && controller->Possess(this))
//			this->controller = controller;
//		else
//			this->controller = nullptr;
//	}
//}
//
//void Pawn::Update(float & frame_time)
//{
//	if (this->controller)
//		(this->controller)->Update(frame_time);
//}
//
//Pawn::~Pawn()
//{
//	if (this->controller)
//		delete controller;
//}