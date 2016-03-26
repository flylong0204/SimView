/**************************************************
outher: LJ
time: 2016-03-23
use: 消息接口
from: 代码原理来自《游戏人工智能编程案例精粹》一书
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
		// 析构函数
		virtual ~IMessage(void) { }
		// 设置发送者
		virtual void SetSender(ulong_l uID) = 0;
		// 获得发送者
		virtual IEntity* GetSender(void) const = 0;
		// 设置接收者
		virtual void SetReceiver(ulong_l uID) = 0;
		// 获得接受者
		virtual IEntity* GetReceiver(void) const = 0;
		// 设置消息
		virtual void SetMessage(uint_l uMsg) = 0;
		// 获得消息
		virtual uint_l GetMessage(void) const = 0;
		// 设置处理时间
		virtual void SetDispatch(const double dDispatchTime) = 0;
		// 获得处理时间
		virtual double GetDispatch(void) const = 0;
		// 设置扩展消息
		virtual void SetExpendInfo(void* pExInfo) = 0;
		// 获得扩展消息
		virtual void* GetExpendInfo(void) const = 0;
	};
}

#endif // !_PUBLIC_IMESSAGE_H_
