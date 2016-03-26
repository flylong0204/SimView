/**************************************************
outher: LJ
time: 2016-03-24
use: 基础属性
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
		// 构造函数
		explicit CBaseAttribute(IEntity* pIEntity);
		// 析构函数
		virtual ~CBaseAttribute(void);

	public:
		// 初始化
		virtual void Init();
		// 设置实体名称
		virtual void SetEntityName(const SVString& strName);
		// 获得实体名称
		virtual SVString GetEntityName(void) const;
		// 设置ID号
		virtual void SetEntityID(const uint64_t uid);
		// 获得ID号
		virtual uint64_t GetEntityID(void) const;
		// 获得位置
		virtual void SetPosition(const CDoublePoint3D& vPos);
		// 获得位置
		virtual CDoublePoint3D GetPosition(void) const;
		// 设置缩放
		virtual void SetScale(const CDoublePoint3D& vScale);
		// 获得缩放
		virtual CDoublePoint3D GetScale(void) const;
		// 设置旋转
		virtual void SetRotate(const CDoublePoint3D& vRot);
		// 获得旋转
		virtual CDoublePoint3D GetRotate(void) const;
		// 设置是否依赖地球
		virtual void SetDependEarth(const bool bDepend);
		// 获得是否依赖地球
		virtual bool IsDependEarth(void) const;

	private:
		SVString m_strEntityName;
		uint64_t m_uID;
	};
}


#endif // !_BASEATTRIBUTE_H_