/**************************************************
outher: LJ
time: 2016-03-23
use: ״̬���ӿ�
from: ����ԭ�����ԡ���Ϸ�˹����ܱ�̰������⡷һ��     
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_ISTATEMACHINE_H_
#define _PUBLIC_ISTATEMACHINE_H_

namespace SimView
{
	class KERNER_EXPORT IStateMachine
	{
	public:
		// ��������
		virtual ~IStateMachine() { }

		// ���õ�ǰ״̬
		virtual void SetCurrentState(IState* pIState) = 0;
		// ������һ״̬
		virtual void SetPreviousState(IState* pIState) = 0;
		// ����ȫ��״̬
		virtual void SetGlobalState(IState* pIState) = 0;
		// ��õ�ǰ״̬
		virtual IState* GetCurrentState(void) const = 0;
		// �����һ״̬
		virtual IState* GetPreviousState(void) const = 0;
		// ���ȫ��״̬
		virtual IState* GetGlobalState(void) const = 0;

		// ������Ϣ
		virtual bool HandleMessage(const IMessage* pIMsg) = 0;
		// ����״̬
		virtual void RevertToPreviousState(void) = 0;
		// �ı�״̬
		virtual void ChangeState(IState* pINewState) = 0;
		// ���״̬����
		virtual SVString GetStateName(void) = 0;
		// �ж��Ƿ�Ϊͬһ��״̬
		virtual bool IsInState(IState* pIState) = 0;

	public:
		// ����״̬
		virtual void Update(void) = 0;
	};
}

#endif // !_PUBLIC_ISTATEMACHINE_H_
