/**************************************************
outher: LJ
time: 2015-10-24
use: 动态管理类
from:
chanage:
change outher :
**************************************************/

#ifndef _DYNLIBMANAGE_H_
#define _DYNLIBMANAGE_H_

#pragma once

namespace SimView
{
	class CDynLibManage : public IDynLibManage
	{
	public:
		// 构造函数
		explicit CDynLibManage(void);
		// 析构函数
		virtual ~CDynLibManage(void);

	public:
		// 导入动态库
		virtual CDynamicLib* Load(const SVString& strDynLibName);
		// 卸载动态库
		virtual void UnLoad(CDynamicLib* pDynLib);

	private:
		// 类型
		typedef std::map<SVString, CDynamicLib*> DynLibList; 
	private:
		// 所有列表
		DynLibList m_lstDynLib;
	};

}


#endif //  _DYNLIBMANAGE_H_