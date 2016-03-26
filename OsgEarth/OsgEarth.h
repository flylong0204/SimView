/**************************************************
outher: LJ
time: 2016-03-23
use: 地球管理接口，提供
from:
chanage:
change outher :
**************************************************/
#ifndef _OSGEARTH_H_
#define _OSGEARTH_H_

#pragma once

#include <osg/Group>

namespace SimView
{
	class COsgEarhConfig;
	class COsgEarthManage;

	class COsgEarth : public IOsgEarth
	{
	public:
		// 构造函数
		explicit COsgEarth(void);
		// 析构函数
		virtual ~COsgEarth(void);

	public:
		// 设置组件名称
		virtual void SetName(const SVString& strName);
		// 获得组件名称
		virtual const SVString& GetName(void) const;
		// 获得类型
		virtual const SVString& GetTypeName(void) const;
		// 创建时调用初始化
		virtual void Init(void);

	public:
		// 渲染地球
		virtual void DrawEarth(void);
		// 获得数字地球管理节点
		virtual IOsgEarthManage* GetOsgEarhManage(void) const ;

	protected:
		// 设置操作器
		void SetEarthManipulator(void);

	private:
		SVString m_strName;

		COsgEarthManage* m_pOsgEarthManage;

		COsgEarhConfig* m_pEarthConfig; // 配置文件

		osg::Group* m_pEarthRoot; // 地球根节点

		bool m_bInit; // 是否初始化

	};

	// 创建工厂
	CREATE_COMBASEFACTORY(COsgEarth, COMTYPE_OSGEARTH, COMNAME_OSGEARTH, COMDIR_OSGEARTH)
}


#endif // !_OSGEARTH_H_