/**************************************************
outher: LJ
time: 2016-03-23
use: ��������
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
		// ��ȡ��������
		virtual SVString GetTypeName() const;
		// ��������
		virtual void SetTypeName(const SVString& strName);
		// ���������ʾ�ؼ�
		virtual Contrl GetCtrlType() const;
		// ����������ʾ�ؼ�
		virtual void SetCtrlType(Contrl ctrl = CTRL_EDIT);

	public:
		// ����ֵ 
		virtual void SetValue(const Variant& var, bool bUI = true);
		// ����ֵ  ��ֱֹ�Ӵ����ѡ������
		virtual void SetValue(const SVString& strCandidata);
		// ���ֵ���Ҳ���STring���ͱ���
		virtual SVString GetValueToString(void) const;
		// ת����osg::Vec3 ���ͱ���
		virtual CFloatPoint3D GetValueToVec3(void);
		// ת����osg::Vec3 ���ͱ���
		virtual CDoublePoint3D GetValueToVec3d(void);
		// ת����Int����
		virtual int GetValueToInt(void) const;
		// ת����Int����
		virtual bool GetValueToBool(void) const;
		// ת����float����
		virtual float GetValueToFloat(void) const;
		// ת����Double����
		virtual double GetValueToDobule(void) const;
		// ��Ӵ�ѡ��
		virtual void AddCandidatas(const SVString& strText, const Variant& value, bool bSelect = false);
		// ��ô�ѡ�б�
		virtual const LstCandidatas& GetCandidatas(void) const;
		// ��ÿɱ�ζ���
		virtual Variant GetVariant(void) const;
		// ��ǰ�Ƿ�ı�������ֵ
		virtual bool IsChanged(void) const;
		// ��õ�ǰѡ������
		virtual int SelectCandidata(void);
		// ����ѡ������
		virtual void SetSelect(const int index);
		// ���浽�ڴ濨��
		virtual void WriteMemory(void) const;
		// ���ڴ��ж�ȡ����
		virtual void ReadFromMem(void);
		// ռ�ÿռ�Ĵ�С
		virtual size_t GetSize(void) const;
		// ��õ�λ
		virtual const SVString& GetUntil(void) const;

	private:
		SVString m_strAttriName; // ��������
		Contrl m_contrlType; // �ؼ�����
		IAttribute* m_pIAttribute; // ��Ӧ����

	private:
		Candidatas m_curCanDidatas; // ��ǰ��ֵ
		mutable bool m_bChanged; // �ı�ֵ
		bool m_bAdded; // ��ӵ���ѡ����
		CCandidatasManager m_lstCandidata; // ��ѡ�б�
		const SVString m_strUntil; // ��λ��

		SIMVIEW_AUTO_MUTEX
	};

}

#endif // !_ATTRIBUTEITEM_H_