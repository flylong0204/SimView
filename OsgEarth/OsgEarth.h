/**************************************************
outher: LJ
time: 2016-03-23
use: �������ӿڣ��ṩ
from:
chanage:
change outher :
**************************************************/
#ifndef _OSGEARTH_H_
#define _OSGEARTH_H_

#pragma once

#include <osg/Group>

namespace SimView
{
	class COsgEarhConfig;
	class COsgEarthManage;

	class COsgEarth : public IOsgEarth
	{
	public:
		// ���캯��
		explicit COsgEarth(void);
		// ��������
		virtual ~COsgEarth(void);

	public:
		// �����������
		virtual void SetName(const SVString& strName);
		// ����������
		virtual const SVString& GetName(void) const;
		// �������
		virtual const SVString& GetTypeName(void) const;
		// ����ʱ���ó�ʼ��
		virtual void Init(void);

	public:
		// ��Ⱦ����
		virtual void DrawEarth(void);
		// ������ֵ������ڵ�
		virtual IOsgEarthManage* GetOsgEarhManage(void) const ;

	protected:
		// ���ò�����
		void SetEarthManipulator(void);

	private:
		SVString m_strName;

		COsgEarthManage* m_pOsgEarthManage;

		COsgEarhConfig* m_pEarthConfig; // �����ļ�

		osg::Group* m_pEarthRoot; // ������ڵ�

		bool m_bInit; // �Ƿ��ʼ��

	};

	// ��������
	CREATE_COMBASEFACTORY(COsgEarth, COMTYPE_OSGEARTH, COMNAME_OSGEARTH, COMDIR_OSGEARTH)
}


#endif // !_OSGEARTH_H_