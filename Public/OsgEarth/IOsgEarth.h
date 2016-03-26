/**************************************************
outher: LJ
time: 2016-03-23
use: 地球管理接口，提供
from:
chanage:
change outher :
**************************************************/
#ifndef _PUBLIC_IOSGEARTH_H_
#define _PUBLIC_IOSGEARTH_H_

// 定义导出关键字
#ifdef OSGEARTH_DLL
#define OSG_EARTH_EXPORT SIMVIEW_EXPORT
#else 
#define OSG_EARTH_EXPORT SIMVIEW_IMPORT
#endif // OSGREARTH_DLL

namespace SimView
{
	const SVString COMTYPE_OSGEARTH = "Osg Earth";
	const SVString COMNAME_OSGEARTH = "OsgEarth";
	const SVString COMDIR_OSGEARTH = "use osg render the osgearth";

	class IOsgEarthManage;

	class OSG_EARTH_EXPORT IOsgEarth : public IComFaceBase
	{
	public:
		virtual ~IOsgEarth() { }
		// 获得数字地球管理节点
		virtual IOsgEarthManage* GetOsgEarhManage(void) const = 0;
		// 渲染地球
		virtual void DrawEarth(void) = 0;

	};
}

#endif // !_PUBLIC_IOSGEARTH_H_
