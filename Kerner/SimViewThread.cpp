#define SIMVIEW_KERNERLIB
#include <boost/function.hpp>
#include "../Public/Kerner/Kerner.h"

namespace SimView
{
	// 构造函数
	CSimViewThread::CSimViewThread()
		:m_bFinsh(false), m_bResume(false), m_pThread(NULL)
	{
	}

	// 析构函数
	CSimViewThread::~CSimViewThread()
	{
		SIMVIEW_DELETE(m_pThread);
	}

	// 循环函数
	void CSimViewThread::RunLoop(void)
	{
		while (!m_bFinsh)
		{
			if (m_bResume)
			{
				SIMVIEW_THREAD_SLEEP(5);
			}
			Run();
		}
	}

	// 设置线程结束
	void CSimViewThread::Join(void)
	{
		m_bFinsh = true;
		m_pThread->join();
	}

	// 启动线程
	void CSimViewThread::Start(void)
	{
		boost::function0<void> func = boost::bind(&CSimViewThread::RunLoop, this);
		m_pThread = new boost::thread(func);
	}

	// 循环函数
	void CSimViewThread::Run(void)
	{

	}

	// 线程挂起
	void CSimViewThread::ResumeThread(bool bResume)
	{
		m_bResume = bResume;
	}

}
