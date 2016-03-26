/**************************************************
outher: LJ
time: 2016-03-23
use: ������ӿ�
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
		CTRL_EDIT,		// �ı���
		CTRL_SPINBOX,	// �����
		CTRL_BUTTON,	// ��ť
		CTRL_COMBOX,	// ��Ͽ�
		CTRL_TREE,		// ���ο�
		CTRL_TRATEGY	// ���Կ�
	}Contrl;

	// ��ѡ�ṹ��
	typedef struct Candidatas_TYP
	{
		SVString strText; // ��Ӧ�ı�
		Variant value; // ��ǰֵ
		bool bSelect; // ��ǰѡ��

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
		// ��ѡ������ѡ��
		typedef std::list<Candidatas> LstCandidatas;

	public:
		// ��������
		virtual ~IAttributeItem(void) {}
		// ��ȡ��������
		virtual SVString GetTypeName() const = 0;
		// ��������
		virtual void SetTypeName(const SVString& strName) = 0;
		// ���������ʾ�ؼ�
		virtual Contrl GetCtrlType() const = 0;
		// ����������ʾ�ؼ�
		virtual void SetCtrlType(Contrl ctrl = CTRL_EDIT) = 0;

	public:
		// ���ֵ���Ҳ���STring���ͱ���
		virtual SVString GetValueToString(void) const = 0;
		// ת����osg::Vec3 ���ͱ���
		virtual CFloatPoint3D GetValueToVec3(void) = 0;
		// ת����osg::Vec3 ���ͱ���
		virtual CDoublePoint3D GetValueToVec3d(void) = 0;
		// ת����Int����
		virtual int GetValueToInt(void) const = 0;
		// ת����float����
		virtual float GetValueToFloat(void) const = 0;
		// ����ֵ ͨ�������ַ���
		virtual void SetValue(const Variant& var, bool bUI = true) = 0;
		// ת����Int����
		virtual bool GetValueToBool(void) const = 0;
		// ת����Double����
		virtual double GetValueToDobule(void) const = 0;
		// ��Ӵ�ѡ��
		virtual void AddCandidatas(const SVString& strText, const Variant& value, bool bSelect = false) = 0;
		// ��ô�ѡ�б�
		virtual const LstCandidatas& GetCandidatas(void) const = 0;
		// ��ÿɱ�ζ���
		virtual Variant GetVariant(void) const = 0;
		// ��ǰ����ֵ�Ƿ��б��
		virtual bool IsChanged(void) const = 0;
		// ��õ�ǰѡ������
		virtual int SelectCandidata(void) = 0;
		// ����ѡ������
		virtual void SetSelect(const int index) = 0;
		// ���浽�ڴ濨��
		virtual void WriteMemory(void) const = 0;
		// ռ�ÿռ�Ĵ�С
		virtual size_t GetSize(void) const = 0;
		// ��õ�λ
		virtual const SVString& GetUntil(void) const = 0;

	};

}

#endif // !_PUBLIC_IATTRIBUTEITEM_
