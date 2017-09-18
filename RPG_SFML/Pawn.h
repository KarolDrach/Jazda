#pragma once
#include "Actor.h"
#include "Game_Status.h"
#include <SFML/Graphics.hpp>

class PawnController;

class Pawn : public Actor
{
protected:
	ActorDirection direction;
	float movement_speed;
	PawnController* controller;
	sf::Sprite outfit;
public:
	float reload;

	void Move(Vector2D<> &vector);
	inline virtual void SetPosition(Vector2D<> &position) override;
	inline void SetDirection(ActorDirection direction) { this->direction = direction; }
	void SetOutfit(std::string outfit_name);
	inline sf::Sprite GetOutfit() { return outfit; }
	inline float GetMovementSpeed() { return movement_speed; }
	PawnController& GetPawnController() { return *controller; }
	ActorDirection GetDirection() { return direction; }
	explicit Pawn();
	explicit Pawn(PawnController* controller, float rotation, Vector2D<> position);
	virtual void Update(float &frame_time) override;
	virtual void Draw() override;
	virtual ~Pawn() override;
	friend class PawnController;
};