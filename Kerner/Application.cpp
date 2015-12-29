#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "LogManage.h"
#include "ComEnumerator.h"
#include "DynLibManage.h"
#include "PluginManage.h"
#include "GUID.h"
#include "Application.h"

namespace SimView
{
	// ���캯��
	CApplication::CApplication(void):
		m_pILogManage(NULL),
		m_pIPluginManage(NULL),
		m_pIDynLibManage(NULL),
		m_pComEnumerator(NULL)
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

	// ����ʵ��
	IApplication* CreateApplication(void)
	{
		return (new CApplication);
	}

}