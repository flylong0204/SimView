/**************************************************
outher: LJ
time: 2015-10-24
use: 程序入口接口
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
		// 析构函数
		virtual ~IApplication(void) { }
		// 产生guid 每次获得都是新的值
		virtual long_l GenerateGuid(void) = 0;
		// 创建属性项
		virtual IAttributeItem* CreateAttributeItem(IAttribute* pIAttribute, const SVString& strItemName, const SVString& strText, const SVString& strUntil, \
			const Variant& var, const Contrl ct = CTRL_SPINBOX) = 0;
		// 创建配置文件操作类
		virtual IConfigFileUtil* CreateConfigFileUtil(void) = 0;
		// 获得可执行程序路径
		virtual SVString GetModulePath(void) const = 0;
	};

	// 创建实例 简单工厂
	SIMVIEW_EXTERN_C KERNER_EXPORT IApplication* CreateApplication(int argc, char *argv[]);
}

#endif //  _PUBLICE_IAPPLICATION_H_