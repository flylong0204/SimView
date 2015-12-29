#define  SIMVIEW_KERNERLIB
#include <algorithm>
#include "../Public/Kerner/Kerner.h"
#include "LogManage.h"
#include "ComEnumerator.h"

namespace SimView
{
	// ���캯��
	CComEnumerator::CComEnumerator(void)
	{
	}

	// ��������
	CComEnumerator::~CComEnumerator(void)
	{
		// �������е�ʵ��
		ListInstaces::iterator  itor = m_listInstances.begin();
		for (; m_listInstances.end() != itor; ++itor)
		{
			// ͨ���������л���ʵ��
			for (ListFactorys::iterator fItor = m_listFactorys.begin(); \
				m_listFactorys.end() != fItor; ++fItor)
			{
				IComBaseFactory* pIComBaseFactory = (*fItor);
				if (0 == pIComBaseFactory->GetMetaData().strTypeName.compare(itor->second->GetTypeName()))
				{
					pIComBaseFactory->DestoryInstance(itor->second);
					m_listInstances.erase(itor->first);
					break;
				}
			}
		}

		m_listInstances.clear();
	}

	// ��ӹ�������
	void CComEnumerator::AddFactory(IComBaseFactory* pIFactory)
	{
		// ��ѯ�Ƿ���ڵ�ǰ�Ĺ���
		ListFactorys::const_iterator cstItor = std::find(\
			m_listFactorys.begin(), m_listFactorys.end(), pIFactory);
		if (m_listFactorys.end() != cstItor)
		{
			return;
		}

		// ��ӵ��б���
		m_listFactorys.push_back(pIFactory);
		// ��������б���
		m_listComData.push_back(&pIFactory->GetMetaData());

		CreateComInstance(pIFactory->GetMetaData().strTypeName, pIFactory->GetMetaData().strName);
		//д����־
		CLogManage::GetSingleton().RecordLog("�������" + pIFactory->GetMetaData().strName + "�ɹ�ע��");
	}

	// �Ƴ���������
	void CComEnumerator::RemoveFactory(IComBaseFactory* pIFactory)
	{
		// ���յ�ǰʵ��
		ListInstaces::iterator itor = m_listInstances.begin();
		for (; m_listInstances.end() != itor;)
		{
			IComFaceBase* pIComFaceInst = itor->second;
			if (0 == pIComFaceInst->GetTypeName().compare(pIFactory->GetMetaData().strTypeName))
			{
				// ��������ʵ��
				pIFactory->DestoryInstance(pIComFaceInst);
				ListInstaces::iterator deli = itor++;
				m_listInstances.erase(deli);
			}
			else
			{
				++itor;
			}
		}

		// �Ƴ�����
		ListComDatas::iterator dataItor = m_listComData.begin();
		for (; m_listComData.end() != dataItor; ++dataItor)
		{
			if (*dataItor == &(pIFactory->GetMetaData()))
			{
				m_listComData.erase(dataItor);
				break;
			}
		}

		m_listFactorys.remove(pIFactory);
	}

	// ����ʵ��
	IComFaceBase* CComEnumerator::CreateComInstance(const SVString& strTypeName, const SVString& strName)
	{
		// �жϵ�ǰʵ���Ƿ����
		if (m_listInstances.end() != m_listInstances.find(strName))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_DUPLICATE_ITEM, "��ǰ���:" + strName + \
				"�Ѿ�����", "CreateComInstance");
		}

		// ����ʵ��
		IComFaceBase* hIns = NULL;
		// �������� 
		ListFactorys::iterator itor = m_listFactorys.begin();
		for (; m_listFactorys.end() != itor; ++itor)
		{
			IComBaseFactory* pIComBaseFactory = *itor;
			if (0 == strTypeName.compare(pIComBaseFactory->GetMetaData().strTypeName))
			{
				hIns = pIComBaseFactory->CreateInstance(strName);
				break;
			}
		}

		if (NULL == hIns)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_ITEM_NOT_FOUND, "û�е�ǰ���͵����" + strTypeName, \
				"CreateComInstance");
		}

		// ���浽ϵͳ��
		m_listInstances[hIns->GetName()] = hIns;

		// ��ʼ�����
		hIns->Init();
		return (hIns);
	}

	// ���ʵ��
	IComFaceBase* CComEnumerator::GetComInstance(const SVString& strName) const
	{
		ListInstaces::const_iterator cstItor = m_listInstances.find(strName);
		if (m_listInstances.end() != cstItor)
		{
			return (cstItor->second);
		}
		else
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_ITEM_NOT_FOUND, "û���ҵ���ǰ���" + strName, \
				"GetComInstance");
		}
	}

	// �Ƿ���ڵ�ǰ���
	bool CComEnumerator::HasComInstance(const SVString& strName) const
	{
		return (m_listInstances.end() == m_listInstances.find(strName));
	}

	// ж�����в��
	void CComEnumerator::ShutAll(void)
	{

	}

}