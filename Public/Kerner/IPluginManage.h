/**********************************************/
/*autor： LJ				                  */
/*time: 2015-10-18		                      */
/*use:	public singleton head                 */
/*use:				                          */
/*form: ogre singleton                        */
/**********************************************/

#ifndef _IPUGLINMANAGE_H_
#define _IPUGLINMANAGE_H_

#pragma once

namespace SimView
{
	class IComBaseFactory;
	class IComFaceBase;
	class IPlugin;

	class KERNER_EXPORT IPluginManage : public CSingleton<IPluginManage>
	{
	public:
		// 析构函数  
		virtual ~IPluginManage(void) { }
		// 添加工厂对象
		virtual void AddFactory(IComBaseFactory* pIFactory) = 0;
		// 移除工厂对象
		virtual void RemoveFactory(IComBaseFactory* pIFactory) = 0;
		// 获得插件对象
		virtual IComFaceBase* GetComInstance(const SVString& strName) = 0;
		// 导入插件
		virtual bool LoadCom(const SVString& strComPath) = 0;
		// 安装插件
		virtual void Install(IPlugin* pIPlugin) = 0;
		// 卸载插件
		virtual void Uninstall(IPlugin* pIPlugin) = 0;
	};
}

#endif // _IPUGLINMANAGE_H_