/**************************************************
outher: LJ
time: 2016-03-23
use: 渲染属性管理接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_IDRAWMANAGER_H_
#define _PUBLICE_IDRAWMANAGER_H_


namespace SimView
{
#define DrawObj void
#define EarthMapNode void

	class IDrawAttribute;

	class KERNER_EXPORT IDrawManager
	{
	public:
		// 获得实体
		virtual IEntity* GetEntity(void) const = 0;
		// 设置地球体
		virtual void SetMapNode(EarthMapNode* pMapNode) = 0;
		// 获得渲染体
		virtual DrawObj* GetDrawObj(void) = 0;
		// 获得根渲染体
		virtual DrawObj* GetRootDrawObj(void) = 0;
		// 添加渲染体
		virtual void Add(IDrawAttribute* pIDrawAttribute) = 0;
		// 移除渲染属性
		virtual void Remove(IDrawAttribute* pIDrawAttribute) = 0;
		// 获得渲染属性
		virtual IDrawAttribute* GetAttribute(const SVString& strName) const = 0;
		// 更新属性
		virtual void Update(void) = 0;
	};
}

#endif // !_PUBLICE_IDRAWMANAGER_H_
