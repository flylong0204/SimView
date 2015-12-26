/**********************************************/
/*autor： LJ				                  */
/*time: 2015-10-18		                      */
/*use:	Manager this Plugin                   */
/*use:				                          */
/**********************************************/

#ifndef _PUGLINMANAGE_H_
#define _PUGLINMANAGE_H_

#pragma once

namespace SimView
{
	class CPluginManage : public IPluginManage
	{
	public:
		typedef std::vector<CDynamicLib*> ListPluginLib; // 插件库链表
		typedef std::vector<IPlugin*> ListPluginInstance; // 插件实体链表

	public:
		// 构造函数
		explicit CPluginManage(void);
		// 析构函数
		virtual ~CPluginManage(void);
		// 导入库

	public:
		// 添加工厂对象
		virtual void AddFactory(IComBaseFactory* pIFactory);
		// 移除工厂对象
		virtual void RemoveFactory(IComBaseFactory* pIFactory);
		// 获得插件对象
		virtual IComFaceBase* GetComInstance(const SVString& strName);
		// 导入插件
		virtual bool LoadCom(const SVString& strComPath);
		// 导出插件
		virtual void UnloadCom(const SVString& strComPath);
		// 安装插件
		virtual void Install(IPlugin* pIPlugin);
		// 卸载插件
		virtual void Uninstall(IPlugin* pIPlugin);

	protected:
		// 卸载所有插件
		virtual void ShutDownAllPlugin();
	private:
		ListPluginLib m_lstPluginLib; // 插件库链表
		ListPluginInstance m_lstPluginInstance; // 实体链表

		bool m_bLoad; // 是否直接加载 无需界面干涉
	};
}

#endif // _PUGLINMANAGE_H_