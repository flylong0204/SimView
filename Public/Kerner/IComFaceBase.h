/**************************************************
outher: LJ
time: 2015-10-24
use: �������ͷ�ļ�
from: 
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_ICOMFACEBASE_H_
#define _PUBLIC_ICOMFACEBASE_H_

namespace SimView
{
	class KERNER_DLL IComFaceBase
	{
	public:
		// ��������
		virtual ~IComFaceBase(void) { }
		// �����������
		virtual void SetName(const SVString& strName) = 0;
		// ����������
		virtual const SVString& GetName(void) const = 0;
		// �������
		virtual const SVString& GetTypeName(void) const = 0;
		// ����ʱ���ó�ʼ��
		virtual void Init(void) = 0;
	};

//////////////////////////////////////////////////////////////////////////
	// �������
	typedef struct ComFaceBaseData_typ
	{
		SVString strName; // �������
		SVString strTypeName; // �����������
		SVString strDescript; // �������
	}ComFaceBaseData;


	// ���������
	class IComBaseFactory
	{
	public:
		IComBaseFactory() :m_ComDataInit(true){}
		virtual ~IComBaseFactory() { }

	public:
		virtual const ComFaceBaseData& GetMetaData(void) const
		{
			if (m_ComDataInit)
			{
				InitData();
				m_ComDataInit = false;
			}
			return m_ComFaceBaseData;
		}
		// ������ʵ��
		virtual IComFaceBase* CreateInstance(const SVString& strName) = 0;
		// ����ʵ��
		virtual void DestoryInstance(IComFaceBase* pIInstance) = 0;
	protected:
		// ��ʼ������
		virtual void InitData(void) const = 0;

	protected:
		mutable bool m_ComDataInit; // �Ƿ��ʼ��
		mutable ComFaceBaseData m_ComFaceBaseData; // �������
	};

#define CREATE_COMBASEFACTORY(CLASSNAME, TYPENAME, INSTNAME, DISC) \
	class CLASSNAME##Factory : public IComBaseFactory \
	{ \
	public: \
	CLASSNAME##Factory() { } \
	virtual ~CLASSNAME##Factory() { } \
	public: \
	virtual IComFaceBase* CreateInstance(const SVString& strName = INSTNAME) \
	{ \
	IComFaceBase* pIComFaceBase = new CLASSNAME; \
	pIComFaceBase->SetName(strName); \
	return (pIComFaceBase); \
	}\
	virtual void DestoryInstance(IComFaceBase* pIInstance)\
	{\
	SIMVIEW_DELETE(pIInstance); \
	} \
	protected: \
	virtual void InitData(void) const \
	{ \
	m_ComFaceBaseData.strName = INSTNAME; \
	m_ComFaceBaseData.strDescript = DISC; \
	m_ComFaceBaseData.strTypeName = TYPENAME; \
	} \
	public: \
	static SVString FACTORY_TYPE_NAME; \
	};
}

#endif // _PUBLIC_ICOMFACEBASE_H_
