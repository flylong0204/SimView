/**************************************************
outher: LJ
time: 2015-10-24
use: ��̬������ӿ�
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_IDYNLIBMANAGE_H_
#define  _PUBLICE_IDYNLIBMANAGE_H_

namespace SimView
{
	class KERNER_DLL IDynLibManage : public CSingleton<IDynLibManage>
	{
	public:
		// ��������
		virtual ~IDynLibManage(void) { }
		// ���붯̬��
		virtual CDynamicLib* Load(const SVString& strDynLibName) = 0;
		// ж�ض�̬��
		virtual void UnLoad(CDynamicLib* pDynLib) = 0;
	};
}

#endif