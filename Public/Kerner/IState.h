/**************************************************
outher: LJ
time: 2016-03-23
use: 状态接口
from: 代码原理来自《游戏人工智能编程案例精粹》一书
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
		// 进入状态
		virtual void Enter(IEntity* pEntityBase) = 0;
		// 执行状态
		virtual void Execute(IEntity* pEntityBase) = 0;
		// 离开状态
		virtual void Exit(IEntity* pEntityBase) = 0;

		// 消息处理
		virtual bool OnMessage(IEntity* pEntityBase, const IMessage* pMessage) = 0;

	};
}
#endif // !_PUBLICE_ISTATE_H_
