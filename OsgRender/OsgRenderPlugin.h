/**************************************************
outher: LJ
time: 2015-11-01
use: osg渲染插件入口
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGRENDERPLUGIN_H_
#define _OSGRENDERPLUGIN_H_

#pragma once

namespace SimView
{
	class COsgRenderPlugin : public CPluginImp<COsgRenderPlugin>
	{
	public:
		// 构造函数
		explicit COsgRenderPlugin(const SVString& strName);
		// 析构函数
		virtual ~COsgRenderPlugin();
		
	public:
		// 安装插件
		virtual void Install(void);
		// 获得库版本
		virtual CPluginVersion GetVersion(void);
	};

	// 注册插件
	REGISTER_PLGUIN(OSGRENDER_EXPORT, COsgRenderPlugin, COMNAME_OSGRENDER);


}

#endif // !_OSGRENDERPLUGIN_H_
