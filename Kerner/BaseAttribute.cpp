#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "BaseAttribute.h"

namespace SimView
{
	CBaseAttribute::CBaseAttribute(IEntity* pIEntity)
		:CAttributeImp<IBaseAttribute>(pIEntity, "基础属性"), m_strEntityName("")
	{
	}


	CBaseAttribute::~CBaseAttribute()
	{
	}

	// 初始化
	void CBaseAttribute::Init()
	{
		// 位置
		CDoublePoint3D vPos(0.0, 0.0, 0.0);
		IAttributeItem* pIAttribute = IApplication::GetSingleton().CreateAttributeItem(this, "位置", "", "", vPos, CTRL_TREE);
		AddAttrItem(pIAttribute);

		// 缩放
		CDoublePoint3D vScal(1.0, 1.0, 1.0);
		pIAttribute = IApplication::GetSingleton().CreateAttributeItem(this, "缩放", "", "", vScal, CTRL_TREE);
		AddAttrItem(pIAttribute);

		// 旋转
		CDoublePoint3D vRote(0.0, 0.0, 0.0);
		pIAttribute = IApplication::GetSingleton().CreateAttributeItem(this, "旋转", "", "", vRote, CTRL_TREE);
		AddAttrItem(pIAttribute);

		// 是否依赖地球
		bool b = true;
		pIAttribute = IApplication::GetSingleton().CreateAttributeItem(this, "依赖地球", "true", "", true, CTRL_COMBOX);
		AddAttrItem(pIAttribute);
		pIAttribute->AddCandidatas("false", true);


	}

	// 设置实体名称
	void CBaseAttribute::SetEntityName(const SVString& strName)
	{
		m_strEntityName = strName;
	}


	SVString CBaseAttribute::GetEntityName(void) const
	{
		return (m_strEntityName);
	}

	// 设置ID号
	void CBaseAttribute::SetEntityID(const uint64_t uid)
	{
		m_uID = uid;
	}

	// 获得ID号
	uint64_t CBaseAttribute::GetEntityID(void) const
	{
		return (m_uID);
	}

	// 设置位置
	void CBaseAttribute::SetPosition(const CDoublePoint3D& vPos)
	{
		GetItem("位置")->SetValue(vPos, false);
	}

	// 获得位置
	CDoublePoint3D CBaseAttribute::GetPosition(void) const
	{
		// 获得值
		CDoublePoint3D v = GetItem("位置")->GetValueToVec3d();
		return (v);
	}

	// 设置缩放
	void CBaseAttribute::SetScale(const CDoublePoint3D& vScale)
	{
		GetItem("缩放")->SetValue(vScale, false);
	}

	// 获得缩放
	CDoublePoint3D CBaseAttribute::GetScale(void) const
	{
		// 获得值
		CDoublePoint3D v = GetItem("缩放")->GetValueToVec3d();
		return (v);
	}

	// 设置旋转
	void CBaseAttribute::SetRotate(const CDoublePoint3D& vRot)
	{
		GetItem("旋转")->SetValue(vRot, false);
	}

	// 获得旋转
	CDoublePoint3D CBaseAttribute::GetRotate(void) const
	{
		// 获得值
		CDoublePoint3D v = GetItem("旋转")->GetValueToVec3d();
		return (v);
	}

	// 设置是否依赖地球
	void CBaseAttribute::SetDependEarth(const bool bDepend)
	{
		GetItem("依赖地球")->SetValue(&bDepend);
	}

	// 获得是否依赖地球
	bool CBaseAttribute::IsDependEarth(void) const
	{
		return (GetItem("依赖地球")->GetValueToBool());
	}

}
