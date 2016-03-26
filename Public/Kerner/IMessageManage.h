/**************************************************
outher: LJ
time: 2016-03-23
use: ��Ϣ�ӿ�
from: ����ԭ�����ԡ���Ϸ�˹����ܱ�̰������⡷һ��
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IMESSAGESYSTEM_H_
#define _PUBLIC_IMESSAGESYSTEM_H_

namespace SimView
{
	const double SEND_MSG_IMMEDIATELY = 0.0f;
	const int   NO_ADDITIONAL_INFO = 0L;

	class KERNER_EXPORT IMessageManage : public CSingleton<IMessageManage>
	{
	public:
		// ��������
		virtual ~IMessageManage() { }
		// ������Ϣ
		virtual void DispatchMessage(IEntity* pISender, IEntity* pIReceiver, uint_l uMsg, \
			const double delay = SEND_MSG_IMMEDIATELY, void*  ExtraInfo = NO_ADDITIONAL_INFO) = 0;
		// ������Ϣ
		virtual void DispatchMessage(const ulong_l uSender, const ulong_l uReceiver, uint_l uMsg, \
			const double delay = SEND_MSG_IMMEDIATELY, void*  ExtraInfo = NO_ADDITIONAL_INFO) = 0;
		// ��Ϣѭ��
		virtual void DispatchDelayedMessages(void) = 0;
	};
}

#endif // !_PUBLIC_IMESSAGESYSTEM_H_
