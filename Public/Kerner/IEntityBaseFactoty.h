/**************************************************
outher: LJ
time: 2016-03-15
use: the base of Entity
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IENTITYBASEFACTORY_H_
#define _PUBLIC_IENTITYBASEFACTORY_H_

namespace SimView
{
	class KERNER_EXPORT IEntityBaseFactory
	{
	public:
		// 析构函数
		virtual ~IEntityBaseFactory() { }
		// 获得路径
		virtual SVString GetPath(void) const = 0;
		// 设置路径
		virtual void SetPath(const SVString& strPath) = 0;
		// 获得类型
		virtual const SVString GetType(void) const = 0;
		// 获得工厂名称 即实体名称
		virtual const SVString& GetInstanceName(void) const = 0;
		// 添加工厂
		virtual void Add(IEntityBaseFactory* pIEntityBaseFactory) = 0;
		// 溢出工厂
		virtual void Remove(IEntityBaseFactory* pIEntityBaseFactory) = 0;
		// 设置父类
		virtual void SetParent(IEntityBaseFactory* pIEntityBaseFactory) = 0;
		// 获得父类
		virtual IEntityBaseFactory* GetParent(void) const = 0;
	};
}

#endif // !_PUBLIC_IENTITYBASEFACTORY_H_