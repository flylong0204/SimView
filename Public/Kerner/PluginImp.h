/**************************************************
outher: LJ
time: 2015-10-24
use: 插件系统模板头文件
from: ogre
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_PLUGINIMP_H_
#define _PUBLIC_PLUGINIMP_H_

namespace SimView
{
	template <typename T>
	class CPluginImp : public IPlugin
	{
	public:
		// 构造函数
		explicit CPluginImp(const SVString& strName);
		// 析构函数
		virtual ~CPluginImp() { }
		// 获得插件名称
		virtual const SVString& GetName(void) const;
		// 初始化插件
		virtual void Initialise(void);
		// 回收插件
		virtual void ShutDown(void);
		// 卸载插件
		virtual void UnInstall(void);

	private:
		// 构造函数
		explicit CPluginImp(const CPluginImp& plugin) { }

	protected:
		IComBaseFactory* m_pIComBaseFactory; // 组件工厂

	private:
		const SVString m_strName; // 插件名称
	};

	template <typename T>
	CPluginImp<T>::CPluginImp(const SVString& strName) :m_strName(strName)
	{

	}


	template <typename T>
	const SVString& CPluginImp<T>::GetName(void) const
	{
		return(m_strName);
	}


	// 初始化插件
	template <typename T>
	void CPluginImp<T>::Initialise(void)
	{
		// 注册工厂进入系统中
		IPluginManage::GetSingleton().AddFactory(m_pIComBaseFactory);
	}

	// 回收插件
	template <typename T>
	void CPluginImp<T>::ShutDown(void)
	{
		// 工厂反注册到系统中
		IPluginManage::GetSingleton().RemoveFactory(m_pIComBaseFactory);
	}

	// 卸载插件
	template <typename T>
	void CPluginImp<T>::UnInstall(void)
	{
		// 删除工厂
		SIMVIEW_DELETE(m_pIComBaseFactory);
	}

#define REGISTER_PLGUIN(SVEXPORT, CLASSPLUGIN, PLUGINNAME) \
	IPlugin* pIPugin = NULL; \
	SIMVIEW_EXTERN_C SVEXPORT void DllPluginStart(void) \
	{ \
	pIPugin = new CLASSPLUGIN(PLUGINNAME); \
	IPluginManage::GetSingleton().Install(pIPugin); \
	} \
	SIMVIEW_EXTERN_C SVEXPORT void DllPluginStop(void) \
	{ \
	IPluginManage::GetSingleton().Uninstall(pIPugin); \
	SIMVIEW_DELETE(pIPugin); \
	}\

}

#endif // !_PUBLIC_PLUGINIMP_H_
