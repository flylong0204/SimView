/**************************************************
outher: LJ
time: 2016-03-24
use: ��������
from:
chanage:
change outher :
**************************************************/

#ifndef _BASEATTRIBUTE_H_
#define _BASEATTRIBUTE_H_

#pragma once

namespace SimView
{
	class CBaseAttribute : public CAttributeImp<IBaseAttribute>
	{
	public:
		// ���캯��
		explicit CBaseAttribute(IEntity* pIEntity);
		// ��������
		virtual ~CBaseAttribute(void);

	public:
		// ��ʼ��
		virtual void Init();
		// ����ʵ������
		virtual void SetEntityName(const SVString& strName);
		// ���ʵ������
		virtual SVString GetEntityName(void) const;
		// ����ID��
		virtual void SetEntityID(const uint64_t uid);
		// ���ID��
		virtual uint64_t GetEntityID(void) const;
		// ���λ��
		virtual void SetPosition(const CDoublePoint3D& vPos);
		// ���λ��
		virtual CDoublePoint3D GetPosition(void) const;
		// ��������
		virtual void SetScale(const CDoublePoint3D& vScale);
		// �������
		virtual CDoublePoint3D GetScale(void) const;
		// ������ת
		virtual void SetRotate(const CDoublePoint3D& vRot);
		// �����ת
		virtual CDoublePoint3D GetRotate(void) const;
		// �����Ƿ���������
		virtual void SetDependEarth(const bool bDepend);
		// ����Ƿ���������
		virtual bool IsDependEarth(void) const;

	private:
		SVString m_strEntityName;
		uint64_t m_uID;
	};
}


#endif // !_BASEATTRIBUTE_H_