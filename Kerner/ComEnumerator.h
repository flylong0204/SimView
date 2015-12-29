/**************************************************
outher: LJ
time: 2015-10-25
use: 插件枚举值
from:
chanage:
change outher :
**************************************************/

#ifndef _COMENUMERATOR_H_
#define _COMENUMERATOR_H_

#pragma once

namespace SimView
{
	class CComEnumerator : public CSingleton<CComEnumerator>
	{
	public:
		// 构造函数
		explicit CComEnumerator(void);
		// 析构函数
		virtual ~CComEnumerator(void);

	public:
		// 添加工厂对象
		void AddFactory(IComBaseFactory* pIFactory);
		// 移除工厂对象
		void RemoveFactory(IComBaseFactory* pIFactory);
		// 创建实例
		IComFaceBase* CreateComInstance(const SVString& strTypeName, const SVString& strName);
		// 获得实例
		IComFaceBase* GetComInstance(const SVString& strName) const;
		// 是否存在当前插件
		bool HasComInstance(const SVString& strName) const;
		// 卸载所有插件
		void ShutAll(void);

	private:
		typedef std::map<SVString, IComFaceBase*> ListInstaces; // 实体类型
		typedef std::list<IComBaseFactory*> ListFactorys; // 工厂类型
		typedef std::vector<const ComFaceBaseData*> ListComDatas; // 数据类型

		ListInstaces m_listInstances; // 实体对象集合
		ListFactorys m_listFactorys; // 工厂对象集合
		ListComDatas m_listComData; // 数据工厂集合

	};
}

#endif // !_COMENUMERATOR_H_