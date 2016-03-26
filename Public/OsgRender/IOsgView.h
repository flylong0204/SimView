/**************************************************
outher: LJ
time: 2015-11-01
use: osg��Ⱦ��ӿ�
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IOSGVIEW_H_
#define _PUBLIC_IOSGVIEW_H_

namespace SimView
{
#define SVView void
#define CameraManip void // ���������

	class OSGRENDER_EXPORT IOsgView
	{
	public:
		// ��������
		virtual ~IOsgView() { }
		// �����ͼ
		virtual SVView* GetView(void) const = 0;
		// ��ӽڵ�
		virtual void AddRenderObj(DrawObj* pRenderObj) = 0;
		// ������������
		virtual void AddCameraManipulator(const SVString& strName, CameraManip* pCameraManip) = 0;
		// ѡ�������
		virtual void SelectCameraManipulator(const SVString& strName) = 0;
	};
}

#endif // !_PUBLIC_IOSGVIEW_H_
