/**************************************************
outher: LJ
time: 2016-03-24
use: �����͵�2D����
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_FLOATPOINT2D_H_
#define _PUBLIC_FLOATPOINT2D_H_

#include "SimViewMath.h"

namespace SimView
{
	class KERNER_EXPORT CFloatPoint2D
	{
	public:

		// ��������
		typedef float value_type;

		// ��������
		enum { num_components = 2 };

		value_type m_data[2];


		// ���캯��
		CFloatPoint2D(){ m_data[0] = 0.f;  m_data[1] = 0.f; }
		CFloatPoint2D(value_type x, value_type y) { m_data[0] = x; m_data[1] = y; }


		inline bool operator == (const CFloatPoint2D& v) const { return m_data[0] == v.m_data[0] && m_data[1] == v.m_data[1]; }

		inline bool operator != (const CFloatPoint2D& v) const { return m_data[0] != v.m_data[0] || m_data[1] != v.m_data[1]; }

		inline bool operator <  (const CFloatPoint2D& v) const
		{
			if (m_data[0]<v.m_data[0]) return true;
			else if (m_data[0]>v.m_data[0]) return false;
			else return (m_data[1]<v.m_data[1]);
		}

		inline value_type * ptr() { return m_data; }
		inline const value_type * ptr() const { return m_data; }

		inline void set(value_type x, value_type y) { m_data[0] = x; m_data[1] = y; }
		inline void set(const CFloatPoint2D& rhs) { m_data[0] = rhs.m_data[0]; m_data[1] = rhs.m_data[1]; }

		inline value_type & operator [] (int i) { return m_data[i]; }
		inline value_type operator [] (int i) const { return m_data[i]; }

		inline value_type & x() { return m_data[0]; }
		inline value_type & y() { return m_data[1]; }

		inline value_type x() const { return m_data[0]; }
		inline value_type y() const { return m_data[1]; }

		// �Ƿ���Ч
		inline bool valid() const { return !isNaN(); }
		// �Ƿ���Ч��ֵ
		inline bool isNaN() const { return SimView::isNaN(m_data[0]) || SimView::isNaN(m_data[1]); }

		// ���
		inline value_type operator * (const CFloatPoint2D& rhs) const
		{
			return m_data[0] * rhs.m_data[0] + m_data[1] * rhs.m_data[1];
		}

		// ���
		inline const CFloatPoint2D operator * (value_type rhs) const
		{
			return CFloatPoint2D(m_data[0] * rhs, m_data[1] * rhs);
		}

		// �ϲ���
		inline CFloatPoint2D& operator *= (value_type rhs)
		{
			m_data[0] *= rhs;
			m_data[1] *= rhs;
			return *this;
		}

		// �ϲ��˵���
		inline const CFloatPoint2D operator / (value_type rhs) const
		{
			return CFloatPoint2D(m_data[0] / rhs, m_data[1] / rhs);
		}

		// ����
		inline CFloatPoint2D& operator /= (value_type rhs)
		{
			m_data[0] /= rhs;
			m_data[1] /= rhs;
			return *this;
		}

		// ������
		inline const CFloatPoint2D operator + (const CFloatPoint2D& rhs) const
		{
			return CFloatPoint2D(m_data[0] + rhs.m_data[0], m_data[1] + rhs.m_data[1]);
		}

		// �ӵ�
		inline CFloatPoint2D& operator += (const CFloatPoint2D& rhs)
		{
			m_data[0] += rhs.m_data[0];
			m_data[1] += rhs.m_data[1];
			return *this;
		}

		// ��
		inline const CFloatPoint2D operator - (const CFloatPoint2D& rhs) const
		{
			return CFloatPoint2D(m_data[0] - rhs.m_data[0], m_data[1] - rhs.m_data[1]);
		}

		// ������
		inline CFloatPoint2D& operator -= (const CFloatPoint2D& rhs)
		{
			m_data[0] -= rhs.m_data[0];
			m_data[1] -= rhs.m_data[1];
			return *this;
		}

		// ȡ��
		inline const CFloatPoint2D operator - () const
		{
			return CFloatPoint2D(-m_data[0], -m_data[1]);
		}

		// ����
		inline value_type length() const
		{
			return std::sqrtf(m_data[0] * m_data[0] + m_data[1] * m_data[1]);
		}

		// ���ȵ�ƽ��
		inline value_type length2(void) const
		{
			return m_data[0] * m_data[0] + m_data[1] * m_data[1];
		}

		// ��һ��
		inline value_type normalize()
		{
			value_type norm = CFloatPoint2D::length();
			if (norm>0.0)
			{
				value_type inv = 1.0f / norm;
				m_data[0] *= inv;
				m_data[1] *= inv;
			}
			return(norm);
		}

	};   

	// ��ʸ������
	inline CFloatPoint2D componentMultiply(const CFloatPoint2D& lhs, const CFloatPoint2D& rhs)
	{
		return CFloatPoint2D(lhs[0] * rhs[0], lhs[1] * rhs[1]);
	}

	// ��RHS�ɷֵ�RHSʸ������ 
	inline CFloatPoint2D componentDivide(const CFloatPoint2D& lhs, const CFloatPoint2D& rhs)
	{
		return CFloatPoint2D(lhs[0] / rhs[0], lhs[1] / rhs[1]);
	}
}

#endif // !_PUBLIC_FLOATPOINT2D_H_
