/**************************************************
outher: LJ
time: 2016-03-25
use: 整数型3D点向量
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_INTPOINT3D_H_
#define _PUBLIC_INTPOINT3D_H_

#include "SimViewMath.h"

namespace SimView
{
	class KERNER_EXPORT CIntPoint3D
	{
	public:

		// 数据类型
		typedef int value_type;

		// 向量个数
		enum { num_components = 3 };

		value_type m_data[3];

		// 构造函数
		CIntPoint3D(){ m_data[0] = 0; m_data[1] = 0; m_data[2] = 0; }
		CIntPoint3D(value_type x, value_type y, value_type z){ m_data[0] = x; m_data[1] = y; m_data[2] = z; }
		CIntPoint3D(const CIntPoint2D& v2, value_type zz)
		{
			m_data[0] = v2[0];
			m_data[1] = v2[1];
			m_data[2] = zz;
		}

		inline value_type* ptr() { return m_data; }
		inline const value_type* ptr() const { return m_data; }

		inline void set(value_type r, value_type g, value_type b)
		{
			m_data[0] = r; m_data[1] = g; m_data[2] = b;
		}

		inline void set(const CIntPoint3D& rhs)
		{
			m_data[0] = rhs.m_data[0]; m_data[1] = rhs.m_data[1]; m_data[2] = rhs.m_data[2];
		}

		inline value_type& operator [] (unsigned int i) { return m_data[i]; }
		inline value_type operator [] (unsigned int i) const { return m_data[i]; }

		inline value_type& x() { return m_data[0]; }
		inline value_type& y() { return m_data[1]; }
		inline value_type& z() { return m_data[2]; }

		inline value_type x() const { return m_data[0]; }
		inline value_type y() const { return m_data[1]; }
		inline value_type z() const { return m_data[2]; }

		inline value_type& r() { return m_data[0]; }
		inline value_type& g() { return m_data[1]; }
		inline value_type& b() { return m_data[2]; }

		inline value_type r() const { return m_data[0]; }
		inline value_type g() const { return m_data[1]; }
		inline value_type b() const { return m_data[2]; }

		inline CIntPoint3D operator * (value_type rhs) const
		{
			return CIntPoint3D(m_data[0] * rhs, m_data[1] * rhs, m_data[2] * rhs);
		}

		inline CIntPoint3D operator / (value_type rhs) const
		{
			return CIntPoint3D(m_data[0] / rhs, m_data[1] / rhs, m_data[2] / rhs);
		}

		inline CIntPoint3D operator + (value_type rhs) const
		{
			return CIntPoint3D(m_data[0] + rhs, m_data[1] + rhs, m_data[2] + rhs);
		}

		inline CIntPoint3D operator - (value_type rhs) const
		{
			return CIntPoint3D(m_data[0] - rhs, m_data[1] - rhs, m_data[2] - rhs);
		}

		inline CIntPoint3D operator + (const CIntPoint3D& rhs) const
		{
			return CIntPoint3D(m_data[0] + rhs.m_data[0], m_data[1] + rhs.m_data[1], m_data[2] + rhs.m_data[2]);
		}

		inline CIntPoint3D operator - (const CIntPoint3D& rhs) const
		{
			return CIntPoint3D(m_data[0] - rhs.m_data[0], m_data[1] - rhs.m_data[1], m_data[2] - rhs.m_data[2]);
		}

		inline CIntPoint3D operator * (const CIntPoint3D& rhs) const
		{
			return CIntPoint3D(m_data[0] * rhs.m_data[0], m_data[1] * rhs.m_data[1], m_data[2] * rhs.m_data[2]);
		}
	};

}

#endif // !_PUBLIC_INTPOINT3D_H_


