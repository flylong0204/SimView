/**************************************************
outher: LJ
time: 2016-03-25
use: �����ļ�������
from:
chanage:
change outher :
**************************************************/

#ifndef _CONFIGFILEUTIL_H_
#define _CONFIGFILEUTIL_H_

#pragma once

namespace SimView
{
	typedef struct ITEMVALUE_TYP
	{
		SVString strItem; // ������
		SVString strValue; // ֵ

		ITEMVALUE_TYP(SVString item, SVString value) :strItem(item), strValue(value)
		{

		}

		bool operator== (const SVString item)
		{
			return (strItem.compare(item) == 0);
		}

		bool operator== (const SVString item) const
		{
			return (strItem.compare(item) == 0);
		}
	}ITEMVALUE, *PTR_ITEMVALUE;

	class CConfigFileUtil : public IConfigFileUtil
	{
	public:
		// ���캯��
		explicit CConfigFileUtil(void);
		// ��������
		virtual ~CConfigFileUtil(void);

	public:
		// �������ļ�
		virtual bool OpenFile(const SVString& strConfigFile);
		// �ر��ļ�
		virtual void CloseFile(void);
		// ��ȡ�ļ����ƶ�Ӧ���ֵ
		virtual SVString GetItemValue(const SVString& strName, const SVString& strItem) const ;
		// ��ȡ�ļ�
		virtual void ReadConfig(void);

	protected:
		typedef std::list<ITEMVALUE> LstItemValue;
		typedef std::map<SVString, LstItemValue > MapStrItem;

		// ��ȡ��Ŀ����
		bool ReadItemName(const SVString& strText, SVString& strName);
		// ��ȡ��
		bool ReadItem(const SVString& strText, SVString& strName, SVString& strValue);
		// �����
		void AddItem(const SVString& strName, const SVString& strValueName, const SVString& strValue);
		// ȥ�����еĿո�
		SVString Trim(SVString& strLine) const;
		// ȥ����ߵĿո�
		SVString LeftTrim(SVString& strLine) const;
		// ȥ���ұߵĿո�
		SVString RightTrim(SVString& strLine) const;
		
	private:
		SVString m_strConfigFile; // �����ļ�
		std::ifstream m_fileOperator; // �ļ�������
		MapStrItem m_mapStrItem; // ���Ӧ����
	};
}

#endif // !_CONFIGFILEUTIL_H_