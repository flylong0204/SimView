/**************************************************
outher: LJ
time: 2015-10-24
use: 程序入口 
from:
chanage:
change outher :
**************************************************/

#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#pragma once

namespace SimView
{
	class CComEnumerator;

	class CApplication : public IApplication
	{
	public:
		// 构造函数
		explicit CApplication(void);
		// 析构函数
		virtual ~CApplication(void);

	public:
		// 产生guid 每次获得都是新的值
		virtual long_l GenerateGuid(void);

	protected:
		// 初始化
		void Init(void);

	private:
		ILogManage* m_pILogManage; // 日志管理
		IPluginManage* m_pIPluginManage; // 插件管理
		IDynLibManage* m_pIDynLibManage; // 导入库管理
		CComEnumerator* m_pComEnumerator; // 实体管理
	};

}
#endif // !_APPLICATION_H_
