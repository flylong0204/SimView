/**************************************************
outher: LJ
time: 2015-12-21
use: the Point of 2D
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_POINT2D_H_
#define _PUBLIC_POINT2D_H_

namespace SimView
{
	template<typename T>
	class CPoint2D
	{
	public:
		// 构造函数
		explicit CPoint2D(void);
		explicit CPoint2D(T x, T y);
		explicit CPoint2D(const CPoint2D& other);
		CPoint2D& operator= (const CPoint2D& other);
		// 析构函数
		~CPoint2D(void) { }

	public:
		// == 符号
		inline bool operator==(const CPoint2D& other) const;
		// != 符号
		inline bool operator!=(const CPoint2D& other) const;
		// < 符号
		inline bool operator< (const CPoint2D& other) const;
		// 点乘
		inline T operator* (const CPoint2D& other) const;
		// 叉乘
		inline CPoint2D operator* (const T value) const;
		// *=
		inline CPoint2D& operator*=(const T value) ;
		// /
		inline CPoint2D operator /(const T value) const;
		// /=
		inline CPoint2D& operator /=(const T value);
		// +
		inline CPoint2D operator + (const CPoint2D& other) const;
		// +=
		inline CPoint2D& operator +=(const CPoint2D& other);
		// -
		inline CPoint2D operator - (const CPoint2D& other) const;
		// -=
		inline CPoint2D& operator -=(const CPoint2D& other);
		// - 取反
		inline const CPoint2D operator- () const;
		// 平方根
		T Length(void) const;
		// 平方
		T Length2(void) const;
		// 归一化
		T Normalize(void);

	public:
		T m_tX, m_tY;
	};
	
	template<typename T>
	CPoint2D<T>::CPoint2D(void)
		:m_tX(0), m_tY(0)
	{

	}

	template<typename T>
	CPoint2D<T>::CPoint2D(T x, T y)
		:m_tX(x), m_tY(y)
	{

	}

	template<typename T>
	CPoint2D<T>::CPoint2D(const CPoint2D<T>& other)
		:m_tX(other.m_tX), m_tY(other.m_tY)
	{

	}

	template<typename T>
	CPoint2D<T>& CPoint2D<T>::operator=(const CPoint2D<T>& other)
	{
		m_tX = other.m_tX;
		m_tY = other.m_tY;
		return (*this);
	}

	// ==符号
	template<typename T>
	bool CPoint2D<T>::operator==(const CPoint2D<T>& other) const
	{
		return ((m_tX == other.m_tX) && (m_tY == other.m_tY));
	}

	// != 符号
	template<typename T>
	bool CPoint2D<T>::operator!=(const CPoint2D<T>& other) const
	{
		return ((m_tX != other.m_tX) && (m_tY != other.m_tY));
	}

	// < 符号
	template<typename T>
	bool CPoint2D<T>::operator<(const CPoint2D<T>& other) const
	{
		return ((m_tX < other.m_tX) && (m_tY < other.m_tY));
	}

	// 点乘
	template<typename T>
	T CPoint2D<T>::operator*(const CPoint2D<T>& other) const
	{
		return (m_tX * other.m_tX + m_tY * other.m_tY);
	}

	// 叉乘
	template<typename T>
	CPoint2D<T> CPoint2D<T>::operator* (const T value) const
	{
		return (CPoint2D(m_tX * value, m_tY * value));
	}

	// *=
	template<typename T>
	CPoint2D<T>& CPoint2D<T>::operator*=(const T value)
	{
		m_tX *= value;
		m_tY *= value;
		return (*this);
	}

	// /
	template<typename T>
	CPoint2D<T> CPoint2D<T>::operator/(const T value) const
	{
		return (CPoint2D(m_tX / value, m_tY / value));
	}


	// /=
	template<typename T>
	CPoint2D<T>& CPoint2D<T>::operator/=(const T value)
	{
		m_tX /= value;
		m_tY /= value;
		return (*this);
	}

	// +
	template<typename T>
	CPoint2D<T> CPoint2D<T>::operator+(const CPoint2D<T>& other) const
	{
		return (CPoint2D(m_tX + other.m_tX, m_tY + other.m_tY));
	}

	// += 
	template<typename T>
	CPoint2D<T>& CPoint2D<T>::operator +=(const CPoint2D<T>& other)
	{
		m_tX += other.m_tX;
		m_tY += other.m_tY;
		return (*this);
	}

	// -
	template<typename T>
	CPoint2D<T> CPoint2D<T>::operator-(const CPoint2D<T>& other) const
	{
		return (CPoint2D(m_tX - other.m_tX, m_tY - other.m_tY));
	}

	// -= 
	template<typename T>
	CPoint2D<T>& CPoint2D<T>::operator -=(const CPoint2D<T>& other)
	{
		m_tX -= other.m_tX;
		m_tY -= other.m_tY;
		return (*this);
	}

	// - 取反
	template<typename T>
	const CPoint2D<T> CPoint2D<T>::operator-() const
	{
		return (CPoint2D(-m_tX, -m_tY));
	}

	// 长度 也就是平方根
	template<typename T>
	T CPoint2D<T>::Length(void) const
	{
		return (sqrtf(m_tX * m_tX + m_tY * m_tY));
	}

	// 平方
	template<typename T>
	T CPoint2D<T>::Length2(void) const
	{
		return ((m_tX * m_tX + m_tY * m_tY));
	}

	// 归一化
	template<typename T>
	T CPoint2D<T>::Normalize(void)
	{
		T norm = Length();
		if (norm > 0.0)
		{
			T inv = 1.0 / norm;
			m_tX *= inv;
			m_tY *= inv;
		}
		return (norm);
	}

	template <typename T>
	inline CPoint2D<T> componentMultiply(const CPoint2D<T>& lhs, const CPoint2D<T>& rhs)
	{
		return CPoint2D(lhs.m_tX * rhs.m_tX, lhs.m_tY * rhs.m_tY);
	}

	template <typename T>
	inline CPoint2D<T> componentDivide(const CPoint2D<T>& lhs, const CPoint2D<T>& rhs)
	{
		return CPoint2D(lhs.m_tX / rhs.m_tX, lhs.m_tY / rhs.m_tY);
	}

}

#endif // ! _PUBLIC_POINT2D_H_