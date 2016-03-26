/**************************************************
outher: LJ
time: 2016-03-25
use: 配置文件操作类接口
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
		// 析构函数
		virtual ~IConfigFileUtil(void) { }
		// 打开配置文件
		virtual bool OpenFile(const SVString& strConfigFile) = 0;
		// 关闭文件
		virtual void CloseFile(void) = 0;
		// 获取文件名称对应项的值
		virtual SVString GetItemValue(const SVString& strName, const SVString& strItem) const = 0;
		// 读取文件
		virtual void ReadConfig(void) = 0;
	};
}

#endif // !_PUBLIC_ICONFIGFILEUTIL_H_
