/**************************************************
outher: LJ
time: 2015-11-01
use: osg��Ⱦ������ �ṩ������Ⱦ�����̺߳��ⲿ������Ⱦ�����綨ʱ�����ã�
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
		// ����һ����ͼ
		virtual void Create(IOsgViewConfig* pIOsgViewConfig);
		// �����ͼ����
		virtual IOsgView* GetView(const SVString& strName) const;

	public:
		// ��������ͼ
		osgViewer::CompositeViewer* GetViewer(void) const;
		// ÿһ֡ǰ��Ҫ����ĺ���
		void PreFrameUpdate(void);
		// ÿһ֡��Ҫ����ĺ���
		void PostFrameUpdate(void);

	protected:
		// �����ͼ
		void AddOsgView(COsgView* pOsgView);
		// �Ƴ���ͼ
		void RemoveView(COsgView* pOsgView);

	protected:
		typedef std::map<SVString, COsgView*> ListOsgView;
	private:
		ListOsgView m_lstOsgView; // ��ͼ���϶���
		osgViewer::CompositeViewer* m_pCompositeViewer; // ��ͼ����
	};
}

#endif // !_OSGVIEWER_H_