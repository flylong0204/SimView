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

	// 打开配置文件
	bool CConfigFileUtil::OpenFile(const SVString& strFile)
	{
		m_strConfigFile = strFile;

		 // 判断是否已经打开
		if (!m_fileOperator.is_open())
		{
			m_fileOperator.open(m_strConfigFile);
		}

		 // 写入日志
		//ILogManager* pLog = IComManager::GetInstance().GetLogManager();
		// 判断是否已经打开
		if (!m_fileOperator.is_open())
		{
			ILogManage::GetSingleton().RecordLog("打开配置文件：" + m_strConfigFile + "失败");
			return (false);
		}
		
		return m_fileOperator.is_open();
	}

	// 关闭文件
	void CConfigFileUtil::CloseFile(void)
	{
		//// 判断是否打开
		//if (NULL == m_pFile)
		//{
		//	return;
		//}

		//fclose(m_pFile);
		if (m_fileOperator.is_open())
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("关闭配置文件：" + m_strConfigFile);
			m_fileOperator.close();
		}
	}

	// 获取文件名称对应项的值
	SVString CConfigFileUtil::GetItemValue(const SVString& strName, const SVString& strItem) const
	{
		SVString strItemName = strName;
		Trim(strItemName);

		SVString strItemValue = strItem;
		Trim(strItemValue);
		// 通过名称查询项
		MapStrItem::const_iterator cstItor = m_mapStrItem.find(strItemName);
		if (m_mapStrItem.end() == cstItor)
		{
			return ("");
		}

		// 转换项目
		const LstItemValue& itemValue = cstItor->second;
		// 查询值
		LstItemValue::const_iterator cstItorValue = std::find(itemValue.begin(), itemValue.end(), strItemValue);
		if (itemValue.end() == cstItorValue)
		{
			return ("");
		}

		// 返回值
		return (cstItorValue->strValue);
		//return "";
	}

	// 读取文件
	void CConfigFileUtil::ReadConfig(void)
	{
		// 判断是否打开
		if (!m_fileOperator.is_open())
		{
			// 写入日志
			ILogManage::GetSingleton().RecordLog("读取配置文件：" + m_strConfigFile + "失败");
			return;
		}
		// 写入日志
		ILogManage::GetSingleton().RecordLog("读取配置文件：" + m_strConfigFile);

		SVString strItemName;
		// 读取文件
		while (!m_fileOperator.eof())
		//while (!feof(m_pFile))
		{
			char szLine[256] = { 0 };
			m_fileOperator.getline(szLine, sizeof(char) * 256);

			SVString strLeftNoSpace = Trim(SVString(szLine));
			// 判断是否为空行
			if (strLeftNoSpace.empty())
			{
				continue;
			}

			// 判断是否为注释行 #
			if (strLeftNoSpace[0] == '#')
			{
				continue;
			}

			// 读取名称
			if (ReadItemName(strLeftNoSpace, strItemName))
			{
				continue;
			}

			SVString strName, strValues;
			if (!ReadItem(strLeftNoSpace, strName, strValues))
			{
				continue;
			}

			// 添加到表中
			AddItem(strItemName, strName, strValues);
		}

		// 写入日志
		ILogManage::GetSingleton().RecordLog("读取配置文件：" + m_strConfigFile + " 完毕");
	}

	// 读取项目名称
	bool CConfigFileUtil::ReadItemName(const SVString& strText, SVString& strName)
	{
		// 判断是否含有'[ ]'
		int nBeginPos = strText.find_first_of('[');
		int nEndPos = strText.find_last_of(']');

		if ((-1 == nBeginPos) && (-1 == nEndPos) && (nBeginPos <= nEndPos))
		{
			return (false);
		}

		// 获取名称
		strName = strText.substr(nBeginPos + 1, nEndPos - 1);

		return (true);
	}

	// 读取项
	bool CConfigFileUtil::ReadItem(const SVString& strText, SVString& strName, SVString& strValue)
	{
		// 查询是否含有‘=’
		int nPos = strText.find('=');
		if (-1 == nPos)
		{
			return (false);
		}

		// 获取字符串长度
		int nLength = strText.length();
		// 获取名称
		strName = strText.substr(0, nPos);
		strValue = strText.substr(nPos + 1, nLength - nPos);

		// 清除两遍空格
		strName = Trim(strName);
		strValue = Trim(strValue);
		return (true);
	}

	// 添加项
	void CConfigFileUtil::AddItem(const SVString& strName, const SVString& strValueName, const SVString& strValue)
	{
		ITEMVALUE value(strValueName, strValue);
		// 查询是否存在当前的项目名称
		MapStrItem::iterator itor = m_mapStrItem.find(strName);
		if (m_mapStrItem.end() != itor)
		{
			LstItemValue& itemValue = itor->second;
			itemValue.push_back(value);
		}
		else
		{
			// 创建项值
			LstItemValue itemValue;
			itemValue.push_back(value);
			m_mapStrItem[strName] = itemValue;
		}
	}

	// 去掉所有的空格
	SVString CConfigFileUtil::Trim(SVString& strLine) const
	{
		int nPos = strLine.find_last_not_of(g_strSpace);
		SVString str = strLine.erase(strLine.find_last_not_of(g_strSpace) + 1);
		return (str.erase(0, str.find_first_not_of(g_strSpace)));
	}

	// 去掉左边的空格
	SVString CConfigFileUtil::LeftTrim(SVString& strLine) const
	{
		return (strLine.erase(strLine.find_first_not_of(g_strSpace)));
	}

	// 去掉右边的空格
	SVString CConfigFileUtil::RightTrim(SVString& strLine) const
	{
		return (strLine.erase(strLine.find_last_not_of(g_strSpace) + 1));
	}

}
