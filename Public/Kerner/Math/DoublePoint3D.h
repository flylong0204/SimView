/**************************************************
outher: LJ
time: 2016-03-25
use: 双精度浮点型3D点向量
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

		// 数据类型
		typedef double value_type;

		// 向量个数
		enum { num_components = 3 };

		value_type m_data[3];

		// 构造函数
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

		// 是否有效
		inline bool valid() const { return !isNaN(); }
		// 是否有效的值
		inline bool isNaN() const { return SimView::isNaN(m_data[0]) || SimView::isNaN(m_data[1]) || SimView::isNaN(m_data[2]); }

		// 点乘
		inline value_type operator * (const CDoublePoint3D& rhs) const
		{
			return m_data[0] * rhs.m_data[0] + m_data[1] * rhs.m_data[1] + m_data[2] * rhs.m_data[2];
		}

		// 叉乘
		inline const CDoublePoint3D operator ^ (const CDoublePoint3D& rhs) const
		{
			return CDoublePoint3D(m_data[1] * rhs.m_data[2] - m_data[2] * rhs.m_data[1],
				m_data[2] * rhs.m_data[0] - m_data[0] * rhs.m_data[2],
				m_data[0] * rhs.m_data[1] - m_data[1] * rhs.m_data[0]);
		}

		// 合并乘
		inline const CDoublePoint3D operator * (value_type rhs) const
		{
			return CDoublePoint3D(m_data[0] * rhs, m_data[1] * rhs, m_data[2] * rhs);
		}

		// 合并乘等于
		inline CDoublePoint3D& operator *= (value_type rhs)
		{
			m_data[0] *= rhs;
			m_data[1] *= rhs;
			m_data[2] *= rhs;
			return *this;
		}

		// 除法
		inline const CDoublePoint3D operator / (value_type rhs) const
		{
			return CDoublePoint3D(m_data[0] / rhs, m_data[1] / rhs, m_data[2] / rhs);
		}

		// 除等于
		inline CDoublePoint3D& operator /= (value_type rhs)
		{
			m_data[0] /= rhs;
			m_data[1] /= rhs;
			m_data[2] /= rhs;
			return *this;
		}

		// 加
		inline const CDoublePoint3D operator + (const CDoublePoint3D& rhs) const
		{
			return CDoublePoint3D(m_data[0] + rhs.m_data[0], m_data[1] + rhs.m_data[1], m_data[2] + rhs.m_data[2]);
		}

		// 加等
		inline CDoublePoint3D& operator += (const CDoublePoint3D& rhs)
		{
			m_data[0] += rhs.m_data[0];
			m_data[1] += rhs.m_data[1];
			m_data[2] += rhs.m_data[2];
			return *this;
		}

		// 减
		inline const CDoublePoint3D operator - (const CDoublePoint3D& rhs) const
		{
			return CDoublePoint3D(m_data[0] - rhs.m_data[0], m_data[1] - rhs.m_data[1], m_data[2] - rhs.m_data[2]);
		}

		// 减等于
		inline CDoublePoint3D& operator -= (const CDoublePoint3D& rhs)
		{
			m_data[0] -= rhs.m_data[0];
			m_data[1] -= rhs.m_data[1];
			m_data[2] -= rhs.m_data[2];
			return *this;
		}

		// 取反
		inline const CDoublePoint3D operator - () const
		{
			return CDoublePoint3D(-m_data[0], -m_data[1], -m_data[2]);
		}

		// 长度
		inline value_type length() const
		{
			return std::sqrt(m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2]);
		}

		// 长度的平方
		inline value_type length2() const
		{
			return m_data[0] * m_data[0] + m_data[1] * m_data[1] + m_data[2] * m_data[2];
		}

		// 归一化
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

	// 乘矢量分量
	inline CDoublePoint3D componentMultiply(const CDoublePoint3D& lhs, const CDoublePoint3D& rhs)
	{
		return CDoublePoint3D(lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2]);
	}

	// 除RHS成分的RHS矢量分量 
	inline CDoublePoint3D componentDivide(const CDoublePoint3D& lhs, const CDoublePoint3D& rhs)
	{
		return CDoublePoint3D(lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2]);
	}

}

#endif // !_PUBLIC_DOUBLEPOINT3D_H_


