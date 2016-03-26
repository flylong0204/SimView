/**************************************************
outher: LJ
time: 2016-03-24
use: ��������
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

		// ��Ӵ�ѡ��
		void Add(const Candidatas& candidata);
		// �Ƴ���ѡ��
		void Remove(SVString& strName);
		// �Ƿ�Ϊ��
		bool Empty(void) const;
		// �������ƻ��ֵ
		Candidatas GetCandidata(const SVString& strName, bool& b);
		// ��ȡ���е�ֵ
		const IAttributeItem::LstCandidatas& GetCandidatas(void) const;
		// ��õ�ǰѡ������
		int SelectCandidata(void) const;
		// ����ѡ������
		void SetSelect(const int index);
		// ��ÿɱ�ζ���
		Variant GetVariant(void) const;

	protected:
		// ��ǰ���Ѿ�����ͬ������
		bool IsHave(const SVString& strName);
		// ��ǰ���Ѿ�����ͬ������
		bool IsHave(const Candidatas& candidata);

	private:
		IAttributeItem::LstCandidatas m_lstCandidatas; // ��ǰѡ���б�
	};
}


#endif // !_CANDIDATESMANAGER