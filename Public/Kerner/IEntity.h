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
		// ��������
		virtual ~IEntity(void) { }
		// ���
		virtual void Add(IEntity* pIEntity) = 0;
		// �Ƴ�
		virtual void Remove(IEntity* pIEntity) = 0;
		// �������
		virtual IEntity* GetChild(int index) = 0;
	};
}

#endif // ! _PUBLIC_IENTITY_H_