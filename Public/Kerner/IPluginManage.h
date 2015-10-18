/**********************************************/
/*autor£º LJ				                  */
/*time: 2015-10-18		                      */
/*use:	public singleton head                 */
/*use:				                          */
/*form: ogre singleton                        */
/**********************************************/

#ifndef _IPUGLINMANAGE_H_
#define _IPUGLINMANAGE_H_

#pragma once

#include "Singleton.h"

namespace SimView
{
	class IPluginManage : public CSingleton<IPluginManage>
	{
	public:
		// Îö¹¹º¯Êý  
		virtual ~IPluginManage(void) { }
	};
}

#endif // _IPUGLINMANAGE_H_