/**************************************************
outher: LJ
time: 2015-10-24
use: ��̬������
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
		// ���캯��
		explicit CDynLibManage(void);
		// ��������
		virtual ~CDynLibManage(void);

	public:
		// ���붯̬��
		virtual CDynamicLib* Load(const SVString& strDynLibName);
		// ж�ض�̬��
		virtual void UnLoad(CDynamicLib* pDynLib);

	private:
		// ����
		typedef std::map<SVString, CDynamicLib*> DynLibList; 
	private:
		// �����б�
		DynLibList m_lstDynLib;
	};

}


#endif //  _DYNLIBMANAGE_H_