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
		// ���캯��
		explicit CPluginManage(void);
		// ��������
		virtual ~CPluginManage(void);
	};
}

#endif // _PUGLINMANAGE_H_