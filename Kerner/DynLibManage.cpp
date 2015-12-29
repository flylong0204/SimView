#define SIMVIEW_KERNERLIB
#include "../Public/Kerner/Kerner.h"
#include "DynLibManage.h"


namespace SimView
{
	//���캯��
	CDynLibManage::CDynLibManage()
	{
	}

	// ��������
	CDynLibManage::~CDynLibManage()
	{
		// ɾ�����ж�̬��
		DynLibList::iterator itor = m_lstDynLib.begin();
		for (; m_lstDynLib.end() != itor; ++itor)
		{
			itor->second->UnLoad();
			SIMVIEW_DELETE(itor->second);
		}

		// �������
		m_lstDynLib.clear();
	}

	// ���붯̬��
	CDynamicLib* CDynLibManage::Load(const SVString& strDynLibName)
	{
		// ���ҵ�ǰ�ǿ��Ƿ��Ѿ�������
		DynLibList::const_iterator cstItor = m_lstDynLib.find(strDynLibName);
		if (m_lstDynLib.end() != cstItor)
		{
			// �Ѿ������� ��ֱ�ӷ��ص�ǰ��
			return (cstItor->second);
		}

		// û�м��� ��ֱ�Ӽ��ؽ���
		CDynamicLib* pDynLib = new CDynamicLib(strDynLibName);
		// ���붯̬��
		pDynLib->Load();
		m_lstDynLib[strDynLibName] = pDynLib;
		return (pDynLib);
	}

	// ж�ض�̬��
	void CDynLibManage::UnLoad(CDynamicLib* pDynLib)
	{
		// ���ҵ�ǰ����
		DynLibList::iterator itor = m_lstDynLib.find(pDynLib->GetName());
		if (m_lstDynLib.end() != itor)
		{
			m_lstDynLib.erase(itor);
		}

		// ж��
		pDynLib->UnLoad();
		SIMVIEW_DELETE(pDynLib);
	}

}
