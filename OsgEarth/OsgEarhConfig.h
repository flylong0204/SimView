/**************************************************
outher: LJ
time: 2016-03-26
use: �������ӿڣ��ṩ
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGEARTHCONFIG_H_
#define _OSGEARTHCONFIG_H_

#pragma once

namespace SimView
{
	class COsgEarhConfig
	{
	public:
		// ���캯��
		explicit COsgEarhConfig(void);
		// ��������
		~COsgEarhConfig(void);

	protected:
		// ��ʼ��
		void Init(void);
		// ��ȡ�����ļ�
		void GetEarthNode(void);
	private:
		IConfigFileUtil* m_pIConfigFileUtil; // �����ļ�������
	};
}


#endif // !_OSGEARTHCONFIG_H_