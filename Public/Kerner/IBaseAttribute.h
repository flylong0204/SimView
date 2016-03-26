/**************************************************
outher: LJ
time: 2016-03-23
use: 实体基本属性接口
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
		// 析构函数
		virtual ~IBaseAttribute(void) { }
		// 设置实体名称
		virtual void SetEntityName(const SVString& strName) = 0;
		// 获得实体名称
		virtual SVString GetEntityName(void) const = 0;
		// 设置ID号
		virtual void SetEntityID(const ulong_l uid) = 0;
		// 获得ID号
		virtual ulong_l GetEntityID(void) const = 0;
		// 设置位置
		virtual void SetPosition(const CDoublePoint3D& vPos) = 0;
		// 获得位置
		virtual CDoublePoint3D GetPosition(void) const = 0;
		// 设置缩放
		virtual void SetScale(const CDoublePoint3D& vScale) = 0;
		// 获得缩放
		virtual CDoublePoint3D GetScale(void) const = 0;
		// 设置旋转
		virtual void SetRotate(const CDoublePoint3D& vRot) = 0;
		// 获得旋转
		virtual CDoublePoint3D GetRotate(void) const = 0;
		// 设置是否依赖地球
		virtual void SetDependEarth(const bool bDepend) = 0;
		// 获得是否依赖地球
		virtual bool IsDependEarth(void) const = 0;
	};
}

#endif // !_PUBLIC_IBASEATTRIBUTE_H_
