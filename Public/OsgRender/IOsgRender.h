/**************************************************
outher: LJ
time: 2015-11-01
use: osg渲染类接口 主要对相机的管理
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IOSGRENDER_H_
#define _PUBLIC_IOSGRENDER_H_

// 定义导出关键字
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
		// 析构函数
		virtual ~IOsgRender() { }
		// 创建视图
		virtual void CreateView(IOsgViewConfig* pIOsgViewConfig) = 0;
		// 获得试图
		virtual IOsgView* GetView(const SVString& strViewName) const = 0;
		// 添加渲染节点
		virtual void AddRenderObj(DrawObj* pRenderObj, const SVString& strViewName = "MainView") = 0;
		// 单独线程运行
		virtual void RunByThread(void) = 0;
	};

}

#endif // !_PUBLIC_IOSGRENDER_H_
