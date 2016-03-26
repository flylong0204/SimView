#define  OSGEARTH_DLL
#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgEarth/OsgEarth.h"
#include "OsgEarhConfig.h"

#include "OsgEarthManage.h"

#include <osgDB/ReadFile>
#include <osgEarth/MapNode>

namespace SimView
{
	// ���캯��
	COsgEarhConfig::COsgEarhConfig(void) :m_pIConfigFileUtil(NULL)
	{
		Init();
	}

	// ��������
	COsgEarhConfig::~COsgEarhConfig(void)
	{
		SIMVIEW_DELETE(m_pIConfigFileUtil);
	}

	// ��ʼ��
	void COsgEarhConfig::Init(void)
	{
		// ��ÿ�ִ�г���·��
		SVString strModulePath = IApplication::GetSingleton().GetModulePath() + "/Config/Earth/earth.cfg";

		// �������ö���
		m_pIConfigFileUtil = IApplication::GetSingleton().CreateConfigFileUtil();
		if (NULL == m_pIConfigFileUtil)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_DUPLICATE_ITEM, "���������ļ�ʧ��", "OsgEarhConfig::Init");
		}

		// �������ļ�
		if (!m_pIConfigFileUtil->OpenFile(strModulePath))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_FILE_NOT_FOUND, "�������ļ�ʧ��", "OsgEarhConfig::Init");
		}

		// ��ȡ�����ļ�
		m_pIConfigFileUtil->ReadConfig();

		// ��ȡ�����ļ�
		GetEarthNode();
	}

	// ��ȡ�����ļ�
	void COsgEarhConfig::GetEarthNode(void)
	{
		// ��ȡ�����ļ�·��
		SVString strPath = m_pIConfigFileUtil->GetItemValue("earth", "filePath");
		if (strPath.empty())
		{
			ILogManage::GetSingleton().RecordLog("earth�����ļ��в�����earth·��");
			return;
		}

		osg::Node* pEarthNode = osgDB::readNodeFile(strPath);
		osgEarth::MapNode* pMapNode = osgEarth::MapNode::findMapNode(pEarthNode);

		// ��õ���ڵ��Ƿ�ɹ�
		if (NULL == pMapNode)
		{
			ILogManage::GetSingleton().RecordLog("�����ڵ���ڵ�");
			return;
		}

		COsgEarthManage::GetSingleton().SetMapNode(pMapNode);
	}

}