#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "BaseAttribute.h"

namespace SimView
{
	CBaseAttribute::CBaseAttribute(IEntity* pIEntity)
		:CAttributeImp<IBaseAttribute>(pIEntity, "��������"), m_strEntityName("")
	{
	}


	CBaseAttribute::~CBaseAttribute()
	{
	}

	// ��ʼ��
	void CBaseAttribute::Init()
	{
		// λ��
		CDoublePoint3D vPos(0.0, 0.0, 0.0);
		IAttributeItem* pIAttribute = IApplication::GetSingleton().CreateAttributeItem(this, "λ��", "", "", vPos, CTRL_TREE);
		AddAttrItem(pIAttribute);

		// ����
		CDoublePoint3D vScal(1.0, 1.0, 1.0);
		pIAttribute = IApplication::GetSingleton().CreateAttributeItem(this, "����", "", "", vScal, CTRL_TREE);
		AddAttrItem(pIAttribute);

		// ��ת
		CDoublePoint3D vRote(0.0, 0.0, 0.0);
		pIAttribute = IApplication::GetSingleton().CreateAttributeItem(this, "��ת", "", "", vRote, CTRL_TREE);
		AddAttrItem(pIAttribute);

		// �Ƿ���������
		bool b = true;
		pIAttribute = IApplication::GetSingleton().CreateAttributeItem(this, "��������", "true", "", true, CTRL_COMBOX);
		AddAttrItem(pIAttribute);
		pIAttribute->AddCandidatas("false", true);


	}

	// ����ʵ������
	void CBaseAttribute::SetEntityName(const SVString& strName)
	{
		m_strEntityName = strName;
	}


	SVString CBaseAttribute::GetEntityName(void) const
	{
		return (m_strEntityName);
	}

	// ����ID��
	void CBaseAttribute::SetEntityID(const uint64_t uid)
	{
		m_uID = uid;
	}

	// ���ID��
	uint64_t CBaseAttribute::GetEntityID(void) const
	{
		return (m_uID);
	}

	// ����λ��
	void CBaseAttribute::SetPosition(const CDoublePoint3D& vPos)
	{
		GetItem("λ��")->SetValue(vPos, false);
	}

	// ���λ��
	CDoublePoint3D CBaseAttribute::GetPosition(void) const
	{
		// ���ֵ
		CDoublePoint3D v = GetItem("λ��")->GetValueToVec3d();
		return (v);
	}

	// ��������
	void CBaseAttribute::SetScale(const CDoublePoint3D& vScale)
	{
		GetItem("����")->SetValue(vScale, false);
	}

	// �������
	CDoublePoint3D CBaseAttribute::GetScale(void) const
	{
		// ���ֵ
		CDoublePoint3D v = GetItem("����")->GetValueToVec3d();
		return (v);
	}

	// ������ת
	void CBaseAttribute::SetRotate(const CDoublePoint3D& vRot)
	{
		GetItem("��ת")->SetValue(vRot, false);
	}

	// �����ת
	CDoublePoint3D CBaseAttribute::GetRotate(void) const
	{
		// ���ֵ
		CDoublePoint3D v = GetItem("��ת")->GetValueToVec3d();
		return (v);
	}

	// �����Ƿ���������
	void CBaseAttribute::SetDependEarth(const bool bDepend)
	{
		GetItem("��������")->SetValue(&bDepend);
	}

	// ����Ƿ���������
	bool CBaseAttribute::IsDependEarth(void) const
	{
		return (GetItem("��������")->GetValueToBool());
	}

}
