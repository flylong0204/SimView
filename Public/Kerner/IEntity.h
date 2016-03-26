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

#include <vector>

namespace SimView
{
	class IAttribute;
	class IBaseAttribute;
	class IDrawAttribute;
	class IDrawManager;
	class IStateMachine;
	class IMessage;
	
	class KERNER_EXPORT IEntity
	{
	public:
		typedef std::vector<IAttribute*> ListAttributes;

	public:
		// ��������
		virtual ~IEntity(void) { }
		// ��������
		virtual void SetName(const SVString& strName) = 0;
		// �������
		virtual SVString GetName(void) const = 0;
		// ����ID
		virtual void SetID(const ulong_l uID) = 0;
		// ���ID
		virtual ulong_l GetID(void) const = 0;

		// ���Խӿ�
	public:
		// ����ʵ���������
		virtual void SetBaseAttribute(IBaseAttribute* pIBaseAttribute) = 0;
		// ��û������Զ���
		virtual IBaseAttribute* GetBaseAttribute(void) const = 0;
		// ������Ⱦ����
		virtual void AddDrawAttribute(IDrawAttribute* pIDrawAttribute) = 0;
		// �����Ⱦ����
		virtual IDrawAttribute* GetDrawAttribute(const SVString& strName) = 0;
		// �Ƴ�����
		virtual void RemoveDrawAttribute(IAttribute* pIAttribute) = 0;
		// ������Ⱦ����
		virtual void SetDrawManager(IDrawManager* pIDrawManager) = 0;
		// �����Ⱦ����
		virtual IDrawManager* GetDrawManager(void) const = 0;

		// �������
	public:
		// ����
		virtual void Update(void) = 0;


		// ��Ϣ���
	public:
		// ������Ϣ
		virtual bool HandleMessage(const IMessage* pIMessage) = 0;
		// ���״̬��
		virtual IStateMachine* GetStateMachine(void) const = 0;
		// ����״̬��
		virtual void SetStateMachine(IStateMachine* pIStateMachine) = 0;
		// ��ʼ��״̬��
		virtual void InitStateMachine(IStateMachine* pIStateMachine) = 0;

	};
}

#endif // ! _PUBLIC_IENTITY_H_