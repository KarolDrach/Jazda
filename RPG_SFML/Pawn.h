#pragma once
#include <memory>
#include "Actor.h"
#include "Game_Status.h"
#include <SFML/Graphics.hpp>

class PawnController;

class Pawn : public Actor, public std::enable_shared_from_this<Pawn>
{
protected:
	ActorDirection direction;
	float movement_speed;
	std::shared_ptr<PawnController> controller;
	sf::Sprite outfit;
public:
	float reload;

	void Move(Vector2D<> &vector);
	inline virtual void SetPosition(Vector2D<> &position) override;
	inline void SetDirection(ActorDirection direction) { this->direction = direction; }
	void SetOutfit(std::string outfit_name);
	void SetController(std::shared_ptr<PawnController> controller);
	inline sf::Sprite GetOutfit() { return outfit; }
	inline float GetMovementSpeed() { return movement_speed; }
	PawnController& GetPawnController() { return *controller; }
	ActorDirection GetDirection() { return direction; }
	explicit Pawn();
	explicit Pawn(const std::shared_ptr<PawnController>& controller, float rotation, Vector2D<> position);
	virtual void Update(float &frame_time) override;
	virtual void Draw() override;
	virtual ~Pawn() override;
	friend class PawnController;
};