/**************************************************
outher: LJ
time: 2016-03-23
use: ״̬�ӿ�
from: ����ԭ�����ԡ���Ϸ�˹����ܱ�̰������⡷һ��
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_ISTATE_H_
#define _PUBLICE_ISTATE_H_

namespace SimView
{
	class KERNER_EXPORT IState
	{
	public:
		virtual ~IState() { }
		// ����״̬
		virtual void Enter(IEntity* pEntityBase) = 0;
		// ִ��״̬
		virtual void Execute(IEntity* pEntityBase) = 0;
		// �뿪״̬
		virtual void Exit(IEntity* pEntityBase) = 0;

		// ��Ϣ����
		virtual bool OnMessage(IEntity* pEntityBase, const IMessage* pMessage) = 0;

	};
}
#endif // !_PUBLICE_ISTATE_H_
