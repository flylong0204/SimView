#define OSGRENDER_DLL
#include <windows.h>
#include <osgViewer/View>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/CameraManipulator>
#include <osg/GraphicsContext>
#include "../Public/Kerner/Kerner.h"
#include "../Public/OsgRender/OsgRender.h"
#include "../Public/OsgRender/IOsgViewConfig.h"
#include "OsgView.h"

namespace SimView
{
	// 构造函数
	COsgView::COsgView(IOsgViewConfig* pIConfig)
		:m_pGroup(NULL),m_pView(new osgViewer::View), m_pIConfig(pIConfig)
	{
		// 设置名称
		m_pView->setName(pIConfig->GetName());
	}

	// 析构函数
	COsgView::~COsgView()
	{
		// 移除渲染体
		if (NULL == m_pGroup)
		{
			return;
		}
		m_pGroup->removeChildren(0, m_pGroup->getNumChildren());
	}

	// 初始化操作器
	void COsgView::InitManipulator(void)
	{
		// 创建视图
		m_pKeyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;
		m_pIConfig->InitManipulator(m_pKeyswitchManipulator);
	}

	// 初始化相机
	void COsgView::InitCamera(void)
	{
		// 创建上下文
		osg::GraphicsContext::Traits* pTraits = new osg::GraphicsContext::Traits;
		// 调用配置函数进行使用配置相关参数
		m_pIConfig->InitContextTraits(pTraits);

		// 创建相机上下文
		osg::GraphicsContext* pGc = osg::GraphicsContext::createGraphicsContext(pTraits);
		// 初始化相机
		osg::Camera* pCamera = m_pView->getCamera();
		// 关联上下文
		pCamera->setGraphicsContext(pGc);
		// 设置视图
		pCamera->setViewport(new osg::Viewport(pTraits->x, pTraits->y, pTraits->width, pTraits->height));
		// 设置投影
		pCamera->setClearMask(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		pCamera->setClearColor(osg::Vec4f(0.2f, 0.2f, 0.4f, 1.0f));
		pCamera->setProjectionMatrixAsPerspective(
			30.0f, static_cast<double>(pTraits->width) / static_cast<double>(pTraits->height), 0.1, 1000.0);
		m_pView->setCamera(pCamera);
		// 添加操作器
		m_pView->setCameraManipulator(m_pKeyswitchManipulator);

		m_pGroup = new osg::Group;
	}

	// 获得名称
	SVString COsgView::GetName(void) const
	{
		return (m_pIConfig->GetName());
	}

	// 获得视图
	SVView* COsgView::GetView(void) const
	{
		return (m_pView);
	}

	// 添加节点
	void COsgView::AddRenderObj(void* pRenderObj)
	{
		// 转换成osg节点
		osg::Node* pNode = static_cast<osg::Node*>(pRenderObj);
		if (NULL == pNode)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_CONVERT_FAILD, "类型转换失败", "AddRenderObj");
		}

		// 判断是否为第一个
		int nCount = m_pGroup->getNumChildren();
		if (0 >= nCount)
		{
			m_pGroup->addChild(pNode);
			m_pView->setSceneData(m_pGroup);
			m_pView->setCameraManipulator(m_pKeyswitchManipulator);
		}
		else
		{
			m_pGroup->addChild(pNode);
		}
		ILogManage::GetSingleton().RecordLog("添加渲染节点成功");
	}

	// 添加相机控制器
	void COsgView::AddCameraManipulator(const SVString& strName, CameraManip* pCameraManipulator)
	{
		// 定义类型
		typedef osgGA::KeySwitchMatrixManipulator::NamedManipulator ManipName;
		typedef osgGA::KeySwitchMatrixManipulator::KeyManipMap MapKeyManip;
		MapKeyManip mapKeyManip = m_pKeyswitchManipulator->getKeyManipMap();

		// 遍历查询
		for (MapKeyManip::const_iterator cstItor = mapKeyManip.begin(); mapKeyManip.end() != cstItor; ++cstItor)
		{
			const ManipName& manipName = cstItor->second;
			if (0 == (strName.compare(manipName.first)))
			{
				SIMVIEW_EXCEPT(CSVExpection::ERR_INTERNAL_ERROR, "该名称已经存在", "AddCameraManipulator");
				break;
			}
		}

		osgGA::CameraManipulator* pCm = static_cast<osgGA::CameraManipulator*>(pCameraManipulator);
		if (NULL == pCm)
		{
			return;
		}

		int nCount = (int)m_pKeyswitchManipulator->getNumMatrixManipulators() +	1;

		m_pKeyswitchManipulator->addMatrixManipulator(nCount, strName, pCm);
	}

	// 选择操作器
	void COsgView::SelectCameraManipulator(const SVString& strName)
	{
		// 定义类型
		typedef osgGA::KeySwitchMatrixManipulator::NamedManipulator ManipName;
		typedef osgGA::KeySwitchMatrixManipulator::KeyManipMap MapKeyManip;
		MapKeyManip mapKeyManip = m_pKeyswitchManipulator->getKeyManipMap();

		unsigned int nSelect = 1;

		// 遍历查询
		for (MapKeyManip::const_iterator cstItor = mapKeyManip.begin(); mapKeyManip.end() != cstItor; ++cstItor)
		{
			const ManipName& manipName = cstItor->second;
			if (0 == (strName.compare(manipName.first)))
			{
				nSelect = cstItor->first;
				break;
			}
		}

		nSelect -= 1;

		// 设置选择的值
		m_pKeyswitchManipulator->selectMatrixManipulator(nSelect);
	}

	// 
}