/**************************************************
outher: LJ
time: 2015-11-01
use: 线程基类
from:
chanage:
change outher :
**************************************************/
#ifndef _PUBLIC_SIMVIEWTHREAD_H_
#define _PUBLIC_SIMVIEWTHREAD_H_

#pragma once

namespace boost
{
	class thread;
}

namespace SimView
{
	class KERNER_EXPORT CSimViewThread
	{
	public:
		// 构造函数
		explicit CSimViewThread();
		// 析构函数
		virtual ~CSimViewThread();
		// 设置线程结束
		void Join(void);
		// 启动线程
		void Start(void);
		// 线程挂起
		void ResumeThread(bool bResume);

	protected:
		// 循环函数
		virtual void Run(void);

	private:
		// 循环函数
		void RunLoop(void);

	private:
		bool m_bFinsh;
		bool m_bResume;
		boost::thread* m_pThread; // boost线程库
	};

}

#endif // !_PUBLIC_SIMVIEWTHREAD_H_