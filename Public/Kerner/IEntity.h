/**************************************************
outher: LJ
time: 2015-12-29
use: the base of Entity
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IENTITY_H_
#define _PUBLIC_IENTITY_H_

#include <vector>

namespace SimView
{
	class IAttribute;
	class IBaseAttribute;
	class IDrawAttribute;
	class IDrawManager;
	class IStateMachine;
	class IMessage;
	
	class KERNER_EXPORT IEntity
	{
	public:
		typedef std::vector<IAttribute*> ListAttributes;

	public:
		// 析构函数
		virtual ~IEntity(void) { }
		// 设置名称
		virtual void SetName(const SVString& strName) = 0;
		// 获得名称
		virtual SVString GetName(void) const = 0;
		// 设置ID
		virtual void SetID(const ulong_l uID) = 0;
		// 获得ID
		virtual ulong_l GetID(void) const = 0;

		// 属性接口
	public:
		// 设置实体基本属性
		virtual void SetBaseAttribute(IBaseAttribute* pIBaseAttribute) = 0;
		// 获得基本属性对象
		virtual IBaseAttribute* GetBaseAttribute(void) const = 0;
		// 设置渲染属性
		virtual void AddDrawAttribute(IDrawAttribute* pIDrawAttribute) = 0;
		// 获得渲染属性
		virtual IDrawAttribute* GetDrawAttribute(const SVString& strName) = 0;
		// 移除属性
		virtual void RemoveDrawAttribute(IAttribute* pIAttribute) = 0;
		// 设置渲染管理
		virtual void SetDrawManager(IDrawManager* pIDrawManager) = 0;
		// 获得渲染管理
		virtual IDrawManager* GetDrawManager(void) const = 0;

		// 更新相关
	public:
		// 更新
		virtual void Update(void) = 0;


		// 消息相关
	public:
		// 处理消息
		virtual bool HandleMessage(const IMessage* pIMessage) = 0;
		// 获得状态机
		virtual IStateMachine* GetStateMachine(void) const = 0;
		// 设置状态机
		virtual void SetStateMachine(IStateMachine* pIStateMachine) = 0;
		// 初始化状态机
		virtual void InitStateMachine(IStateMachine* pIStateMachine) = 0;

	};
}

#endif // ! _PUBLIC_IENTITY_H_