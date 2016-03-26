/**************************************************
outher: LJ
time: 2016-03-15
use: 实体工厂管理类， 进行实体工程实例化的管理
from: 
chanage:
change outher :
**************************************************/

#pragma once

#include <vector>

namespace SimView
{
	class CEntityFactoryManager : public IEntityFactoryType
	{
	public:
		explicit CEntityFactoryManager(void);
		~CEntityFactoryManager();

	public:
		// 获得路径
		virtual SVString GetPath(void) const;
		// 设置路径
		virtual void SetPath(const SVString& strPath);
		// 获得类型
		virtual const SVString GetType(void) const;
		// 获得工厂名称 即实体名称
		virtual const SVString& GetInstanceName(void) const;
		// 添加工厂
		virtual void Add(IEntityBaseFactory* pIEntityBaseFactory);
		// 移除出工厂
		virtual void Remove(IEntityBaseFactory* pIEntityBaseFactory);
		// 获得子所有的工厂
		virtual IEntityFactoryType::ListEntityFactorys GetChilds(void) const;
		// 设置父类
		virtual void SetParent(IEntityBaseFactory* pIEntityBaseFactory);
		// 获得父类
		virtual IEntityBaseFactory* GetParent(void) const;

	protected:
		// 是否包含了 该组件
		bool IsHand(const SVString& strPath);

	private:
		IEntityBaseFactory* m_pIParent; // 父类指针
		SVString m_strPath; // 路径
		SVString m_strName; // 工厂名称
		ListEntityFactorys m_lstEntityFactorys; // 子元素列表

	};
}


