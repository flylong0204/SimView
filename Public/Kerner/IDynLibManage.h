/**************************************************
outher: LJ
time: 2015-10-24
use: 动态管理类接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_IDYNLIBMANAGE_H_
#define  _PUBLICE_IDYNLIBMANAGE_H_

namespace SimView
{
	class KERNER_DLL IDynLibManage : public CSingleton<IDynLibManage>
	{
	public:
		// 析构函数
		virtual ~IDynLibManage(void) { }
		// 导入动态库
		virtual CDynamicLib* Load(const SVString& strDynLibName) = 0;
		// 卸载动态库
		virtual void UnLoad(CDynamicLib* pDynLib) = 0;
	};
}

#endif