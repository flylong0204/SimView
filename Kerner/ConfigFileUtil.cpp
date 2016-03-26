#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "ConfigFileUtil.h"

namespace SimView
{
	const SVString g_strSpace = " ";// /f/n/t/r/v";

	CConfigFileUtil::CConfigFileUtil()
	{
	}

	CConfigFileUtil::~CConfigFileUtil(void)
	{
		CloseFile();
	}

	// �������ļ�
	bool CConfigFileUtil::OpenFile(const SVString& strFile)
	{
		m_strConfigFile = strFile;

		 // �ж��Ƿ��Ѿ���
		if (!m_fileOperator.is_open())
		{
			m_fileOperator.open(m_strConfigFile);
		}

		 // д����־
		//ILogManager* pLog = IComManager::GetInstance().GetLogManager();
		// �ж��Ƿ��Ѿ���
		if (!m_fileOperator.is_open())
		{
			ILogManage::GetSingleton().RecordLog("�������ļ���" + m_strConfigFile + "ʧ��");
			return (false);
		}
		
		return m_fileOperator.is_open();
	}

	// �ر��ļ�
	void CConfigFileUtil::CloseFile(void)
	{
		//// �ж��Ƿ��
		//if (NULL == m_pFile)
		//{
		//	return;
		//}

		//fclose(m_pFile);
		if (m_fileOperator.is_open())
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("�ر������ļ���" + m_strConfigFile);
			m_fileOperator.close();
		}
	}

	// ��ȡ�ļ����ƶ�Ӧ���ֵ
	SVString CConfigFileUtil::GetItemValue(const SVString& strName, const SVString& strItem) const
	{
		SVString strItemName = strName;
		Trim(strItemName);

		SVString strItemValue = strItem;
		Trim(strItemValue);
		// ͨ�����Ʋ�ѯ��
		MapStrItem::const_iterator cstItor = m_mapStrItem.find(strItemName);
		if (m_mapStrItem.end() == cstItor)
		{
			return ("");
		}

		// ת����Ŀ
		const LstItemValue& itemValue = cstItor->second;
		// ��ѯֵ
		LstItemValue::const_iterator cstItorValue = std::find(itemValue.begin(), itemValue.end(), strItemValue);
		if (itemValue.end() == cstItorValue)
		{
			return ("");
		}

		// ����ֵ
		return (cstItorValue->strValue);
		//return "";
	}

	// ��ȡ�ļ�
	void CConfigFileUtil::ReadConfig(void)
	{
		// �ж��Ƿ��
		if (!m_fileOperator.is_open())
		{
			// д����־
			ILogManage::GetSingleton().RecordLog("��ȡ�����ļ���" + m_strConfigFile + "ʧ��");
			return;
		}
		// д����־
		ILogManage::GetSingleton().RecordLog("��ȡ�����ļ���" + m_strConfigFile);

		SVString strItemName;
		// ��ȡ�ļ�
		while (!m_fileOperator.eof())
		//while (!feof(m_pFile))
		{
			char szLine[256] = { 0 };
			m_fileOperator.getline(szLine, sizeof(char) * 256);

			SVString strLeftNoSpace = Trim(SVString(szLine));
			// �ж��Ƿ�Ϊ����
			if (strLeftNoSpace.empty())
			{
				continue;
			}

			// �ж��Ƿ�Ϊע���� #
			if (strLeftNoSpace[0] == '#')
			{
				continue;
			}

			// ��ȡ����
			if (ReadItemName(strLeftNoSpace, strItemName))
			{
				continue;
			}

			SVString strName, strValues;
			if (!ReadItem(strLeftNoSpace, strName, strValues))
			{
				continue;
			}

			// ��ӵ�����
			AddItem(strItemName, strName, strValues);
		}

		// д����־
		ILogManage::GetSingleton().RecordLog("��ȡ�����ļ���" + m_strConfigFile + " ���");
	}

	// ��ȡ��Ŀ����
	bool CConfigFileUtil::ReadItemName(const SVString& strText, SVString& strName)
	{
		// �ж��Ƿ���'[ ]'
		int nBeginPos = strText.find_first_of('[');
		int nEndPos = strText.find_last_of(']');

		if ((-1 == nBeginPos) && (-1 == nEndPos) && (nBeginPos <= nEndPos))
		{
			return (false);
		}

		// ��ȡ����
		strName = strText.substr(nBeginPos + 1, nEndPos - 1);

		return (true);
	}

	// ��ȡ��
	bool CConfigFileUtil::ReadItem(const SVString& strText, SVString& strName, SVString& strValue)
	{
		// ��ѯ�Ƿ��С�=��
		int nPos = strText.find('=');
		if (-1 == nPos)
		{
			return (false);
		}

		// ��ȡ�ַ�������
		int nLength = strText.length();
		// ��ȡ����
		strName = strText.substr(0, nPos);
		strValue = strText.substr(nPos + 1, nLength - nPos);

		// �������ո�
		strName = Trim(strName);
		strValue = Trim(strValue);
		return (true);
	}

	// �����
	void CConfigFileUtil::AddItem(const SVString& strName, const SVString& strValueName, const SVString& strValue)
	{
		ITEMVALUE value(strValueName, strValue);
		// ��ѯ�Ƿ���ڵ�ǰ����Ŀ����
		MapStrItem::iterator itor = m_mapStrItem.find(strName);
		if (m_mapStrItem.end() != itor)
		{
			LstItemValue& itemValue = itor->second;
			itemValue.push_back(value);
		}
		else
		{
			// ������ֵ
			LstItemValue itemValue;
			itemValue.push_back(value);
			m_mapStrItem[strName] = itemValue;
		}
	}

	// ȥ�����еĿո�
	SVString CConfigFileUtil::Trim(SVString& strLine) const
	{
		int nPos = strLine.find_last_not_of(g_strSpace);
		SVString str = strLine.erase(strLine.find_last_not_of(g_strSpace) + 1);
		return (str.erase(0, str.find_first_not_of(g_strSpace)));
	}

	// ȥ����ߵĿո�
	SVString CConfigFileUtil::LeftTrim(SVString& strLine) const
	{
		return (strLine.erase(strLine.find_first_not_of(g_strSpace)));
	}

	// ȥ���ұߵĿո�
	SVString CConfigFileUtil::RightTrim(SVString& strLine) const
	{
		return (strLine.erase(strLine.find_last_not_of(g_strSpace) + 1));
	}

}
