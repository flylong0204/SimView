/**************************************************
outher: LJ
time: 2016-03-23
use: 状态机接口
from: 代码原理来自《游戏人工智能编程案例精粹》一书     
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
		// 析构函数
		virtual ~IStateMachine() { }

		// 设置当前状态
		virtual void SetCurrentState(IState* pIState) = 0;
		// 设置上一状态
		virtual void SetPreviousState(IState* pIState) = 0;
		// 设置全局状态
		virtual void SetGlobalState(IState* pIState) = 0;
		// 获得当前状态
		virtual IState* GetCurrentState(void) const = 0;
		// 获得上一状态
		virtual IState* GetPreviousState(void) const = 0;
		// 获得全局状态
		virtual IState* GetGlobalState(void) const = 0;

		// 处理消息
		virtual bool HandleMessage(const IMessage* pIMsg) = 0;
		// 重置状态
		virtual void RevertToPreviousState(void) = 0;
		// 改变状态
		virtual void ChangeState(IState* pINewState) = 0;
		// 获得状态名称
		virtual SVString GetStateName(void) = 0;
		// 判断是否为同一个状态
		virtual bool IsInState(IState* pIState) = 0;

	public:
		// 更新状态
		virtual void Update(void) = 0;
	};
}

#endif // !_PUBLIC_ISTATEMACHINE_H_
