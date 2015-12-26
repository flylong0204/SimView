/**************************************************
outher: LJ
time: 2015-11-01
use: osg��Ⱦ��ӿ�
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
		// ��������
		virtual ~IOsgViewConfig() { }
		// �����ͼ����
		virtual SVString GetName(void) const = 0;
		// ��ʼ��������
		virtual void InitManipulator(osgGA::KeySwitchMatrixManipulator* pMainpulator) = 0;
		// ��ʼ����ͼ
		virtual void InitContextTraits(osg::GraphicsContext::Traits* pTraits) = 0;
	};
}

#endif // !_PUBLIC_IOSGVIEWCONFING_H_
