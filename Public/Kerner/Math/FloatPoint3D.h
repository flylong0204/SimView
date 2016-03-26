/**************************************************
outher: LJ
time: 2016-03-24
use: �����͵�����
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_FLOATPOINT3D_H_
#define _PUBLIC_FLOATPOINT3D_H_

#include "SimViewMath.h"

namespace SimView
{
	class CFloatPoint3D
	{
	public:

		// ��������
		typedef float value_type;

		// ��������
		enum { num_components = 3 };

		value_type m_data[3];

		// ���캯��
		CFloatPoint3D(){ m_data[0] = 0.0f; m_data[1] = 0.0f; m_data[2] = 0.0f; }
		CFloatPoint3D(value_type x, value_type y, value_type z) { m_data[0] = x; m_data[1] = y; m_data[2] = z;  }
		CFloatPoint3D(const CFloatPoint2D& v2, value_type zz)
		{
			m_data[0] = v2[0];
			m_data[1] = v2[1];
			m_data[2] = zz;
		}


		inline bool operator == (const CFloatPoint3D& v) const { return m_data[0] == v.m_data[0] && m_data[1] == v.m_data[1] && m_data[2] == v.m_data[2]; }

		inline bool operator != (const CFloatPoint3D& v) const { return m_data[0] != v.m_data[0] || m_data[1] != v.m_data[1] || m_data[2] != v.m_data[2]; }

		inline bool operator <  (const CFloatPoint3D& v) const
		{
			if (m_data[0]<v.m_data[0]) return true;
			else if (m_data[0]>v.m_data[0]) return false;
			else if (m_data[1]<v.m_data[1]) return true;
			else if (m_data[1]>v.m_data[1]) return false;
			else return (m_data[2]<v.m_data[2]);
		}

		inline value_type* ptr() { return m_data; }
		inline const value_type* ptr() const { return m_data; }

		inline void set(value_type x, value_type y, value_type z)
		{
			m_data[0] = x; m_data[1] = y; m_data[2] = z;
		}

		inline void set(const CFloatPoint3D& rhs)
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
		inline value_type operator * (const CFloatPoint3D& rhs) const
		{
			return m_data[0] * rhs.m_data[0] + m_data[1] * rhs.m_data[1] + m_data[2] * rhs.m_data[2];
		}

		// ���
		inline const CFloatPoint3D operator ^ (const CFloatPoint3D& rhs) const
		{
			return CFloatPoint3D(m_data[1] * rhs.m_data[2] - m_data[2] * rhs.m_data[1],
				m_data[2] * rhs.m_data[0] - m_data[0] * rhs.m_data[2],
				m_data[0] * rhs.m_data[1] - m_data[1] * rhs.m_data[0]);
		}

		// �ϲ���
		inline const CFloatPoint3D operator * (value_type rhs) const
		{
			return CFloatPoint3D(m_data[0] * rhs, m_data[1] * rhs, m_data[2] * rhs);
		}

		// �ϲ��˵���
		inline CFloatPoint3D& operator *= (value_type rhs)
		{
			m_data[0] *= rhs;
			m_data[1] *= rhs;
			m_data[2] *= rhs;
			return *this;
		}

		// ����
		inline const CFloatPoint3D operator / (value_type rhs) const
		{
			return CFloatPoint3D(m_data[0] / rhs, m_data[1] / rhs, m_data[2] / rhs);
		}

		// ������
		inline CFloatPoint3D& operator /= (value_type rhs)
		{
			m_data[0] /= rhs;
			m_data[1] /= rhs;
			m_data[2] /= rhs;
			return *this;
		}

		// ��
		inline const CFloatPoint3D operator + (const CFloatPoint3D& rhs) const
		{
			return CFloatPoint3D(m_data[0] + rhs.m_data[0], m_data[1] + rhs.m_data[1], m_data[2] + rhs.m_data[2]);
		}

		// �ӵ�
		inline CFloatPoint3D& operator += (const CFloatPoint3D& rhs)
		{
			m_data[0] += rhs.m_data[0];
			m_data[1] += rhs.m_data[1];
			m_data[2] += rhs.m_data[2];
			return *this;
		}

		// ��
		inline const CFloatPoint3D operator - (const CFloatPoint3D& rhs) const
		{
			return CFloatPoint3D(m_data[0] - rhs.m_data[0], m_data[1] - rhs.m_data[1], m_data[2] - rhs.m_data[2]);
		}

		// ������
		inline CFloatPoint3D& operator -= (const CFloatPoint3D& rhs)
		{
			m_data[0] -= rhs.m_data[0];
			m_data[1] -= rhs.m_data[1];
			m_data[2] -= rhs.m_data[2];
			return *this;
		}

		// ȡ��
		inline const CFloatPoint3D operator - () const
		{
			return CFloatPoint3D(-m_data[0], -m_data[1], -m_data[2]);
		}

		// ����
		inline value_type length() const
		{
			return std::sqrtf(m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2]);
		}

		// ���ȵ�ƽ��
		inline value_type length2() const
		{
			return m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2];
		}

		// ��һ��
		inline value_type normalize()
		{
			value_type norm = CFloatPoint3D::length();
			if (norm>0.0)
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
	inline CFloatPoint3D componentMultiply(const CFloatPoint3D& lhs, const CFloatPoint3D& rhs)
	{
		return CFloatPoint3D(lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2]);
	}

	// ��RHS�ɷֵ�RHSʸ������ 
	inline CFloatPoint3D componentDivide(const CFloatPoint3D& lhs, const CFloatPoint3D& rhs)
	{
		return CFloatPoint3D(lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2]);
	}

	const CFloatPoint3D X_AXIS(1.0, 0.0, 0.0);
	const CFloatPoint3D Y_AXIS(0.0, 1.0, 0.0);
	const CFloatPoint3D Z_AXIS(0.0, 0.0, 1.0);
}

#endif // !_PUBLIC_FLOATPOINT3D_H_


