/**************************************************
outher: LJ
time: 2016-03-25
use: �����ļ�������ӿ�
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_ICONFIGFILEUTIL_H_
#define _PUBLIC_ICONFIGFILEUTIL_H_

namespace SimView
{
	class KERNER_EXPORT IConfigFileUtil
	{
	public:
		// ��������
		virtual ~IConfigFileUtil(void) { }
		// �������ļ�
		virtual bool OpenFile(const SVString& strConfigFile) = 0;
		// �ر��ļ�
		virtual void CloseFile(void) = 0;
		// ��ȡ�ļ����ƶ�Ӧ���ֵ
		virtual SVString GetItemValue(const SVString& strName, const SVString& strItem) const = 0;
		// ��ȡ�ļ�
		virtual void ReadConfig(void) = 0;
	};
}

#endif // !_PUBLIC_ICONFIGFILEUTIL_H_
