#define  OSGEARTH_DLL
#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgEarth/OsgEarth.h"
#include "OsgEarhConfig.h"

#include "OsgEarthManage.h"

#include <osgDB/ReadFile>
#include <osgEarth/MapNode>

namespace SimView
{
	// 构造函数
	COsgEarhConfig::COsgEarhConfig(void) :m_pIConfigFileUtil(NULL)
	{
		Init();
	}

	// 析构函数
	COsgEarhConfig::~COsgEarhConfig(void)
	{
		SIMVIEW_DELETE(m_pIConfigFileUtil);
	}

	// 初始化
	void COsgEarhConfig::Init(void)
	{
		// 获得可执行程序路径
		SVString strModulePath = IApplication::GetSingleton().GetModulePath() + "/Config/Earth/earth.cfg";

		// 创建配置对象
		m_pIConfigFileUtil = IApplication::GetSingleton().CreateConfigFileUtil();
		if (NULL == m_pIConfigFileUtil)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_DUPLICATE_ITEM, "创建配置文件失败", "OsgEarhConfig::Init");
		}

		// 打开配置文件
		if (!m_pIConfigFileUtil->OpenFile(strModulePath))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_FILE_NOT_FOUND, "打开配置文件失败", "OsgEarhConfig::Init");
		}

		// 读取配置文件
		m_pIConfigFileUtil->ReadConfig();

		// 读取地球文件
		GetEarthNode();
	}

	// 读取地球文件
	void COsgEarhConfig::GetEarthNode(void)
	{
		// 获取地球文件路径
		SVString strPath = m_pIConfigFileUtil->GetItemValue("earth", "filePath");
		if (strPath.empty())
		{
			ILogManage::GetSingleton().RecordLog("earth配置文件中不配置earth路径");
			return;
		}

		osg::Node* pEarthNode = osgDB::readNodeFile(strPath);
		osgEarth::MapNode* pMapNode = osgEarth::MapNode::findMapNode(pEarthNode);

		// 获得地球节点是否成功
		if (NULL == pMapNode)
		{
			ILogManage::GetSingleton().RecordLog("不存在地球节点");
			return;
		}

		COsgEarthManage::GetSingleton().SetMapNode(pMapNode);
	}

}