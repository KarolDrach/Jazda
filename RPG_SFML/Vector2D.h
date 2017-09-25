#pragma once
#define M_PI 3.14159265358979323846
#define DEFAULT_TYPE float

template <typename Type = DEFAULT_TYPE>
class Vector2D
{
private:
	Type first, second;
public:
	//Return first paramater of a Vector2D.
	inline Type GetFirst() { return first; } const
	inline Type GetSecond() { return second; } const
	inline void SetFirst(Type value) { first = value; }
	inline void SetSecond(Type value) { second = value; }
	inline void Add(Vector2D<Type> &added);
	inline void MultiplyByScalar(Type &value);
	inline float CalculateLength() const ;
	float CalculateDistance(Vector2D<Type> &other);
	float CalculateAngleRad(Vector2D<Type> &other);
	inline bool Compare(Vector2D<Type> &other) const;
	Vector2D();
	Vector2D(Type first, Type second);
	~Vector2D();
};

template<typename Type = DEFAULT_TYPE>
inline void Vector2D<Type>::Add(Vector2D<Type> &added)
{
	this->first = this->first + added.GetFirst();
	this->second = this->second + added.GetSecond();
}

template<typename Type = DEFAULT_TYPE>
inline void Vector2D<Type>::MultiplyByScalar(Type &value)
{
	this->first = this->first * value;
	this->second = this->second * value;
}

template<typename Type = DEFAULT_TYPE>
inline float Vector2D<Type>::CalculateLength() const
{
	return static_cast<float>(sqrt(this->first * this->first + this->second * this->second));
}

template<typename Type = DEFAULT_TYPE>
inline float Vector2D<Type>::CalculateDistance(Vector2D<Type> &other)
{
	float dist_x, dist_y;
	dist_x = other.GetFirst() - this->GetFirst();
	dist_y = other.GetSecond() - this->GetSecond();
	return sqrt(dist_x * dist_x + dist_y * dist_y);
}

template<typename Type>
inline float Vector2D<Type>::CalculateAngleRad(Vector2D<Type>& other)
{
	auto x = this->GetFirst();
	auto y = this->GetSecond();
	auto second_x = other.GetFirst();
	auto second_y = other.GetSecond();
	auto x_dist_difference = fabs(second_x - x);
	auto y_dist_difference = fabs(second_y - y);

	float rotation;

	if (second_x > x && second_y > y)
	{
		if (x_dist_difference > 0.000001)
			rotation = atan(y_dist_difference / x_dist_difference);
		else
			rotation = 0.5 * M_PI;
	}		
	else
	if (second_x < x && second_y > y)
	{
		if (y_dist_difference > 0.000001)
			rotation = atan(x_dist_difference / y_dist_difference) + (0.5 * M_PI);
		else
			rotation = M_PI;
	}
	else
	if (second_x < x && second_y < y)
	{
		if (x_dist_difference > 0.000001)
			rotation = atan(y_dist_difference / x_dist_difference) + M_PI;
		else
			rotation = 1.5 * M_PI;
	}
	else
	if (second_x > x && second_y < y)
	{
		if (y_dist_difference > 0.000001)
			rotation = atan(x_dist_difference / y_dist_difference) + (1.5 * M_PI);
		else
			rotation = 2.0 * M_PI;
	}

	return rotation;
}

template<typename Type = DEFAULT_TYPE>
inline bool Vector2D<Type>::Compare(Vector2D<Type> &other) const
{
	return ((this->first == other.GetFirst()) && (this->second == other.GetSecond()));
}

template<typename Type = DEFAULT_TYPE>
inline Vector2D<Type>::Vector2D() : first(static_cast<Type>(0)),
									second(static_cast<Type>(0))
{
}

template<typename Type = DEFAULT_TYPE>
inline Vector2D<Type>::Vector2D(Type first, Type second)
{
	this->first = first;
	this->second = second;
}

template<typename Type = DEFAULT_TYPE>
inline Vector2D<Type>::~Vector2D()
{
}
//#include "Vector2D.cpp"
