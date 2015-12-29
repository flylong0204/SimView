/**************************************************
outher: LJ
time: 2015-11-02
use: 提供OSG在线程中渲染
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGVIEWERTHREAD_H_
#define _OSGVIEWERTHREAD_H_


#pragma once

namespace SimView
{
	class COsgViewer;

	class COsgViewerThread : public CSimViewThread
	{
	public:
		// 构造函数
		explicit COsgViewerThread(COsgViewer* pOsgViewer);
		// 析构函数
		virtual ~COsgViewerThread();

	protected:
		// 运行处理函数
		virtual void Run(void);

	private:
		COsgViewer* m_pOsgViewer; // 视图对象
		bool m_bDone; // 是否渲染完毕
	};

}

#endif // !_OSGVIEWERTHREAD_H_