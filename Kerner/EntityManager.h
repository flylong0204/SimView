/**************************************************
outher: LJ
time: 2016-03-15
use: ����ʵ������ݼ�
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
		// ����ʵ��
		void Add(IEntity* pIEntity);
		// �Ƴ�ʵ��
		void Remove(IEntity* pIEntity);
		// ���ʵ��λ��
		int GetIndex(IEntity* pIEntity) const;
		// ͨ��λ�û��ʵ��
		IEntity* GetEntity(const int index);
		


	private:
		SIMVIEW_AUTO_MUTEX // ����Ĭ����

		ListEntitys m_lstEntitys; // ʵ�����

		
	};

}

#endif // !_ENTITYMANGER_H_