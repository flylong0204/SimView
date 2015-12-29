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
	class KERNER_DLL IApplication : public CSingleton<IApplication>
	{
	public:
		// 析构函数
		virtual ~IApplication(void) { }
		// 产生guid 每次获得都是新的值
		virtual long_l GenerateGuid(void) = 0;
	};

	// 创建实例 简单工厂
	SIMVIEW_EXTERN_C KERNER_DLL IApplication* CreateApplication(void);
}

#endif //  _PUBLICE_IAPPLICATION_H_