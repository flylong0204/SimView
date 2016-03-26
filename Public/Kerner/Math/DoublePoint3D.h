/**************************************************
outher: LJ
time: 2016-03-25
use: ˫���ȸ�����3D������
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_DOUBLEPOINT3D_H_
#define _PUBLIC_DOUBLEPOINT3D_H_

#include "SimViewMath.h"

namespace SimView
{
	class KERNER_EXPORT CDoublePoint3D
	{
	public:

		// ��������
		typedef double value_type;

		// ��������
		enum { num_components = 3 };

		value_type m_data[3];

		// ���캯��
		CDoublePoint3D(){ m_data[0] = 0.0; m_data[1] = 0.0; m_data[2] = 0.0; }
		CDoublePoint3D(value_type x, value_type y, value_type z){ m_data[0] = x; m_data[1] = y; m_data[2] = z; }
		CDoublePoint3D(const CDoublePoint2D& v2, value_type zz)
		{
			m_data[0] = v2[0];
			m_data[1] = v2[1];
			m_data[2] = zz;
		}


		inline bool operator == (const CDoublePoint3D& v) const { return m_data[0] == v.m_data[0] && m_data[1] == v.m_data[1] && m_data[2] == v.m_data[2]; }

		inline bool operator != (const CDoublePoint3D& v) const { return m_data[0] != v.m_data[0] || m_data[1] != v.m_data[1] || m_data[2] != v.m_data[2]; }

		inline bool operator <  (const CDoublePoint3D& v) const
		{
			if (m_data[0]<v.m_data[0]) return true;
			else if (m_data[0]>v.m_data[0]) return false;
			else if (m_data[1] < v.m_data[1]) return true;
			else if (m_data[1] > v.m_data[1]) return false;
			else return (m_data[2] < v.m_data[2]);
		}

		inline value_type* ptr() { return m_data; }
		inline const value_type* ptr() const { return m_data; }

		inline void set(value_type x, value_type y, value_type z)
		{
			m_data[0] = x; m_data[1] = y; m_data[2] = z;
		}

		inline void set(const CDoublePoint3D& rhs)
		{
			m_data[0] = rhs.m_data[0]; m_data[1] = rhs.m_data[1]; m_data[2] = rhs.m_data[2];
		}

		inline value_type& operator [] (int i) { return m_data[i]; }
		inline value_type operator [] (int i) const { return m_data[i]; }

		inline value_type& x() { return m_data[0]; }
		inline value_type& y() { return m_data[1]; }
		inline value_type& z() { return m_data[2]; }

		inline value_type x() const { return m_data[0]; }
		inline value_type y() const { return m_data[1]; }
		inline value_type z() const { return m_data[2]; }

		// �Ƿ���Ч
		inline bool valid() const { return !isNaN(); }
		// �Ƿ���Ч��ֵ
		inline bool isNaN() const { return SimView::isNaN(m_data[0]) || SimView::isNaN(m_data[1]) || SimView::isNaN(m_data[2]); }

		// ���
		inline value_type operator * (const CDoublePoint3D& rhs) const
		{
			return m_data[0] * rhs.m_data[0] + m_data[1] * rhs.m_data[1] + m_data[2] * rhs.m_data[2];
		}

		// ���
		inline const CDoublePoint3D operator ^ (const CDoublePoint3D& rhs) const
		{
			return CDoublePoint3D(m_data[1] * rhs.m_data[2] - m_data[2] * rhs.m_data[1],
				m_data[2] * rhs.m_data[0] - m_data[0] * rhs.m_data[2],
				m_data[0] * rhs.m_data[1] - m_data[1] * rhs.m_data[0]);
		}

		// �ϲ���
		inline const CDoublePoint3D operator * (value_type rhs) const
		{
			return CDoublePoint3D(m_data[0] * rhs, m_data[1] * rhs, m_data[2] * rhs);
		}

		// �ϲ��˵���
		inline CDoublePoint3D& operator *= (value_type rhs)
		{
			m_data[0] *= rhs;
			m_data[1] *= rhs;
			m_data[2] *= rhs;
			return *this;
		}

		// ����
		inline const CDoublePoint3D operator / (value_type rhs) const
		{
			return CDoublePoint3D(m_data[0] / rhs, m_data[1] / rhs, m_data[2] / rhs);
		}

		// ������
		inline CDoublePoint3D& operator /= (value_type rhs)
		{
			m_data[0] /= rhs;
			m_data[1] /= rhs;
			m_data[2] /= rhs;
			return *this;
		}

		// ��
		inline const CDoublePoint3D operator + (const CDoublePoint3D& rhs) const
		{
			return CDoublePoint3D(m_data[0] + rhs.m_data[0], m_data[1] + rhs.m_data[1], m_data[2] + rhs.m_data[2]);
		}

		// �ӵ�
		inline CDoublePoint3D& operator += (const CDoublePoint3D& rhs)
		{
			m_data[0] += rhs.m_data[0];
			m_data[1] += rhs.m_data[1];
			m_data[2] += rhs.m_data[2];
			return *this;
		}

		// ��
		inline const CDoublePoint3D operator - (const CDoublePoint3D& rhs) const
		{
			return CDoublePoint3D(m_data[0] - rhs.m_data[0], m_data[1] - rhs.m_data[1], m_data[2] - rhs.m_data[2]);
		}

		// ������
		inline CDoublePoint3D& operator -= (const CDoublePoint3D& rhs)
		{
			m_data[0] -= rhs.m_data[0];
			m_data[1] -= rhs.m_data[1];
			m_data[2] -= rhs.m_data[2];
			return *this;
		}

		// ȡ��
		inline const CDoublePoint3D operator - () const
		{
			return CDoublePoint3D(-m_data[0], -m_data[1], -m_data[2]);
		}

		// ����
		inline value_type length() const
		{
			return std::sqrt(m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2]);
		}

		// ���ȵ�ƽ��
		inline value_type length2() const
		{
			return m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2];
		}

		// ��һ��
		inline value_type normalize()
		{
			value_type norm = CDoublePoint3D::length();
			if (norm > 0.0)
			{
				value_type inv = 1.0f / norm;
				m_data[0] *= inv;
				m_data[1] *= inv;
				m_data[2] *= inv;
			}
			return(norm);
		}

	};

	// ��ʸ������
	inline CDoublePoint3D componentMultiply(const CDoublePoint3D& lhs, const CDoublePoint3D& rhs)
	{
		return CDoublePoint3D(lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2]);
	}

	// ��RHS�ɷֵ�RHSʸ������ 
	inline CDoublePoint3D componentDivide(const CDoublePoint3D& lhs, const CDoublePoint3D& rhs)
	{
		return CDoublePoint3D(lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2]);
	}

}

#endif // !_PUBLIC_DOUBLEPOINT3D_H_


