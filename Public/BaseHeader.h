/**********************************************/
/*autor�� LJ				                  */
/*time: 2015-10-18		                      */
/*use:	����������ͷ�ļ�		              */
/*use:				                          */
/*form: ogre singleton                        */
/**********************************************/

#ifndef _BASEHEAD_H_
#define _BASEHEAD_H_

#include <assert.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <map>

// ����ƽ̨ͷ�ļ�
#include "Platform.h"
#include "Tool.h"
#include "ThreadDepend.h"

namespace SimView
{
	//////////////////////////////////////////////////////////////////////////
	// �ַ�������
#if UNICODE || _UNICODE
// 	typedef	std::wstringstream  SVSStream;
// 	typedef	std::wstring		SVString;
// 	typedef	wchar_t				SVChar;
#define SVSStream	std::wstringstream
#define SVString	std::wstring
#define SVChar		wchar_t

#else
// 	typedef	std::stringstream	SVSStream;
// 	typedef	std::string			SVString;
// 	typedef	char				SVChar;
#define SVSStream	std::stringstream
#define SVString	std::string
#define SVChar		char
#define SVSprintf	sprintf
#endif // UNICODE

	// ��������
	typedef long long long_l;
	typedef unsigned long long ulong_l;

}
#endif