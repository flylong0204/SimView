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
	class KERNER_EXPORT IApplication : public CSingleton<IApplication>
	{
	public:
		// ��������
		virtual ~IApplication(void) { }
		// ����guid ÿ�λ�ö����µ�ֵ
		virtual long_l GenerateGuid(void) = 0;
		// ����������
		virtual IAttributeItem* CreateAttributeItem(IAttribute* pIAttribute, const SVString& strItemName, const SVString& strText, const SVString& strUntil, \
			const Variant& var, const Contrl ct = CTRL_SPINBOX) = 0;
		// ���������ļ�������
		virtual IConfigFileUtil* CreateConfigFileUtil(void) = 0;
		// ��ÿ�ִ�г���·��
		virtual SVString GetModulePath(void) const = 0;
	};

	// ����ʵ�� �򵥹���
	SIMVIEW_EXTERN_C KERNER_EXPORT IApplication* CreateApplication(int argc, char *argv[]);
}

#endif //  _PUBLICE_IAPPLICATION_H_