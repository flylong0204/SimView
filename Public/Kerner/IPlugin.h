/**************************************************
outher: LJ
time: 2015-10-24
use: 插件系统头文件 
from: ogre
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_IPLUGIN_H_
#define _PUBLICE_IPLUGIN_H_

namespace SimView
{
	// 插件版本类
	class CPluginVersion 
	{
	public:
		CPluginVersion(const int nMainV, const int nMinorV, const int nReviseV, \
			const int nDate) :
			m_nMainV(nMainV),
			m_nMinorV(nMinorV),
			m_nReviseV(nReviseV),
			m_nDate(nDate)
		{

		}

		// 获得主版本号
		virtual int MainVersion(void) const
		{
			return (m_nMainV);
		}

		// 获得次版本号
		virtual int MinorVersion(void) const
		{
			return (m_nMinorV);
		}

		// 获得修订版本好
		virtual int ReviseVersion(void) const
		{
			return (m_nReviseV);
		}

		// 获得版本日期
		virtual int CreateDate(void) const
		{
			return (m_nDate);
		}

		// 获得版本字符串
		virtual SVString GetVersion(void) const
		{
			SVChar szTmp[256];
			SVSprintf(szTmp, "%d.%d.%d.%d", m_nMainV, m_nMinorV, m_nReviseV, m_nDate);
			return szTmp;
		}

	private:
		int m_nMainV; // 主版本号
		int m_nMinorV; // 次版本号
		int m_nReviseV; // 修订版本号
		int m_nDate; // 修订日期
	};

	//////////////////////////////////////////////////////////////////////////

	// 插件基类
	class KERNER_EXPORT IPlugin
	{
	public:
		// 析构函数
		virtual ~IPlugin(void) { }
		// 获得插件名称
		virtual const SVString& GetName(void) const = 0;
		// 安装插件
		virtual void Install(void) = 0;
		// 初始化插件
		virtual void Initialise(void) = 0;
		// 回收插件
		virtual void ShutDown(void) = 0;
		// 卸载插件
		virtual void UnInstall(void) = 0;
		// 获得插件版本
		virtual CPluginVersion GetVersion(void) = 0;
	};
}

#endif // !_PUBLICE_IPLUGIN_H_
