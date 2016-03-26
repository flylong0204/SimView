/**************************************************
outher: LJ
time: 2016-03-24
use: 整型点2D向量
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_INTPOINT2D_H_
#define _PUBLIC_INTPOINT2D_H_

namespace SimView
{
	class KERNER_EXPORT CIntPoint2D
	{
	public:

		// 数据类型
		typedef int value_type;

		// 向量个数
		enum { num_components = 2 };

		value_type m_data[2];


		// 构造函数
		CIntPoint2D(){ m_data[0] = 0;  m_data[1] = 0; }
		CIntPoint2D(value_type x, value_type y)  { m_data[0] = x; m_data[1] = y; }


		inline bool operator == (const CIntPoint2D& v) const { return m_data[0] == v.m_data[0] && m_data[1] == v.m_data[1]; }

		inline bool operator != (const CIntPoint2D& v) const { return m_data[0] != v.m_data[0] || m_data[1] != v.m_data[1]; }

		inline bool operator <  (const CIntPoint2D& v) const
		{
			if (m_data[0]<v.m_data[0]) return true;
			else if (m_data[0]>v.m_data[0]) return false;
			else return (m_data[1] < v.m_data[1]);
		}

		inline value_type* ptr() { return m_data; }
		inline const value_type* ptr() const { return m_data; }

		inline void set(value_type x, value_type y)
		{
			m_data[0] = x; m_data[1] = y;
		}

		inline void set(const CIntPoint2D& rhs)
		{
			m_data[0] = rhs.m_data[0]; m_data[1] = rhs.m_data[1];
		}

		inline value_type& operator [] (int i) { return m_data[i]; }
		inline value_type operator [] (int i) const { return m_data[i]; }

		inline value_type& x() { return m_data[0]; }
		inline value_type& y() { return m_data[1]; }

		inline value_type x() const { return m_data[0]; }
		inline value_type y() const { return m_data[1]; }

		inline value_type& r() { return m_data[0]; }
		inline value_type& g() { return m_data[1]; }

		inline value_type r() const { return m_data[0]; }
		inline value_type g() const { return m_data[1]; }

		inline CIntPoint2D operator * (value_type rhs) const
		{
			return CIntPoint2D(m_data[0] * rhs, m_data[1] * rhs);
		}

		inline CIntPoint2D operator / (value_type rhs) const
		{
			return CIntPoint2D(m_data[0] / rhs, m_data[1] / rhs);
		}

		inline CIntPoint2D operator + (value_type rhs) const
		{
			return CIntPoint2D(m_data[0] + rhs, m_data[1] + rhs);
		}

		inline CIntPoint2D operator - (value_type rhs) const
		{
			return CIntPoint2D(m_data[0] - rhs, m_data[1] - rhs);
		}

		inline CIntPoint2D operator + (const CIntPoint2D& rhs) const
		{
			return CIntPoint2D(m_data[0] + rhs.m_data[0], m_data[1] + rhs.m_data[1]);
		}

		inline CIntPoint2D operator - (const CIntPoint2D& rhs) const
		{
			return CIntPoint2D(m_data[0] - rhs.m_data[0], m_data[1] - rhs.m_data[1]);
		}

		inline CIntPoint2D operator * (const CIntPoint2D& rhs) const
		{
			return CIntPoint2D(m_data[0] * rhs.m_data[0], m_data[1] * rhs.m_data[1]);
		}
	};
}

#endif // !_PUBLIC_INTPOINT2D_H_
