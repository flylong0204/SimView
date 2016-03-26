/**************************************************
outher: LJ
time: 2015-11-01
use: osg��Ⱦ��ӿ� ��Ҫ������Ĺ���
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IOSGRENDER_H_
#define _PUBLIC_IOSGRENDER_H_

// ���嵼���ؼ���
#ifdef OSGRENDER_DLL
#define OSGRENDER_EXPORT SIMVIEW_EXPORT
#else 
#define OSGRENDER_EXPORT SIMVIEW_IMPORT
#endif // OSGRENDER_DLL


namespace SimView
{
	const SVString COMTYPE_OSGRENDER = "Osg Render";
	const SVString COMNAME_OSGRENDER = "OsgRender";
	const SVString COMDIR_OSGRENDER = "use osg render the osg node";

	class IOsgViewConfig;
	class IOsgView;

	class OSGRENDER_EXPORT IOsgRender : public IComFaceBase
	{
	public:
		// ��������
		virtual ~IOsgRender() { }
		// ������ͼ
		virtual void CreateView(IOsgViewConfig* pIOsgViewConfig) = 0;
		// �����ͼ
		virtual IOsgView* GetView(const SVString& strViewName) const = 0;
		// �����Ⱦ�ڵ�
		virtual void AddRenderObj(DrawObj* pRenderObj, const SVString& strViewName = "MainView") = 0;
		// �����߳�����
		virtual void RunByThread(void) = 0;
	};

}

#endif // !_PUBLIC_IOSGRENDER_H_
