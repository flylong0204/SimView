/**************************************************
outher: LJ
time: 2015-10-24
use: 插件基类头文件
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
		// 析构函数
		virtual ~IComFaceBase(void) { }
		// 设置组件名称
		virtual void SetName(const SVString& strName) = 0;
		// 获得组件名称
		virtual const SVString& GetName(void) const = 0;
		// 获得类型
		virtual const SVString& GetTypeName(void) const = 0;
		// 创建时调用初始化
		virtual void Init(void) = 0;
	};

//////////////////////////////////////////////////////////////////////////
	// 组件数据
	typedef struct ComFaceBaseData_typ
	{
		SVString strName; // 组件名称
		SVString strTypeName; // 组件类型名称
		SVString strDescript; // 组件描述
	}ComFaceBaseData;


	// 插件工厂类
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
		// 获得组件实例
		virtual IComFaceBase* CreateInstance(const SVString& strName) = 0;
		// 销毁实例
		virtual void DestoryInstance(IComFaceBase* pIInstance) = 0;
	protected:
		// 初始化数据
		virtual void InitData(void) const = 0;

	protected:
		mutable bool m_ComDataInit; // 是否初始化
		mutable ComFaceBaseData m_ComFaceBaseData; // 组件数据
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
