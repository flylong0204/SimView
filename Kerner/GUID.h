/**************************************************
outher: LJ
time: 2015-12-21
use: Generate the GUID
from:
chanage:
change outher :
**************************************************/

#ifndef _GUID_H_
#define  _GUID_H_

#pragma once

namespace SimView
{
	class CGUID
	{
	public:
		explicit CGUID();
		~CGUID();

		// ����guid
		static long_l Generate(void);
	};

}

#endif // ! _GUID_H_