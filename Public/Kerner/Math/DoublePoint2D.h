/**************************************************
outher: LJ
time: 2016-03-24
use: ˫�����͵�2D����
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_DOUBLEPOINT2D_H_
#define _PUBLIC_DOUBLEPOINT2D_H_

#include "SimViewMath.h"

namespace SimView
{
	class KERNER_EXPORT CDoublePoint2D
	{
	public:

		// ��������
		typedef double value_type;

		// ��������
		enum { num_components = 2 };

		value_type m_data[2];


		// ���캯��
		CDoublePoint2D(){ m_data[0] = 0.0;  m_data[1] = 0.0; }
		CDoublePoint2D(value_type x, value_type y){ m_data[0] = x; m_data[1] = y; }


		inline bool operator == (const CDoublePoint2D& v) const { return m_data[0] == v.m_data[0] && m_data[1] == v.m_data[1]; }

		inline bool operator != (const CDoublePoint2D& v) const { return m_data[0] != v.m_data[0] || m_data[1] != v.m_data[1]; }

		inline bool operator <  (const CDoublePoint2D& v) const
		{
			if (m_data[0]<v.m_data[0]) return true;
			else if (m_data[0]>v.m_data[0]) return false;
			else return (m_data[1] < v.m_data[1]);
		}

		inline value_type * ptr() { return m_data; }
		inline const value_type * ptr() const { return m_data; }

		inline void set(value_type x, value_type y) { m_data[0] = x; m_data[1] = y; }
		inline void set(const CDoublePoint2D& rhs) { m_data[0] = rhs.m_data[0]; m_data[1] = rhs.m_data[1]; }

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
		inline value_type operator * (const CDoublePoint2D& rhs) const
		{
			return m_data[0] * rhs.m_data[0] + m_data[1] * rhs.m_data[1];
		}

		// ���
		inline const CDoublePoint2D operator * (value_type rhs) const
		{
			return CDoublePoint2D(m_data[0] * rhs, m_data[1] * rhs);
		}

		// �ϲ���
		inline CDoublePoint2D& operator *= (value_type rhs)
		{
			m_data[0] *= rhs;
			m_data[1] *= rhs;
			return *this;
		}

		// �ϲ��˵���
		inline const CDoublePoint2D operator / (value_type rhs) const
		{
			return CDoublePoint2D(m_data[0] / rhs, m_data[1] / rhs);
		}

		// ����
		inline CDoublePoint2D& operator /= (value_type rhs)
		{
			m_data[0] /= rhs;
			m_data[1] /= rhs;
			return *this;
		}

		// ������
		inline const CDoublePoint2D operator + (const CDoublePoint2D& rhs) const
		{
			return CDoublePoint2D(m_data[0] + rhs.m_data[0], m_data[1] + rhs.m_data[1]);
		}

		// �ӵ�
		inline CDoublePoint2D& operator += (const CDoublePoint2D& rhs)
		{
			m_data[0] += rhs.m_data[0];
			m_data[1] += rhs.m_data[1];
			return *this;
		}

		// ��
		inline const CDoublePoint2D operator - (const CDoublePoint2D& rhs) const
		{
			return CDoublePoint2D(m_data[0] - rhs.m_data[0], m_data[1] - rhs.m_data[1]);
		}

		// ������
		inline CDoublePoint2D& operator -= (const CDoublePoint2D& rhs)
		{
			m_data[0] -= rhs.m_data[0];
			m_data[1] -= rhs.m_data[1];
			return *this;
		}

		// ȡ��
		inline const CDoublePoint2D operator - () const
		{
			return CDoublePoint2D(-m_data[0], -m_data[1]);
		}

		// ����
		inline value_type length() const
		{
			return std::sqrt(m_data[0] * m_data[0] + m_data[1] * m_data[1]);
		}

		// ���ȵ�ƽ��
		inline value_type length2(void) const
		{
			return m_data[0] * m_data[0] + m_data[1] * m_data[1];
		}

		// ��һ��
		inline value_type normalize()
		{
			value_type norm = CDoublePoint2D::length();
			if (norm > 0.0)
			{
				value_type inv = 1.0f / norm;
				m_data[0] *= inv;
				m_data[1] *= inv;
			}
			return(norm);
		}

	};

	// ��ʸ������
	inline CDoublePoint2D componentMultiply(const CDoublePoint2D& lhs, const CDoublePoint2D& rhs)
	{
		return CDoublePoint2D(lhs[0] * rhs[0], lhs[1] * rhs[1]);
	}

	// ��RHS�ɷֵ�RHSʸ������ 
	inline CDoublePoint2D componentDivide(const CDoublePoint2D& lhs, const CDoublePoint2D& rhs)
	{
		return CDoublePoint2D(lhs[0] / rhs[0], lhs[1] / rhs[1]);
	}
}

#endif // !_PUBLIC_DOUBLEPOINT2D_H_
