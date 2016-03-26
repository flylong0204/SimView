/**************************************************
outher: LJ
time: 2015-11-01
use: Osg��Ⱦ�����
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
		// ���캯��
		explicit COsgRender(void);
		// ��������
		virtual ~COsgRender(void);

	public:
		// ������ͼ
		virtual void CreateView(IOsgViewConfig* pIOsgViewConfig);
		// �����ͼ
		virtual IOsgView* GetView(const SVString& strViewName) const;
		// �����Ⱦ�ڵ�
		virtual void AddRenderObj(DrawObj* pRenderObj, const SVString& strViewName = "MainView");

	public:
		// �����������
		virtual void SetName(const SVString& strName);
		// ����������
		virtual const SVString& GetName(void) const;
		// �������
		virtual const SVString& GetTypeName(void) const;
		// ����ʱ���ó�ʼ��
		virtual void Init(void);

	public:
		// �����߳�����
		virtual void RunByThread(void);

	private:
		SVString m_strName;
		COsgViewer* m_pOsgViewer; // ��ͼ���
		COsgViewerThread* m_pOsgViewerThread; // �߳�ָ��
	};

	// ��������
	CREATE_COMBASEFACTORY(COsgRender, COMTYPE_OSGRENDER, COMNAME_OSGRENDER, COMDIR_OSGRENDER)
}

#endif // !_OSGRENDER_H_