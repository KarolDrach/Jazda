//#include "Vector2D.h"
//#include <cmath>
//
//template<typename Type = DEFAULT_TYPE>
//inline Vector2D<Type> Vector2D<Type>::Add(Vector2D<Type> &added)
//{
//	return Vector2D();
//}
//
//template<typename Type = DEFAULT_TYPE>
//inline void Vector2D<Type>::MultiplyByScalar(Type value)
//{
//	this->first = this->first * value;
//	this->second = this->second * value;
//}
//
//template<typename Type = DEFAULT_TYPE>
//inline Type Vector2D<Type>::CalculateLength()
//{
//	return dynamic_cast<Type>(sqrt(this->first * this->first + this->second * this->second));
//}
//
//template<typename Type = DEFAULT_TYPE>
//inline Type Vector2D<Type>::CalculateDistance(Vector2D<Type> &other)
//{
//	return Type();
//}
//
//template<typename Type = DEFAULT_TYPE>
//inline bool Vector2D<Type>::Compare(Vector2D<Type> &other)
//{
//	return ((this->first == other->first) && (this->second == other->second));
//}
//
//template<typename Type = DEFAULT_TYPE>
//inline Vector2D<Type>::Vector2D(): first(static_cast<Type>(0)),
//					        second(static_cast<Type>(0))
//{
//}
//
//template<typename Type>
//inline Vector2D<Type>::Vector2D(Type first, Type second)
//{
//	this->first = first;
//	this->second = second;
//}
//
//template<typename Type = DEFAULT_TYPE>
//inline Vector2D<Type>::~Vector2D()
//{
//}