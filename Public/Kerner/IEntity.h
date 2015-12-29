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

namespace SimView
{
	class IEntity
	{
	public:
		// 析构函数
		virtual ~IEntity(void) { }
		// 添加
		virtual void Add(IEntity* pIEntity) = 0;
		// 移除
		virtual void Remove(IEntity* pIEntity) = 0;
		// 获得子类
		virtual IEntity* GetChild(int index) = 0;
	};
}

#endif // ! _PUBLIC_IENTITY_H_