/**************************************************
outher: LJ
time: 2015-11-01
use: osg��Ⱦ��ӿ�
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
		// ��������
		virtual ~IOsgView() { }
		// ��ӽڵ�
		virtual void AddRenderObj(void* pRenderObj) = 0;
	};
}

#endif // !_PUBLIC_IOSGVIEW_H_
