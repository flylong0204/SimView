/**************************************************
outher: LJ
time: 2015-11-02
use: �ṩOSG���߳�����Ⱦ
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
		// ���캯��
		explicit COsgViewerThread(COsgViewer* pOsgViewer);
		// ��������
		virtual ~COsgViewerThread();

	protected:
		// ���д�����
		virtual void Run(void);

	private:
		COsgViewer* m_pOsgViewer; // ��ͼ����
		bool m_bDone; // �Ƿ���Ⱦ���
	};

}

#endif // !_OSGVIEWERTHREAD_H_