/**********************************************/
/*autor： LJ				                  */
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
		// 构造函数
		explicit CPluginManage(void);
		// 析构函数
		virtual ~CPluginManage(void);
	};
}

#endif // _PUGLINMANAGE_H_