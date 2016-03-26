/**************************************************
outher: LJ
time: 2015-12-21
use: the inteface of drawable
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IRENDERABLE_H_
#define _PUBLIC_IRENDERABLE_H_

namespace SimView
{
	class KERNER_EXPORT IRenderable
	{
	public:
		// 析构函数
		virtual ~IRenderable() { }
		// 设置位置

		// 设置缩放
		// 设置旋转
	};
}

#endif // !_PUBLIC_IRENDERABLE_H_