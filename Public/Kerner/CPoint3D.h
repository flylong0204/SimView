/**************************************************
outher: LJ
time: 2015-12-21
use: the Point of 3D
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_POINT3D_H_
#define _PUBLIC_POINT3D_H_

namespace SimView
{
	template<typename T>
	class CPoint3D
	{
	public:
		// 构造函数
		explicit CPoint3D(void);
		explicit CPoint3D(T x, T y, T z);
		explicit CPoint3D(const CPoint3D& other);
		CPoint3D& operator= (const CPoint3D& other);
		// 析构函数
		~CPoint3D(void) { }

	public:
		// == 符号
		inline bool operator==(const CPoint3D& other) const;
		// != 符号
		inline bool operator!=(const CPoint3D& other) const;
		// < 符号
		inline bool operator< (const CPoint3D& other) const;
		// 点乘
		inline T operator* (const CPoint3D& other) const;
		// 叉乘
		inline CPoint3D operator* (const T value) const;
		// *=
		inline CPoint3D& operator*=(const T value);
		// /
		inline CPoint3D operator /(const T value) const;
		// /=
		inline CPoint3D& operator /=(const T value);
		// +
		inline CPoint3D operator + (const CPoint3D& other) const;
		// +=
		inline CPoint3D& operator +=(const CPoint3D& other);
		// -
		inline CPoint3D operator - (const CPoint3D& other) const;
		// -=
		inline CPoint3D& operator -=(const CPoint3D& other);
		// - 取反
		inline const CPoint3D operator- () const;
		// 平方根
		T Length(void) const;
		// 平方
		T Length2(void) const;
		// 归一化
		T Normalize(void);
		const CPoint3D operator ^ (const CPoint3D<T>& other) const;
	public:
		T m_tX, m_tY, m_tZ;
	};

	template<typename T>
	CPoint3D<T>::CPoint3D(void)
		:m_tX(0), m_tY(0), m_tZ(0)
	{

	}

	template<typename T>
	CPoint3D<T>::CPoint3D(T x, T y, T z)
		:m_tX(x), m_tY(y), m_tZ(z)
	{

	}

	template<typename T>
	CPoint3D<T>::CPoint3D(const CPoint3D& other)
		:m_tX(other.m_tX), m_tY(other.m_tY), m_tZ(other.m_tZ)
	{

	}

	template<typename T>
	CPoint3D& CPoint3D<T>::operator=(const CPoint3D& other)
	{
		m_tX = other.m_tX;
		m_tY = other.m_tY;
		m_tZ = other.m_tZ;
		return (*this);
	}

	// ==符号
	template<typename T>
	bool CPoint3D<T>::operator==(const CPoint3D& other) const
	{
		return ((m_tX == other.m_tX) && (m_tY == other.m_tY) && (m_tZ == other.m_tZ));
	}

	// != 符号
	template<typename T>
	bool CPoint3D<T>::operator!=(const CPoint3D& other) const
	{
		return ((m_tX != other.m_tX) && (m_tY != other.m_tY) && (m_tZ != other.m_tZ));
	}

	// < 符号
	template<typename T>
	bool CPoint3D<T>::operator<(const CPoint3D& other) const
	{
		return ((m_tX < other.m_tX) && (m_tY < other.m_tY) && (m_tZ < other.m_tZ));
	}

	// 点乘
	template<typename T>
	T CPoint3D<T>::operator*(const CPoint3D& other) const
	{
		return (m_tX * other.m_tX + m_tY * other.m_tY + m_tZ * other.m_tZ);
	}

	// 叉乘
	template<typename T>
	const CPoint3D CPoint3D<T>::operator ^ (const CPoint3D<T>& other) const
	{
		return CPoint3D(m_tY * other.m_tZ - m_tZ * other.m_tY,
			m_tZ * other.m_tX - m_tX * other.m_tZ,
			m_tX * other.m_tY - m_tY * other.m_tX);
	}



	// 叉乘
	template<typename T>
	CPoint3D CPoint3D<T>::operator* (const T value) const
	{
		return (CPoint3D(m_tX * value, m_tY * value, m_tZ * value));
	}

	// *=
	template<typename T>
	CPoint3D& CPoint3D<T>::operator*=(const T value)
	{
		m_tX *= value;
		m_tY *= value;
		m_tZ *= value;
		return (*this);
	}

	// /
	template<typename T>
	CPoint3D CPoint3D<T>::operator/(const T value) const
	{
		return (CPoint3D(m_tX / value, m_tY / value, m_tZ / value));
	}


	// /=
	template<typename T>
	CPoint3D& CPoint3D<T>::operator/=(const T value)
	{
		m_tX /= value;
		m_tY /= value;
		m_tZ /= value;
		return (*this);
	}

	// +
	template<typename T>
	CPoint3D CPoint3D<T>::operator+(const CPoint3D& other) const
	{
		return (CPoint3D(m_tX + other.m_tX, m_tY + other.m_tY, m_tZ + other.m_tZ));
	}

	// += 
	template<typename T>
	CPoint3D& CPoint3D<T>::operator +=(const CPoint3D& other)
	{
		m_tX += other.m_tX;
		m_tY += other.m_tY;
		m_tZ += other.m_tZ;
		return (*this);
	}

	// -
	template<typename T>
	CPoint3D CPoint3D<T>::operator-(const CPoint3D& other) const
	{
		return (CPoint3D(m_tX - other.m_tX, m_tY - other.m_tY, m_tZ - other.m_tZ));
	}

	// -= 
	template<typename T>
	CPoint3D& CPoint3D::operator -=(const CPoint3D& other)
	{
		m_tX -= other.m_tX;
		m_tY -= other.m_tY;
		m_tZ -= other.m_tZ;
		return (*this);
	}

	// - 取反
	template<typename T>
	const CPoint3D CPoint3D<T>::operator-() const
	{
		return (CPoint3D(-m_tX, -m_tY, m_tZ));
	}

	// 长度 也就是平方根
	template<typename T>
	T CPoint3D<T>::Length(void) const
	{
		return (sqrtf(m_tX * m_tX + m_tY * m_tY + m_tZ * m_tZ));
	}

	// 平方
	template<typename T>
	T CPoint3D<T>::Length2(void) const
	{
		return ((m_tX * m_tX + m_tY * m_tY + m_tZ * m_tZ));
	}

	// 归一化
	template<typename T>
	T CPoint3D<T>::Normalize(void)
	{
		T norm = Length();
		if (norm > 0.0)
		{
			T inv = 1.0 / norm;
			m_tX *= inv;
			m_tY *= inv;
			m_tZ *= inv;
		}
		return (norm);
	}

	template <typename T>
	inline CPoint3D<T> componentMultiply(const CPoint3D<T>& lhs, const CPoint3D<T>& rhs)
	{
		return CPoint3D(lhs.m_tX * rhs.m_tX, lhs.m_tY * rhs.m_tY, lhs.m_tZ * rhs.m_tZ);
	}

	template <typename T>
	inline CPoint3D<T> componentDivide(const CPoint3D<T>& lhs, const CPoint3D<T>& rhs)
	{
		return CPoint3D(lhs.m_tX / rhs.m_tX, lhs.m_tY / rhs.m_tY, lhs.m_tZ / rhs.m_tZ);
	}

}

#endif // ! _PUBLIC_POINT3D_H_