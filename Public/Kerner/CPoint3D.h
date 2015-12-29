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
		// ���캯��
		explicit CPoint3D(void);
		explicit CPoint3D(T x, T y, T z);
		explicit CPoint3D(const CPoint3D& other);
		CPoint3D& operator= (const CPoint3D& other);
		// ��������
		~CPoint3D(void) { }

	public:
		// == ����
		inline bool operator==(const CPoint3D& other) const;
		// != ����
		inline bool operator!=(const CPoint3D& other) const;
		// < ����
		inline bool operator< (const CPoint3D& other) const;
		// ���
		inline T operator* (const CPoint3D& other) const;
		// ���
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
		// - ȡ��
		inline const CPoint3D operator- () const;
		// ƽ����
		T Length(void) const;
		// ƽ��
		T Length2(void) const;
		// ��һ��
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

	// ==����
	template<typename T>
	bool CPoint3D<T>::operator==(const CPoint3D& other) const
	{
		return ((m_tX == other.m_tX) && (m_tY == other.m_tY) && (m_tZ == other.m_tZ));
	}

	// != ����
	template<typename T>
	bool CPoint3D<T>::operator!=(const CPoint3D& other) const
	{
		return ((m_tX != other.m_tX) && (m_tY != other.m_tY) && (m_tZ != other.m_tZ));
	}

	// < ����
	template<typename T>
	bool CPoint3D<T>::operator<(const CPoint3D& other) const
	{
		return ((m_tX < other.m_tX) && (m_tY < other.m_tY) && (m_tZ < other.m_tZ));
	}

	// ���
	template<typename T>
	T CPoint3D<T>::operator*(const CPoint3D& other) const
	{
		return (m_tX * other.m_tX + m_tY * other.m_tY + m_tZ * other.m_tZ);
	}

	// ���
	template<typename T>
	const CPoint3D CPoint3D<T>::operator ^ (const CPoint3D<T>& other) const
	{
		return CPoint3D(m_tY * other.m_tZ - m_tZ * other.m_tY,
			m_tZ * other.m_tX - m_tX * other.m_tZ,
			m_tX * other.m_tY - m_tY * other.m_tX);
	}



	// ���
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

	// - ȡ��
	template<typename T>
	const CPoint3D CPoint3D<T>::operator-() const
	{
		return (CPoint3D(-m_tX, -m_tY, m_tZ));
	}

	// ���� Ҳ����ƽ����
	template<typename T>
	T CPoint3D<T>::Length(void) const
	{
		return (sqrtf(m_tX * m_tX + m_tY * m_tY + m_tZ * m_tZ));
	}

	// ƽ��
	template<typename T>
	T CPoint3D<T>::Length2(void) const
	{
		return ((m_tX * m_tX + m_tY * m_tY + m_tZ * m_tZ));
	}

	// ��һ��
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