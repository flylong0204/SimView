/**************************************************
outher: LJ
time: 2015-11-01
use: Osg渲染插件类
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGRENDER_H_
#define _OSGRENDER_H_

#pragma once

namespace SimView
{
	class COsgViewerThread;
	class COsgViewer;

	class COsgRender : public IOsgRender
	{
	public:
		// 构造函数
		explicit COsgRender(void);
		// 析构函数
		virtual ~COsgRender(void);

	public:
		// 创建视图
		virtual void CreateView(IOsgViewConfig* pIOsgViewConfig);
		// 获得视图
		virtual IOsgView* GetView(const SVString& strViewName) const;
		// 添加渲染节点
		virtual void AddRenderObj(DrawObj* pRenderObj, const SVString& strViewName = "MainView");

	public:
		// 设置组件名称
		virtual void SetName(const SVString& strName);
		// 获得组件名称
		virtual const SVString& GetName(void) const;
		// 获得类型
		virtual const SVString& GetTypeName(void) const;
		// 创建时调用初始化
		virtual void Init(void);

	public:
		// 单独线程运行
		virtual void RunByThread(void);

	private:
		SVString m_strName;
		COsgViewer* m_pOsgViewer; // 视图组合
		COsgViewerThread* m_pOsgViewerThread; // 线程指针
	};

	// 创建工厂
	CREATE_COMBASEFACTORY(COsgRender, COMTYPE_OSGRENDER, COMNAME_OSGRENDER, COMDIR_OSGRENDER)
}

#endif // !_OSGRENDER_H_