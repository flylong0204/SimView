/**************************************************
outher: LJ
time: 2016-03-23
use: ʵ��������Խӿ�
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IBASEATTRIBUTE_H_
#define _PUBLIC_IBASEATTRIBUTE_H_

namespace SimView
{
	class KERNER_EXPORT IBaseAttribute : public IAttribute
	{
	public:
		// ��������
		virtual ~IBaseAttribute(void) { }
		// ����ʵ������
		virtual void SetEntityName(const SVString& strName) = 0;
		// ���ʵ������
		virtual SVString GetEntityName(void) const = 0;
		// ����ID��
		virtual void SetEntityID(const ulong_l uid) = 0;
		// ���ID��
		virtual ulong_l GetEntityID(void) const = 0;
		// ����λ��
		virtual void SetPosition(const CDoublePoint3D& vPos) = 0;
		// ���λ��
		virtual CDoublePoint3D GetPosition(void) const = 0;
		// ��������
		virtual void SetScale(const CDoublePoint3D& vScale) = 0;
		// �������
		virtual CDoublePoint3D GetScale(void) const = 0;
		// ������ת
		virtual void SetRotate(const CDoublePoint3D& vRot) = 0;
		// �����ת
		virtual CDoublePoint3D GetRotate(void) const = 0;
		// �����Ƿ���������
		virtual void SetDependEarth(const bool bDepend) = 0;
		// ����Ƿ���������
		virtual bool IsDependEarth(void) const = 0;
	};
}

#endif // !_PUBLIC_IBASEATTRIBUTE_H_
