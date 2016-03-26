/**************************************************
outher: LJ
time: 2016-03-23
use: 属性项接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IATTRIBUTEITEM_
#define _PUBLIC_IATTRIBUTEITEM_

namespace SimView
{
	typedef enum _Typ
	{
		CTRL_EDIT,		// 文本框
		CTRL_SPINBOX,	// 浮点框
		CTRL_BUTTON,	// 按钮
		CTRL_COMBOX,	// 组合框
		CTRL_TREE,		// 树形框
		CTRL_TRATEGY	// 策略框
	}Contrl;

	// 候选结构体
	typedef struct Candidatas_TYP
	{
		SVString strText; // 对应文本
		Variant value; // 当前值
		bool bSelect; // 当前选中

		Candidatas_TYP(SVString str, Variant v)
			:strText(str), value(v), bSelect(false)
		{

		}
		Candidatas_TYP(SVString str, Variant v, bool b)
			:strText(str), value(v), bSelect(b)
		{

		}
		Candidatas_TYP(const Candidatas_TYP& other)
			:strText(other.strText), value(other.value), bSelect(other.bSelect)
		{

		}

		bool operator== (const Candidatas_TYP& other)
		{
			return (strText == other.strText);
		}

		bool operator== (const SVString& strName) const
		{
			return (strText == strName);
		}

	}Candidatas, PTR_Candidatas;

	class KERNER_EXPORT IAttributeItem
	{
	public:
		// 候选的所有选项
		typedef std::list<Candidatas> LstCandidatas;

	public:
		// 析构函数
		virtual ~IAttributeItem(void) {}
		// 获取属性名称
		virtual SVString GetTypeName() const = 0;
		// 设置名称
		virtual void SetTypeName(const SVString& strName) = 0;
		// 获得属性显示控件
		virtual Contrl GetCtrlType() const = 0;
		// 设置属性显示控件
		virtual void SetCtrlType(Contrl ctrl = CTRL_EDIT) = 0;

	public:
		// 获得值并且采用STring类型表现
		virtual SVString GetValueToString(void) const = 0;
		// 转换成osg::Vec3 类型表现
		virtual CFloatPoint3D GetValueToVec3(void) = 0;
		// 转换成osg::Vec3 类型表现
		virtual CDoublePoint3D GetValueToVec3d(void) = 0;
		// 转换成Int类型
		virtual int GetValueToInt(void) const = 0;
		// 转换成float类型
		virtual float GetValueToFloat(void) const = 0;
		// 设置值 通过设置字符串
		virtual void SetValue(const Variant& var, bool bUI = true) = 0;
		// 转换成Int类型
		virtual bool GetValueToBool(void) const = 0;
		// 转换成Double类型
		virtual double GetValueToDobule(void) const = 0;
		// 添加待选项
		virtual void AddCandidatas(const SVString& strText, const Variant& value, bool bSelect = false) = 0;
		// 获得待选列表
		virtual const LstCandidatas& GetCandidatas(void) const = 0;
		// 获得可变参对象
		virtual Variant GetVariant(void) const = 0;
		// 当前属性值是否有变更
		virtual bool IsChanged(void) const = 0;
		// 获得当前选择的序号
		virtual int SelectCandidata(void) = 0;
		// 设置选择的序号
		virtual void SetSelect(const int index) = 0;
		// 保存到内存卡中
		virtual void WriteMemory(void) const = 0;
		// 占用空间的大小
		virtual size_t GetSize(void) const = 0;
		// 获得单位
		virtual const SVString& GetUntil(void) const = 0;

	};

}

#endif // !_PUBLIC_IATTRIBUTEITEM_
