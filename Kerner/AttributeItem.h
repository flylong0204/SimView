/**************************************************
outher: LJ
time: 2016-03-23
use: 属性项类
from:
chanage:
change outher :
**************************************************/

#ifndef _ATTRIBUTEITEM_H_
#define _ATTRIBUTEITEM_H_

#pragma once

#include "CandidatasManager.h"

namespace SimView
{
	class CAttributeItem : public IAttributeItem
	{
	public:
		explicit CAttributeItem(IAttribute* pIAttribute, const SVString& strName, const SVString& strText, const SVString& strUntil, const Variant& var);
		virtual ~CAttributeItem();

	public:
		// 获取属性名称
		virtual SVString GetTypeName() const;
		// 设置名称
		virtual void SetTypeName(const SVString& strName);
		// 获得属性显示控件
		virtual Contrl GetCtrlType() const;
		// 设置属性显示控件
		virtual void SetCtrlType(Contrl ctrl = CTRL_EDIT);

	public:
		// 设置值 
		virtual void SetValue(const Variant& var, bool bUI = true);
		// 设置值  防止直接传入待选项名称
		virtual void SetValue(const SVString& strCandidata);
		// 获得值并且采用STring类型表现
		virtual SVString GetValueToString(void) const;
		// 转换成osg::Vec3 类型表现
		virtual CFloatPoint3D GetValueToVec3(void);
		// 转换成osg::Vec3 类型表现
		virtual CDoublePoint3D GetValueToVec3d(void);
		// 转换成Int类型
		virtual int GetValueToInt(void) const;
		// 转换成Int类型
		virtual bool GetValueToBool(void) const;
		// 转换成float类型
		virtual float GetValueToFloat(void) const;
		// 转换成Double类型
		virtual double GetValueToDobule(void) const;
		// 添加待选项
		virtual void AddCandidatas(const SVString& strText, const Variant& value, bool bSelect = false);
		// 获得待选列表
		virtual const LstCandidatas& GetCandidatas(void) const;
		// 获得可变参对象
		virtual Variant GetVariant(void) const;
		// 当前是否改变了属性值
		virtual bool IsChanged(void) const;
		// 获得当前选择的序号
		virtual int SelectCandidata(void);
		// 设置选择的序号
		virtual void SetSelect(const int index);
		// 保存到内存卡中
		virtual void WriteMemory(void) const;
		// 从内存中读取出来
		virtual void ReadFromMem(void);
		// 占用空间的大小
		virtual size_t GetSize(void) const;
		// 获得单位
		virtual const SVString& GetUntil(void) const;

	private:
		SVString m_strAttriName; // 属性名称
		Contrl m_contrlType; // 控件属性
		IAttribute* m_pIAttribute; // 对应属性

	private:
		Candidatas m_curCanDidatas; // 当前的值
		mutable bool m_bChanged; // 改变值
		bool m_bAdded; // 添加到待选项中
		CCandidatasManager m_lstCandidata; // 候选列表
		const SVString m_strUntil; // 单位量

		SIMVIEW_AUTO_MUTEX
	};

}

#endif // !_ATTRIBUTEITEM_H_