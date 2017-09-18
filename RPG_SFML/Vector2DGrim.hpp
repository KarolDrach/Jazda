#pragma once

#include "Definitions.hpp"

	namespace grim
{
	namespace impl
	{
		template <typename T>
		class BaseVector2
		{
		public:
			T x, y;

			BaseVector2();
			
			BaseVector2(const T &xValue, const T &yValue);
		
			template <typename U>
			BaseVector2(const BaseVector2<U> &v);
		
			~BaseVector2() = default;

			void Set(const T &xValue, const T &yValue);

			float Length() const;

			float LengthSquared() const;

			template <typename U>
			float Distance(const BaseVector2<U> & v) const;

			template <typename U>
			float DistanceSquared(const BaseVector2<U> & v) const;

			template <typename U>
			float Dot(const BaseVector2<U> & v) const;

			template <typename U>
			float Cross(const BaseVector2<U> & v) const;

			template <typename U>
			BaseVector2<T> Reflect(const BaseVector2<U> &Normal) const;

			template <typename U>
			BaseVector2<T> & ReflectSelf(const BaseVector2<U> &Normal);

			BaseVector2<T> Normal() const;

			BaseVector2<T> & NormalizeSelf();

			BaseVector2<T> Normalize() const;

			template <typename U>
			inline bool Equals(const BaseVector2<U> &Other, const double EqualityTolerance = Math::Equality::LowTolerance) const
			{
				return (Math::Absolute(static_cast<double>(x) - static_cast<double>(Other.x)) <= EqualityTolerance
					&& Math::Absolute(static_cast<double>(y) - static_cast<double>(Other.y)) <= EqualityTolerance);
			}

			template <typename V, typename U>
			inline static BaseVector2<V> Min(const BaseVector2<V> &MinVec, const BaseVector2<U> &MaxVec)
			{
				return BaseVector2<V>(Math::Min(MinVec.x, MaxVec.x), Math::Min(MinVec.y, MaxVec.y));
			}
			template <typename V, typename U>
			inline static BaseVector2<V> Max(const BaseVector2<V> &MinVec, const BaseVector2<U> &MaxVec)
			{
				return BaseVector2<V>(Math::Max(MinVec.x, MaxVec.x), Math::Max(MinVec.y, MaxVec.y));
			}

			template <typename V, typename U>
			inline static void MinMax(BaseVector2<V> &MinVec, BaseVector2<U> &MaxVec)
			{
				MinVec = BaseVector2<V>::Min(MinVec, MaxVec);
				MaxVec = BaseVector2<U>::Max(MinVec, MaxVec);
			}

			template <typename U>
			inline BaseVector2<U> As() const { return BaseVector2<U>(*this); }

			template <typename U>
			inline BaseVector2<T> & operator = (const BaseVector2<U> &Right) { x = T(Right.x); y = T(Right.y); return *this; }

			////// Operator: Negate
			inline BaseVector2<T> operator - () const { return BaseVector2<T>(-x, -y); }

			////// Operator: Equality test
			template <typename U>
			inline bool operator == (const BaseVector2<U> &Right) const { return Equals(Right); }

			////// Operator: Inequality test
			template <typename U>
			inline bool operator != (const BaseVector2<U> &Right) const { return !Equals(Right); }

			////// Operator: Addition
			
			template <typename U>
			inline BaseVector2<T> operator + (const BaseVector2<U> &Right) const { return BaseVector2<T>(x + T(Right.x), y + T(Right.y)); }

			////// Operator: Subtraction
			template <typename U>
			inline BaseVector2<T> operator - (const BaseVector2<U> &Right) const { return BaseVector2<T>(x - T(Right.x), y - T(Right.y)); }

			////// Operator: Multiplication
			template <typename U>
			inline BaseVector2<T> operator * (const BaseVector2<U> &Right) const { return BaseVector2<T>(x * T(Right.x), y * T(Right.y)); }

			////// Operator: Division
			template <typename U>
			inline BaseVector2<T> operator / (const BaseVector2<U> &Right) const { return BaseVector2<T>(x / T(Right.x), y / T(Right.y)); }

			////// Operator: Addition (to self)
			template <typename U>
			inline BaseVector2<T> & operator += (const BaseVector2<U> &Right) { x += T(Right.x); y += T(Right.y); return *this; }

			////// Operator: Subtraction (from self)
			//// Brief: Subtracts a vector from self
			///////////////////////////////////////////////////////////////
			template <typename U>
			inline BaseVector2<T> & operator -= (const BaseVector2<U> &Right) { x -= T(Right.x); y -= T(Right.y); return *this; }

