/**************************************************
outher: LJ
time: 2016-03-23
use: ��Ϣ�ӿ�
from: ����ԭ�����ԡ���Ϸ�˹����ܱ�̰������⡷һ��
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IMESSAGE_H_
#define _PUBLIC_IMESSAGE_H_

namespace SimView
{
	class KERNER_EXPORT IMessage
	{
	public:
		// ��������
		virtual ~IMessage(void) { }
		// ���÷�����
		virtual void SetSender(ulong_l uID) = 0;
		// ��÷�����
		virtual IEntity* GetSender(void) const = 0;
		// ���ý�����
		virtual void SetReceiver(ulong_l uID) = 0;
		// ��ý�����
		virtual IEntity* GetReceiver(void) const = 0;
		// ������Ϣ
		virtual void SetMessage(uint_l uMsg) = 0;
		// �����Ϣ
		virtual uint_l GetMessage(void) const = 0;
		// ���ô���ʱ��
		virtual void SetDispatch(const double dDispatchTime) = 0;
		// ��ô���ʱ��
		virtual double GetDispatch(void) const = 0;
		// ������չ��Ϣ
		virtual void SetExpendInfo(void* pExInfo) = 0;
		// �����չ��Ϣ
		virtual void* GetExpendInfo(void) const = 0;
	};
}

#endif // !_PUBLIC_IMESSAGE_H_
