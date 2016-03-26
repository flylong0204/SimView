#include "../Public/Kerner/Kerner.h"
#include "CandidatasManager.h"

namespace SimView
{
	CCandidatasManager::CCandidatasManager()
	{
	}


	CCandidatasManager::~CCandidatasManager()
	{
	}

	void CCandidatasManager::Add(const Candidatas& candidata)
	{
		if (!IsHave(candidata))
		{
			return;
		}

		m_lstCandidatas.push_back(candidata);
	}

	void CCandidatasManager::Remove(SVString& strName)
	{
		IAttributeItem::LstCandidatas::iterator cstItro = std::find(m_lstCandidatas.begin(), m_lstCandidatas.end(), strName);
		if (cstItro == m_lstCandidatas.end())
		{
			return;
		}

		m_lstCandidatas.erase(cstItro);
	}

	bool CCandidatasManager::Empty(void) const
	{
		return m_lstCandidatas.empty();
	}

	Candidatas CCandidatasManager::GetCandidata(const SVString& strName, bool& b)
	{
		IAttributeItem::LstCandidatas::iterator cstItro = std::find(m_lstCandidatas.begin(), m_lstCandidatas.end(), strName);
		if (cstItro == m_lstCandidatas.end())
		{
			b = false;
			return Candidatas("", "");
		}

		b = true;
		return *cstItro;

	}

	const IAttributeItem::LstCandidatas& CCandidatasManager::GetCandidatas(void) const
	{
		return m_lstCandidatas;
	}

	int CCandidatasManager::SelectCandidata(void) const
	{
		// �������е�ֵ
		int index = 0;
		IAttributeItem::LstCandidatas::const_iterator cstItro = m_lstCandidatas.begin();
		for (; m_lstCandidatas.end() != cstItro; ++cstItro, ++index)
		{
			if (cstItro->bSelect)
			{
				return (index);
			}
		}

		// �жϵ�ǰû��ѡ����ֱ�ӷ��ص�һ��
		return (0);
	}

	void CCandidatasManager::SetSelect(const int index)
	{
		// �ж������ǰ����������� ��֮�䷵��
		if (index >= (int)m_lstCandidatas.size())
		{
			return;
		}

		// �������е�ֵ ����ѡ����
		IAttributeItem::LstCandidatas::iterator itor = m_lstCandidatas.begin();
		for (int i = 0; m_lstCandidatas.end() != itor; ++itor, ++i)
		{
			itor->bSelect = index == i ? true : false;
		}
	}

	Variant CCandidatasManager::GetVariant(void) const
	{
		// �������е�ֵ ����ѡ����
		IAttributeItem::LstCandidatas::const_iterator itor = m_lstCandidatas.begin();
		for (int i = 0; m_lstCandidatas.end() != itor; ++itor, ++i)
		{
			if (itor->bSelect)
			{
				return (itor->value);
			}

		}

		return (m_lstCandidatas.begin()->value);
	}

	bool CCandidatasManager::IsHave(const SVString& strName)
	{
		IAttributeItem::LstCandidatas::const_iterator cstItro = std::find(m_lstCandidatas.begin(), m_lstCandidatas.end(), strName);
		return (cstItro == m_lstCandidatas.end());
	}

	bool CCandidatasManager::IsHave(const Candidatas& candidata)
	{
		IAttributeItem::LstCandidatas::const_iterator cstItro = std::find(m_lstCandidatas.begin(), m_lstCandidatas.end(), candidata);
		return (cstItro == m_lstCandidatas.end());
	}
}

