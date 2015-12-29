/**************************************************
outher: LJ
time: 2015-11-01
use: osg��Ⱦ��
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGVIEW_H_
#define _OSGVIEW_H_

#pragma once

namespace osgGA
{
	class KeySwitchMatrixManipulator;
}

namespace SimView
{
	class COsgView : public IOsgView
	{
	public:
		explicit COsgView(IOsgViewConfig* pIConfig);
		virtual ~COsgView();

	public: 
		// ��ӽڵ�
		virtual void AddRenderObj(void* pRenderObj);

	public:
		// ��ʼ��������
		void InitManipulator(void);
		// ��ʼ�����
		void InitCamera(void);

	public:
		// �������
		SVString GetName(void) const;
		// �����ͼ
		osgViewer::View* GetView(void) const;

	private:
		osg::Group* m_pGroup; // ���ڵ�
		osgViewer::View* m_pView; // osg��ͼ
		osgGA::KeySwitchMatrixManipulator* m_pKeyswitchManipulator; // ���������
		IOsgViewConfig* m_pIConfig; // ���ö���
	};
}

#endif // !_OSGVIEW_H_