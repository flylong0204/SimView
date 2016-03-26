/**************************************************
outher: LJ
time: 2015-11-01
use: �̻߳���
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
		// ���캯��
		explicit CSimViewThread();
		// ��������
		virtual ~CSimViewThread();
		// �����߳̽���
		void Join(void);
		// �����߳�
		void Start(void);
		// �̹߳���
		void ResumeThread(bool bResume);

	protected:
		// ѭ������
		virtual void Run(void);

	private:
		// ѭ������
		void RunLoop(void);

	private:
		bool m_bFinsh;
		bool m_bResume;
		boost::thread* m_pThread; // boost�߳̿�
	};

}

#endif // !_PUBLIC_SIMVIEWTHREAD_H_