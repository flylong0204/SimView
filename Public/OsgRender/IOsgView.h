/**************************************************
outher: LJ
time: 2015-11-01
use: osg渲染类接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IOSGVIEW_H_
#define _PUBLIC_IOSGVIEW_H_

namespace SimView
{
	class OSGRENDER_EXPORT IOsgView
	{
	public:
		// 析构函数
		virtual ~IOsgView() { }
		// 添加节点
		virtual void AddRenderObj(void* pRenderObj) = 0;
	};
}

#endif // !_PUBLIC_IOSGVIEW_H_
