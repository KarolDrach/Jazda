#pragma once
#include "Vector2D.h"
#include <string>

class Actor
{
protected:
	float rotation;
	Vector2D<> position;
public:
	Actor();
	Actor(float rotation, Vector2D<> position);
	inline virtual void SetPosition(Vector2D<> &position) { this->position = position; }
	inline void SetRotation(float &value) { this->rotation = value; }
	inline void Move(Vector2D<> &vector) { this->position.Add(vector); }
	inline virtual void Update(float &frame_time) {}
	inline virtual void Draw() = 0;
	inline float GetRotation() { return rotation; }
	inline Vector2D<> GetPosition() { return position; }
	virtual ~Actor();
};

