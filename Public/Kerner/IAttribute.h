/**************************************************
outher: LJ
time: 2016-03-23
use: 属性接口
from:
chanage:
change outher :
**************************************************/
#ifndef _PUBLIC_IATTRIBUTE_H_
#define _PUBLIC_IATTRIBUTE_H_

namespace SimView
{
	class KERNER_EXPORT IAttribute
	{
	public:
		typedef std::list<IAttributeItem* > LstAttrItems;

	public:
		// 析构函数
		virtual ~IAttribute(void) { }
		// 初始化属性
		virtual void Init(void) = 0;
		// 获得模型对象
		virtual IEntity* GetEntity(void) const = 0;
		// 获得名称
		virtual const SVString& GetName(void) const = 0;
		// 设置名称
		virtual void SetName(const SVString& strName) = 0;
		// 获得属性列表
		virtual const LstAttrItems& GetAttrItems(void) const = 0;
		// 通过属性的名称获取属性项
		virtual IAttributeItem* GetItem(const SVString& strName) const = 0;
		// 设置属性
		virtual void AddAttrItem(IAttributeItem* pIItem) = 0;
		// 写入内存中
		//virtual void WriteMemory(void);
	};
}

#endif // !_PUBLIC_IATTRIBUTE_H_
