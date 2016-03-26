#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "LogManage.h"
#include "ComEnumerator.h"
#include "DynLibManage.h"
#include "PluginManage.h"
#include "GUID.h"
#include "AttributeItem.h"
#include "ConfigFileUtil.h"
#include "Application.h"

namespace SimView
{
	// ���캯��
	CApplication::CApplication(void):
		m_pILogManage(NULL),
		m_pIPluginManage(NULL),
		m_pIDynLibManage(NULL),
		m_pComEnumerator(NULL),
		m_strModuleDir("")
	{
		Init();
	}

	// ��������
	CApplication::~CApplication(void)
	{
		SIMVIEW_DELETE(m_pIPluginManage);
		SIMVIEW_DELETE(m_pIDynLibManage);
		SIMVIEW_DELETE(m_pComEnumerator);
		SIMVIEW_DELETE(m_pILogManage);
	}

	// ��ʼ��
	void CApplication::Init(void)
	{
		// ������־����
		m_pILogManage = new CLogManage;
		// ������־����
		m_pILogManage->CreateLog("simview.log", true);
		// �����������
		m_pIPluginManage = new CPluginManage;
		// ������̬�����
		m_pIDynLibManage = new CDynLibManage;
		// ����ʵ�����
		m_pComEnumerator = new CComEnumerator;
	}

	// ����guid ÿ�λ�ö����µ�ֵ
	long_l CApplication::GenerateGuid(void)
	{
		// ����GUID����������GUID
		long_l llGuid = CGUID::Generate();
		return (llGuid);
	}

	IAttributeItem* CApplication::CreateAttributeItem(IAttribute* pIAttribute, const SVString& strItemName, \
		const SVString& strText, const SVString& strUntil, \
		const Variant& var, const Contrl ct /*= CTRL_SPINBOX*/)
	{
		IAttributeItem* pItem = new CAttributeItem(pIAttribute, strItemName, strText, strUntil, var);
		if (NULL != pItem)
		{
			pItem->SetCtrlType(ct);
		}

		// ������Чֵ
		return (pItem);
	}

	// ���������ļ�������
	IConfigFileUtil* CApplication::CreateConfigFileUtil(void)
	{
		return (new CConfigFileUtil);
	}

	// ��ÿ�ִ�г���·��
	SVString CApplication::GetModulePath(void) const
	{
		return (m_strModuleDir);
	}

	// ���ÿ�ִ�г���·��
	void CApplication::SetModuleDir(const SVString& strModuleDir)
	{
		if (strModuleDir.empty())
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_FILE_NOT_FOUND, "��ִ�г���·��Ϊ��", "SetModuleDir");
		}

		// �������һ�� ��/��
		const int nPos = strModuleDir.find_last_of('\\');
		if (-1 == nPos)
		{
			return ;
		}

		// ���·��
		SVString str = strModuleDir.substr(0, nPos);

		// ��ǰ·��
		ILogManage::GetSingleton().RecordLog("��ִ�г���ǰ·��Ϊ:" + str);
		m_strModuleDir = str;
	}

	// ����ʵ��
	IApplication* CreateApplication(int argc, char *argv[])
	{
		CApplication* pApplication = new CApplication;
		pApplication->SetModuleDir(argv[0]);
		return (pApplication);
	}

}