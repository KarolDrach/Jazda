#include "Actor.h"
#include "Vector2D.h"

Actor::Actor(): rotation(0.0),
				position(Vector2D<float>())
{
}

Actor::Actor(float rotation, Vector2D<> position)
{
	this->SetRotation(rotation);
	this->SetPosition(position);
}

Actor::~Actor()
{
}
