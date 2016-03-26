/**************************************************
outher: LJ
time: 2016-03-25
use: 配置文件操作类
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
		SVString strItem; // 项名称
		SVString strValue; // 值

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
		// 构造函数
		explicit CConfigFileUtil(void);
		// 析构函数
		virtual ~CConfigFileUtil(void);

	public:
		// 打开配置文件
		virtual bool OpenFile(const SVString& strConfigFile);
		// 关闭文件
		virtual void CloseFile(void);
		// 获取文件名称对应项的值
		virtual SVString GetItemValue(const SVString& strName, const SVString& strItem) const ;
		// 读取文件
		virtual void ReadConfig(void);

	protected:
		typedef std::list<ITEMVALUE> LstItemValue;
		typedef std::map<SVString, LstItemValue > MapStrItem;

		// 读取项目名称
		bool ReadItemName(const SVString& strText, SVString& strName);
		// 读取项
		bool ReadItem(const SVString& strText, SVString& strName, SVString& strValue);
		// 添加项
		void AddItem(const SVString& strName, const SVString& strValueName, const SVString& strValue);
		// 去掉所有的空格
		SVString Trim(SVString& strLine) const;
		// 去掉左边的空格
		SVString LeftTrim(SVString& strLine) const;
		// 去掉右边的空格
		SVString RightTrim(SVString& strLine) const;
		
	private:
		SVString m_strConfigFile; // 配置文件
		std::ifstream m_fileOperator; // 文件操作器
		MapStrItem m_mapStrItem; // 项对应名称
	};
}

#endif // !_CONFIGFILEUTIL_H_