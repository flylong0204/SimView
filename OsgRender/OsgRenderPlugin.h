/**************************************************
outher: LJ
time: 2015-11-01
use: osg��Ⱦ������
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
		// ���캯��
		explicit COsgRenderPlugin(const SVString& strName);
		// ��������
		virtual ~COsgRenderPlugin();
		
	public:
		// ��װ���
		virtual void Install(void);
		// ��ÿ�汾
		virtual CPluginVersion GetVersion(void);
	};

	// ע����
	REGISTER_PLGUIN(OSGRENDER_EXPORT, COsgRenderPlugin, COMNAME_OSGRENDER);


}

#endif // !_OSGRENDERPLUGIN_H_
