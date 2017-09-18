#pragma once
class Pawn;
class Actor;

class PawnController
{
protected:
	Pawn* controlled_pawn;
public:
	virtual void Update(float &frame_time) = 0;
	inline bool IsPossesed() const { return controlled_pawn != nullptr; }
	bool Possess(Pawn* controlled_pawn);
	PawnController();
	virtual ~PawnController();
	friend class Pawn;
	friend class Game;
};