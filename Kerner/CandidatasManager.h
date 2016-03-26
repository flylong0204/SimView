/**************************************************
outher: LJ
time: 2016-03-24
use: 属性项类
from:
chanage:
change outher :
**************************************************/

#ifndef _CANDIDATESMANAGER
#define _CANDIDATESMANAGER

#pragma once

namespace SimView
{
	class CCandidatasManager
	{
	public:
		explicit CCandidatasManager(void);
		~CCandidatasManager(void);

		// 添加待选项
		void Add(const Candidatas& candidata);
		// 移除带选项
		void Remove(SVString& strName);
		// 是否为空
		bool Empty(void) const;
		// 根据名称获得值
		Candidatas GetCandidata(const SVString& strName, bool& b);
		// 获取所有的值
		const IAttributeItem::LstCandidatas& GetCandidatas(void) const;
		// 获得当前选择的序号
		int SelectCandidata(void) const;
		// 设置选择的序号
		void SetSelect(const int index);
		// 获得可变参对象
		Variant GetVariant(void) const;

	protected:
		// 当前是已经有相同的名称
		bool IsHave(const SVString& strName);
		// 当前是已经有相同的名称
		bool IsHave(const Candidatas& candidata);

	private:
		IAttributeItem::LstCandidatas m_lstCandidatas; // 当前选项列表
	};
}


#endif // !_CANDIDATESMANAGER