/**************************************************
outher: LJ
time: 2015-10-24
use: ������ڽӿ�
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_IAPPLICATION_H_
#define _PUBLICE_IAPPLICATION_H_

namespace SimView
{
	class KERNER_DLL IApplication : public CSingleton<IApplication>
	{
	public:
		// ��������
		virtual ~IApplication(void) { }
		// ����guid ÿ�λ�ö����µ�ֵ
		virtual long_l GenerateGuid(void) = 0;
	};

	// ����ʵ�� �򵥹���
	SIMVIEW_EXTERN_C KERNER_DLL IApplication* CreateApplication(void);
}

#endif //  _PUBLICE_IAPPLICATION_H_