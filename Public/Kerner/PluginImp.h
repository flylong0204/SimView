/**************************************************
outher: LJ
time: 2015-10-24
use: ���ϵͳģ��ͷ�ļ�
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
		// ���캯��
		explicit CPluginImp(const SVString& strName);
		// ��������
		virtual ~CPluginImp() { }
		// ��ò������
		virtual const SVString& GetName(void) const;
		// ��ʼ�����
		virtual void Initialise(void);
		// ���ղ��
		virtual void ShutDown(void);
		// ж�ز��
		virtual void UnInstall(void);

	private:
		// ���캯��
		explicit CPluginImp(const CPluginImp& plugin) { }

	protected:
		IComBaseFactory* m_pIComBaseFactory; // �������

	private:
		const SVString m_strName; // �������
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


	// ��ʼ�����
	template <typename T>
	void CPluginImp<T>::Initialise(void)
	{
		// ע�Ṥ������ϵͳ��
		IPluginManage::GetSingleton().AddFactory(m_pIComBaseFactory);
	}

	// ���ղ��
	template <typename T>
	void CPluginImp<T>::ShutDown(void)
	{
		// ������ע�ᵽϵͳ��
		IPluginManage::GetSingleton().RemoveFactory(m_pIComBaseFactory);
	}

	// ж�ز��
	template <typename T>
	void CPluginImp<T>::UnInstall(void)
	{
		// ɾ������
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
