/**************************************************
outher: LJ
time: 2016-03-23
use: osg���������
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
		// ���캯��
		explicit COsgEarthPlugin(const SVString& strName);
		// ��������
		virtual ~COsgEarthPlugin();

	public:
		// ��װ���
		virtual void Install(void);
		// ��ÿ�汾
		virtual CPluginVersion GetVersion(void);
	};

	// ע����
	REGISTER_PLGUIN(OSG_EARTH_EXPORT, COsgEarthPlugin, COMNAME_OSGEARTH);
}


#endif // !_OSGEARTHPLUGIN_H_