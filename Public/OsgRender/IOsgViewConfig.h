/**************************************************
outher: LJ
time: 2015-11-01
use: osg渲染类接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IOSGVIEWCONFING_H_
#define _PUBLIC_IOSGVIEWCONFING_H_

namespace osg
{
	class GraphicsContext;
	struct GraphicsContext::Traits;
}

namespace osgGA
{
	class KeySwitchMatrixManipulator;
}

namespace SimView
{
	class IOsgViewConfig
	{
	public:
		// 析构函数
		virtual ~IOsgViewConfig() { }
		// 获得视图名称
		virtual SVString GetName(void) const = 0;
		// 初始化操作器
		virtual void InitManipulator(osgGA::KeySwitchMatrixManipulator* pMainpulator) = 0;
		// 初始化视图
		virtual void InitContextTraits(osg::GraphicsContext::Traits* pTraits) = 0;
	};
}

#endif // !_PUBLIC_IOSGVIEWCONFING_H_