			////// Operator: Multiplication (self by other)
			template <typename U>
			inline BaseVector2<T> & operator *= (const BaseVector2<U> &Right) { x *= T(Right.x); y *= T(Right.y); return *this; }

			////// Operator: Division (self by other)
			template <typename U>
			inline BaseVector2<T> & operator /= (const BaseVector2<U> &Right) { x /= T(Right.x); y /= T(Right.y); return *this; }

			////// Operator: Addition (scalar to self) (return copy)
			inline BaseVector2<T> operator + (const float &Right) const { return BaseVector2<T>(x + T(Right), y + T(Right)); }

			////// Operator: Subtraction (scalar from self) (return copy)
			inline BaseVector2<T> operator - (const float &Right) const { return BaseVector2<T>(x - T(Right), y - T(Right)); }

			////// Operator: Multiplication (self by scalar) (return copy)
			inline BaseVector2<T> operator * (const float &Right) const { return BaseVector2<T>(x * T(Right), y * T(Right)); }

			////// Operator: Division (self by scalar) (return copy)
			inline BaseVector2<T> operator / (const float &Right) const { return BaseVector2<T>(x / T(Right), y / T(Right)); }


			inline BaseVector2<T> & operator += (const float &Right) { x += T(Right); y += T(Right); return *this; }

			inline BaseVector2<T> & operator -= (const float &Right) { x -= T(Right); y -= T(Right); return *this; }

			inline BaseVector2<T> & operator *= (const float &Right) { x *= T(Right); y *= T(Right); return *this; }

			inline BaseVector2<T> & operator /= (const float &Right) { x /= T(Right); y /= T(Right); return *this; }
		};

		template <typename T>
		BaseVector2<T>::BaseVector2() : x(0), y(0) { }

		template <typename T>
		BaseVector2<T>::BaseVector2(const T &xValue, const T &yValue) : x(xValue), y(yValue) { }

		template <typename T>
		template <typename U>
		BaseVector2<T>::BaseVector2(const BaseVector2<U> & v) : x(static_cast<T>(v.x)), y(static_cast<T>(v.y)) { }

		template <typename T>
		void BaseVector2<T>::Set(const T &xValue, const T &yValue) { x = xValue; y = yValue; }

		template <typename T>
		float BaseVector2<T>::Length() const { return sqrt(static_cast<float>(x * x + y * y)); }

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		float BaseVector2<T>::LengthSquared() const { return x * x + y * y; }

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		template <typename U>
		float BaseVector2<T>::Distance(const BaseVector2<U> & v) const { return sqrt(static_cast<float>((x - T(v.x)) * (x - T(v.x))) + ((y - T(v.y)) * (y - T(v.y)))); }

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		template <typename U>
		float BaseVector2<T>::DistanceSquared(const BaseVector2<U> & v) const { return static_cast<float>((x - T(v.x)) * (x - T(v.x))) + ((y - T(v.y)) * (y - T(v.y))); }

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		template <typename U>
		float BaseVector2<T>::Dot(const BaseVector2<U> & v) const { return x * T(v.x) + y * T(v.y); }

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		template <typename U>
		float BaseVector2<T>::Cross(const BaseVector2<U> & v) const { return x * T(v.y) + y * T(v.x); }

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		template <typename U>
		BaseVector2<T> BaseVector2<T>::Reflect(const BaseVector2<U> &Normal) const
		{
			Normal.Normalize();
			return BaseVector2<T>(*this) - ((Normal.template As<T>() * (Normal.template As<T>().Dot(*this))) * 2.f);
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		template <typename U>
		BaseVector2<T>& BaseVector2<T>::ReflectSelf(const BaseVector2<U> &Normal)
		{
			*this = (Reflect(Normal));
			return *this;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		BaseVector2<T> BaseVector2<T>::Normal() const { return BaseVector2<T>(-y, x); }

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		BaseVector2<T> & BaseVector2<T>::NormalizeSelf()
		{
			if (Length() != 0)
			{
				float length = Length();
				x /= length; y /= length;
				return *this;
			}

			Set(0, 0);
			return *this;
		}

		////////////////////////////////////////////////////////////////////////////////////////////////////
		template <typename T>
		BaseVector2<T> BaseVector2<T>::Normalize() const
		{
			BaseVector2<T> ret = *this;
			if (Length() != 0)
			{
				float length = Length();
				ret.x /= length; ret.y /= length;
				return ret;
			}

			ret.Set(0, 0);
			return ret;
		}
	}
}

