#pragma once
#include "PawnController.h"
class Character;

class CharacterController : public PawnController
{
private:
	//Character* controlled_pawn; 
public:
	virtual void Update(float &frame_time) override;
	CharacterController();
	~CharacterController();
};

