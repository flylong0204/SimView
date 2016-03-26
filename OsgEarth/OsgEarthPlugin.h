/**************************************************
outher: LJ
time: 2016-03-23
use: osg地球插件入口
from:
chanage:
change outher :
**************************************************/
#ifndef _OSGEARTHPLUGIN_H_
#define _OSGEARTHPLUGIN_H_

#pragma once

namespace SimView
{
	class COsgEarthPlugin : public CPluginImp<COsgEarthPlugin>
	{
	public:
		// 构造函数
		explicit COsgEarthPlugin(const SVString& strName);
		// 析构函数
		virtual ~COsgEarthPlugin();

	public:
		// 安装插件
		virtual void Install(void);
		// 获得库版本
		virtual CPluginVersion GetVersion(void);
	};

	// 注册插件
	REGISTER_PLGUIN(OSG_EARTH_EXPORT, COsgEarthPlugin, COMNAME_OSGEARTH);
}


#endif // !_OSGEARTHPLUGIN_H_