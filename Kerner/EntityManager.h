/**************************************************
outher: LJ
time: 2016-03-15
use: 所有实体的数据集
from: 
chanage:
change outher :
**************************************************/

#ifndef _ENTITYMANGER_H_
#define _ENTITYMANGER_H_

#pragma once

#include <list>

namespace SimView
{

	class IEntity;

	class CEntityManager 
	{
	public:
		typedef std::list<IEntity*> ListEntitys;

	public:
		CEntityManager();
		~CEntityManager();

	public:
		// 加入实体
		void Add(IEntity* pIEntity);
		// 移除实体
		void Remove(IEntity* pIEntity);
		// 获得实体位置
		int GetIndex(IEntity* pIEntity) const;
		// 通过位置获得实体
		IEntity* GetEntity(const int index);
		


	private:
		SIMVIEW_AUTO_MUTEX // 用于默认锁

		ListEntitys m_lstEntitys; // 实体管理集

		
	};

}

#endif // !_ENTITYMANGER_H_