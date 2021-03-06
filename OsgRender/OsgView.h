/**************************************************
outher: LJ
time: 2015-11-01
use: osg渲染类
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGVIEW_H_
#define _OSGVIEW_H_

#pragma once

namespace osgGA
{
	class KeySwitchMatrixManipulator;
}

namespace SimView
{
	class COsgView : public IOsgView
	{
	public:
		explicit COsgView(IOsgViewConfig* pIConfig);
		virtual ~COsgView();

	public: 
		// 添加节点
		virtual void AddRenderObj(void* pRenderObj);
		// 添加相机控制器
		virtual void AddCameraManipulator(const SVString& strName, CameraManip* pCameraManipulator);
		// 选择操作器
		virtual void SelectCameraManipulator(const SVString& strName);

	public:
		// 初始化操作器
		void InitManipulator(void);
		// 初始化相机
		void InitCamera(void);
		// 获得视图
		virtual SVView* GetView(void) const;

	public:
		// 获得名称
		SVString GetName(void) const;

	private:
		osg::Group* m_pGroup; // 跟节点
		osgViewer::View* m_pView; // osg视图
		osgGA::KeySwitchMatrixManipulator* m_pKeyswitchManipulator; // 相机操作器
		IOsgViewConfig* m_pIConfig; // 配置对象
	};
}

#endif // !_OSGVIEW_H_