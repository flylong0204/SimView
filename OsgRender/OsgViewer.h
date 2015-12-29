/**************************************************
outher: LJ
time: 2015-11-01
use: osg渲染集合类 提供自身渲染采用线程和外部驱动渲染（比如定时器调用）
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGVIEWER_H_
#define _OSGVIEWER_H_

#pragma once

#include <map>
#include <windows.h>

namespace osgViewer
{
	class CompositeViewer;
}

namespace SimView
{
	class COsgView;
	class IOsgViewConfig;
	class IOsgView;

	class COsgViewer
	{
	public:
		explicit COsgViewer();
		virtual ~COsgViewer();

	public:
		// 创建一个视图
		virtual void Create(IOsgViewConfig* pIOsgViewConfig);
		// 获得视图对象
		virtual IOsgView* GetView(const SVString& strName) const;

	public:
		// 获得组合视图
		osgViewer::CompositeViewer* GetViewer(void) const;
		// 每一帧前需要处理的函数
		void PreFrameUpdate(void);
		// 每一帧后要处理的函数
		void PostFrameUpdate(void);

	protected:
		// 添加视图
		void AddOsgView(COsgView* pOsgView);
		// 移除视图
		void RemoveView(COsgView* pOsgView);

	protected:
		typedef std::map<SVString, COsgView*> ListOsgView;
	private:
		ListOsgView m_lstOsgView; // 视图集合对象
		osgViewer::CompositeViewer* m_pCompositeViewer; // 视图集合
	};
}

#endif // !_OSGVIEWER_H_