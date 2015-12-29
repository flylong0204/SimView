#define SIMVIEW_KERNERLIB
#include <boost/function.hpp>
#include "../Public/Kerner/Kerner.h"

namespace SimView
{
	// ���캯��
	CSimViewThread::CSimViewThread()
		:m_bFinsh(false), m_bResume(false), m_pThread(NULL)
	{
	}

	// ��������
	CSimViewThread::~CSimViewThread()
	{
		SIMVIEW_DELETE(m_pThread);
	}

	// ѭ������
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

	// �����߳̽���
	void CSimViewThread::Join(void)
	{
		m_bFinsh = true;
		m_pThread->join();
	}

	// �����߳�
	void CSimViewThread::Start(void)
	{
		boost::function0<void> func = boost::bind(&CSimViewThread::RunLoop, this);
		m_pThread = new boost::thread(func);
	}

	// ѭ������
	void CSimViewThread::Run(void)
	{

	}

	// �̹߳���
	void CSimViewThread::ResumeThread(bool bResume)
	{
		m_bResume = bResume;
	}

}
