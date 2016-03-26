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
		// 创建属性项
		virtual IAttributeItem* CreateAttributeItem(IAttribute* pIAttribute, const SVString& strItemName, const SVString& strText, const SVString& strUntil, \
			const Variant& var, const Contrl ct = CTRL_SPINBOX);
		// 创建配置文件操作类
		virtual IConfigFileUtil* CreateConfigFileUtil(void);
		// 获得可执行程序路径
		virtual SVString GetModulePath(void) const;

	public:
		// 设置可执行程序路径
		void SetModuleDir(const SVString& strModuleDir);

	protected:
		// 初始化
		void Init(void);

	private:
		ILogManage* m_pILogManage; // 日志管理
		IPluginManage* m_pIPluginManage; // 插件管理
		IDynLibManage* m_pIDynLibManage; // 导入库管理
		CComEnumerator* m_pComEnumerator; // 实体管理

		SVString m_strModuleDir; // 可执行程序所在路径
	};

}
#endif // !_APPLICATION_H_
