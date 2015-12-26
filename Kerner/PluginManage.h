/**********************************************/
/*autor�� LJ				                  */
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
		typedef std::vector<CDynamicLib*> ListPluginLib; // ���������
		typedef std::vector<IPlugin*> ListPluginInstance; // ���ʵ������

	public:
		// ���캯��
		explicit CPluginManage(void);
		// ��������
		virtual ~CPluginManage(void);
		// �����

	public:
		// ��ӹ�������
		virtual void AddFactory(IComBaseFactory* pIFactory);
		// �Ƴ���������
		virtual void RemoveFactory(IComBaseFactory* pIFactory);
		// ��ò������
		virtual IComFaceBase* GetComInstance(const SVString& strName);
		// ������
		virtual bool LoadCom(const SVString& strComPath);
		// �������
		virtual void UnloadCom(const SVString& strComPath);
		// ��װ���
		virtual void Install(IPlugin* pIPlugin);
		// ж�ز��
		virtual void Uninstall(IPlugin* pIPlugin);

	protected:
		// ж�����в��
		virtual void ShutDownAllPlugin();
	private:
		ListPluginLib m_lstPluginLib; // ���������
		ListPluginInstance m_lstPluginInstance; // ʵ������

		bool m_bLoad; // �Ƿ�ֱ�Ӽ��� ����������
	};
}

#endif // _PUGLINMANAGE_H_