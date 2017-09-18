#include "PawnController.h"

bool PawnController::Possess(Pawn* controlled_pawn)
{
	if (!this->controlled_pawn)
	{
		this->controlled_pawn = controlled_pawn;
		return true;
	}
	return false;
}

PawnController::PawnController()
{
}


PawnController::~PawnController()
{
}


// OLD_
//#include "PawnController.h"
//
//bool PawnController::Possess(Pawn * owner)
//{
//	if (!this->owner)
//	{
//		this->owner = owner;
//		return true;
//	}
//	return false;
//}
//
//PawnController::PawnController()
//{
//}
//
//
//PawnController::~PawnController()
//{
//}
