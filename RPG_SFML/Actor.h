#pragma once
#include "Vector2D.h"
#include <string>

class Actor
{
protected:
	float rotation;
	Vector2D<> position;
	bool can_be_picked_up;
public:
	Actor();
	Actor(float rotation, Vector2D<> position);
	inline bool CanBePickedUp() { return can_be_picked_up; }
	inline virtual void SetPosition(Vector2D<> &position) { this->position = position; }
	inline void SetRotation(float &value) { this->rotation = value; }
	inline void Move(Vector2D<> &vector) { this->position.Add(vector); }
	inline virtual void Update(float &frame_time) {}
	inline virtual void Draw() = 0;
	inline float GetRotation() { return rotation; }
	inline Vector2D<> GetPosition() { return position; }
	virtual ~Actor();
};

