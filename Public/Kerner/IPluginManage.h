/**********************************************/
/*autor�� LJ				                  */
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
		// ��������  
		virtual ~IPluginManage(void) { }
		// ��ӹ�������
		virtual void AddFactory(IComBaseFactory* pIFactory) = 0;
		// �Ƴ���������
		virtual void RemoveFactory(IComBaseFactory* pIFactory) = 0;
		// ��ò������
		virtual IComFaceBase* GetComInstance(const SVString& strName) = 0;
		// ������
		virtual bool LoadCom(const SVString& strComPath) = 0;
		// ��װ���
		virtual void Install(IPlugin* pIPlugin) = 0;
		// ж�ز��
		virtual void Uninstall(IPlugin* pIPlugin) = 0;
	};
}

#endif // _IPUGLINMANAGE_H_