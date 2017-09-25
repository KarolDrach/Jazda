#pragma once
class Pawn;
class Actor;

class PawnController
{
protected:
	//Pawn* controlled_pawn;
public:
	virtual void Update(float &frame_time) = 0;
	virtual inline bool IsPossesed() = 0;// const { return controlled_pawn != nullptr; }
	virtual bool Possess(Pawn* controlled_pawn) = 0;
	PawnController();
	virtual ~PawnController();
	friend class Pawn;
	friend class Game;
};