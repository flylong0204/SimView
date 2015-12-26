#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "LogManage.h"
#include "DynLibManage.h"
#include "ComEnumerator.h"
#include "PluginManage.h"

namespace SimView
{

	typedef void (*StartPluginFunc)(void);
	typedef void (*StopPluginFunc)(void);

	// ���캯��
	CPluginManage::CPluginManage(void)
		:IPluginManage(),
		m_bLoad(true)
	{
	}

	// ��������
	CPluginManage::~CPluginManage(void)
	{
		 // ж�����в��
		ShutDownAllPlugin();
	}

	// ��ӹ�������
	void CPluginManage::AddFactory(IComBaseFactory* pIFactory)
	{
		CComEnumerator::GetSingleton().AddFactory(pIFactory);
	}

	// �Ƴ���������
	void CPluginManage::RemoveFactory(IComBaseFactory* pIFactory)
	{
		CComEnumerator::GetSingleton().RemoveFactory(pIFactory);
	}

	// ��ò������
	IComFaceBase* CPluginManage::GetComInstance(const SVString& strName)
	{
		return (CComEnumerator::GetSingleton().GetComInstance(strName));
	}

	// ������
	bool CPluginManage::LoadCom(const SVString& strComPath)
	{
		// ���ز��
		CDynamicLib* pLib = IDynLibManage::GetSingleton().Load(strComPath);
		if (NULL == pLib)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INTERNAL_ERROR,"��ʼ��CDynamicLibʧ��",\
				"IPuginManager::LoadCom");
		}

		// ��������Ƿ���ڵ�ǰ���
		ListPluginLib::const_iterator cstItor = std::find(m_lstPluginLib.begin(), m_lstPluginLib.end(), pLib);
		if (m_lstPluginLib.end() != cstItor)
		{
			CLogManage::GetSingleton().RecordLog("���" + strComPath + "�Ѿ�������");
			return (true);
		}

		// ��ú���ָ��
		StartPluginFunc pDllStartFun = (StartPluginFunc)(pLib->GetSymbool("DllPluginStart"));
		if (NULL == pDllStartFun)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_ITEM_NOT_FOUND, "���"+ strComPath + "δ�ҵ���ں���DllPluginStart", \
				"IPuginManager::LoadCom");
		}

		// ִ�к���
		pDllStartFun();
		return (true);
	}

	// �������
	void CPluginManage::UnloadCom(const SVString& strComPath)
	{
		// �����ǰϵͳ���صĲ����
		ListPluginLib::iterator itor = m_lstPluginLib.begin();
		for (; m_lstPluginLib.end() != itor; ++itor)
		{
			if (0 != (*itor)->GetName().compare(strComPath))
			{
				continue;
			}

			// ����ж�غ���
			StopPluginFunc pStopPluginFunc = (StopPluginFunc)(*itor)->GetSymbool("DllPluginStop");
			if (NULL == pStopPluginFunc)
			{
				// û���ҵ� �׳��쳣
				SIMVIEW_EXCEPT(CSVExpection::ERR_ITEM_NOT_FOUND, "���" + strComPath + "δ�ҵ���ں���DllPluginStop", \
					"IPuginManager::UnloadCom");
			}

			// ִ�к���
			pStopPluginFunc();

			// �Ƴ���̬��
			CDynLibManage::GetSingleton().UnLoad(*itor);
			m_lstPluginLib.erase(itor);
			return;
		}
	}

	// ��װ���
	void CPluginManage::Install(IPlugin* pIPlugin)
	{
		CLogManage::GetSingleton().RecordLog("���ز��" + pIPlugin->GetName());
		m_lstPluginInstance.push_back(pIPlugin);
		// ��װ���
		if (NULL != pIPlugin)
		{
			pIPlugin->Install();

			if (m_bLoad)
			{
				pIPlugin->Initialise();
			}
		}

		CLogManage::GetSingleton().RecordLog("�ɹ����ز��" + pIPlugin->GetName());
	}

	// ж�ز��
	void CPluginManage::Uninstall(IPlugin* pIPlugin)
	{
		// ��¼��־
		CLogManage::GetSingleton().RecordLog("ж�ز��" + pIPlugin->GetName());
		// ��ѯ��ǰ���
		ListPluginInstance::iterator itor = std::find(m_lstPluginInstance.begin(), \
			m_lstPluginInstance.end(), pIPlugin);
		if (m_lstPluginInstance.end() != itor)
		{
			pIPlugin->ShutDown();
			pIPlugin->UnInstall();
			SIMVIEW_DELETE(pIPlugin);
			m_lstPluginInstance.erase(itor);
		}
		
		CLogManage::GetSingleton().RecordLog("�ɹ�ж�ز��");
	}

	// ж�����в��
	void CPluginManage::ShutDownAllPlugin()
	{
		// �������
		ListPluginInstance::iterator itor = m_lstPluginInstance.begin();
		for (; m_lstPluginInstance.end() != itor; ++itor)
		{
			(*itor)->ShutDown();
			SIMVIEW_DELETE(*itor);
		}

		m_lstPluginInstance.clear();

	}

	// ж�����в��
	

}
