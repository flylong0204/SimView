#define SIMVIEW_KERNERLIB

#include "../Public/Kerner/Kerner.h"
#include "AttributeItem.h"

namespace SimView
{
	CAttributeItem::CAttributeItem(IAttribute* pIAttribute, const SVString& strName, const SVString& strText, const SVString& strUntil, const Variant& var)
		:m_strAttriName(strName), m_curCanDidatas(strText, var, true), m_bAdded(false), m_strUntil(strUntil)
	{
	}


	CAttributeItem::~CAttributeItem()
	{
	}

	// ���ֵ���Ҳ���STring���ͱ���
	SVString CAttributeItem::GetValueToString(void) const
	{
		SVString str = "";

		// �ӹ����ڴ��ж�ȡ
		(const_cast<CAttributeItem*>(this))->ReadFromMem();

		// �쳣����
		try
		{
			// �ж������Ƿ�Ϊ����  
			if (typeid(int) == m_curCanDidatas.value.type())
			{
				int nVar = boost::any_cast<int>(m_curCanDidatas.value);
				char szTemp[256];
				sprintf(szTemp, "%d", nVar);
				str = SVString(szTemp);

			}
			else if (typeid(float) == m_curCanDidatas.value.type())
			{
				float fVar = boost::any_cast<float>(m_curCanDidatas.value);
				char szTemp[256];
				sprintf(szTemp, "%f", fVar);
				str = SVString(szTemp);
			}
			else if (typeid(double) == m_curCanDidatas.value.type())
			{
				double dVar = boost::any_cast<double>(m_curCanDidatas.value);
				char szTemp[256];
				sprintf(szTemp, "%f", dVar);
				str = SVString(szTemp);
			}
			else if (typeid(SVString) == m_curCanDidatas.value.type())
			{
				str = boost::any_cast<SVString>(m_curCanDidatas.value);
			}
			else if (typeid(bool) == m_curCanDidatas.value.type())
			{
				bool b = boost::any_cast<bool>(m_curCanDidatas.value);
				str = b ? "true" : "false";
			}
			else if (typeid(CFloatPoint3D) == m_curCanDidatas.value.type())
			{
				CFloatPoint3D v = boost::any_cast<CFloatPoint3D>(m_curCanDidatas.value);
				char szTemp[256];
				sprintf(szTemp, "%f,%f,%f", v.x(), v.y(), v.z());
				str = SVString(szTemp);
			}
			else if (typeid(CDoublePoint3D) == m_curCanDidatas.value.type())
			{
				CDoublePoint3D v = boost::any_cast<CDoublePoint3D>(m_curCanDidatas.value);
				char szTemp[256];
				sprintf(szTemp, "%6f,%6f,%6f", v.x(), v.y(), v.z());
				str = SVString(szTemp);
			}
			/*else if (typeid(osg::Vec4) == m_curCanDidatas.value.type())
			{
				osg::Vec4 v = boost::any_cast<osg::Vec4>(m_curCanDidatas.value);
				char szTemp[256];
				sprintf(szTemp, "%f,%f,%f,%f", v.r(), v.g(), v.b(), v.a());
				str = SVString(szTemp);
			}*/
			else if (!m_lstCandidata.Empty())
			{
				char szTemp[256];
				sprintf(szTemp, "%d", m_lstCandidata.SelectCandidata());
				str = SVString(szTemp);
				return (str);
			}
		}
		catch (const boost::bad_any_cast&)
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INVALID_STATE, "����ת��ʧ��", "GetValueToString");
		}


		return (str);
	}

	// ת����osg::Vec3 ���ͱ���
	CFloatPoint3D CAttributeItem::GetValueToVec3(void)
	{
		// �ӹ����ڴ��ж�ȡ
		(const_cast<CAttributeItem*>(this))->ReadFromMem();

		if (m_curCanDidatas.value.type() != typeid(CFloatPoint3D))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INVALID_STATE, "����ת��ʧ��", "GetValueToVec3");
		}

//		CFloatPoint3D v = boost::any_cast<CFloatPoint3D>(m_curCanDidatas.value);
		return (CFloatPoint3D());
	}

	// ת����osg::Vec3 ���ͱ���
	CDoublePoint3D CAttributeItem::GetValueToVec3d(void)
	{
		// �ӹ����ڴ��ж�ȡ
		(const_cast<CAttributeItem*>(this))->ReadFromMem();

		if (m_curCanDidatas.value.type() != typeid(CDoublePoint3D))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INVALID_STATE, "����ת��ʧ��", "GetValueToVec3d");
		}

		CDoublePoint3D v = boost::any_cast<CDoublePoint3D>(m_curCanDidatas.value);
		return (v);
	}

	// ת����Int����
	int CAttributeItem::GetValueToInt(void) const
	{
		// �ӹ����ڴ��ж�ȡ
		(const_cast<CAttributeItem*>(this))->ReadFromMem();

		if (m_curCanDidatas.value.type() != typeid(int))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INVALID_STATE, "����ת��ʧ��", "GetValueToInt");
		}

		int b = boost::any_cast<int>(m_curCanDidatas.value);
		return (b);
	}

	// ת����Int����
	bool CAttributeItem::GetValueToBool(void) const
	{
		// �ӹ����ڴ��ж�ȡ
		(const_cast<CAttributeItem*>(this))->ReadFromMem();

		if (m_curCanDidatas.value.type() != typeid(bool))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INVALID_STATE, "����ת��ʧ��", "GetValueToBool");
		}

		// �ж��Ƿ��д�ѡ��
		bool b = false;
		if (m_lstCandidata.Empty())
		{
			b = boost::any_cast<bool>(m_curCanDidatas.value);
		}
		else
		{
			// �Ӵ�ѡ����ѡȡ��ǰ�����ѡ��
			b = boost::any_cast<bool>(m_lstCandidata.GetVariant());
		}

		return (b);
	}

	// ת����float����
	// ת����Int����
	float CAttributeItem::GetValueToFloat(void) const
	{
		// �ӹ����ڴ��ж�ȡ
		(const_cast<CAttributeItem*>(this))->ReadFromMem();
		const char* pszTypeName = m_curCanDidatas.value.type().name();
		if (m_curCanDidatas.value.type() != typeid(float))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INVALID_STATE, "����ת��ʧ��", "GetValueToFloat");
		}

		float f = boost::any_cast<float>(m_curCanDidatas.value);
		return (f);
	}

	// ת����Double����
	double CAttributeItem::GetValueToDobule(void) const
	{
		// �ӹ����ڴ��ж�ȡ
		(const_cast<CAttributeItem*>(this))->ReadFromMem();
		const char* pszTypeName = m_curCanDidatas.value.type().name();
		if (m_curCanDidatas.value.type() != typeid(double))
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_CONVERT_FAILD, "����ת��ʧ��", "GetValueToDobule");
		}

		double d = boost::any_cast<double>(m_curCanDidatas.value);
		return (d);
	}

	// ��ȡ��������
	SVString CAttributeItem::GetTypeName() const
	{
		return (m_strAttriName);
	}

	// ���������ʾ�ؼ�
	SimView::Contrl CAttributeItem::GetCtrlType() const
	{
		return (m_contrlType);
	}

	// ����������ʾ�ؼ�
	void CAttributeItem::SetCtrlType(Contrl ctrl /*= CTRL_EDIT*/)
	{
		m_contrlType = ctrl;
	}

	// ��������
	void CAttributeItem::SetTypeName(const SVString& strName)
	{
		m_strAttriName = strName;
	}

	// ����ֵ ͨ�������ַ���
	void CAttributeItem::SetValue(const Variant& var, bool bUI)
	{
		// �ж��������Ƿ�һ��
		if (m_curCanDidatas.value.type() != var.type())
		{
			SIMVIEW_EXCEPT(CSVExpection::ERR_INVALID_STATE, "�������Ͳ�һ��", "SetValue");
		}

		// ������ֵ
		m_curCanDidatas.value.clear();
		m_curCanDidatas.value = var;
		m_bChanged = true;

		// ���µ������ڴ���
		WriteMemory();

		if (bUI)
		{
			return;
		}
		//// ˢ�����Կؼ�
		//IEntityManager::GetInstance().GetAttributeManagerInstance()->UpdateAttributeItem(this);

	}

	void CAttributeItem::SetValue(const SVString& strCandidata)
	{
		// �����Ƿ��д�ѡ��
		if (m_lstCandidata.Empty())
		{
			SetValue(Variant(strCandidata));
			return;
		}

		// ��Ϊ�� �Ƿ���� �򷵻ض�Ӧ��ֵ
		bool b;
		Candidatas candidata = m_lstCandidata.GetCandidata(strCandidata, b);
		if (b)
		{
			m_curCanDidatas = candidata;
		}

		m_bChanged = true;

		// д�빲���ڴ���
		WriteMemory();

	}

	// ��Ӵ�ѡ��
	void CAttributeItem::AddCandidatas(const SVString& strText, const Variant& value, bool bSelect)
	{
		// ȷ���̰߳�ȫ
		SIMVIEW_LOCK_AUTO_METEX;

		if (!m_bAdded)
		{
			m_lstCandidata.Add(m_curCanDidatas);
			m_bAdded = true;
		}

		m_lstCandidata.Add(Candidatas(strText, value, bSelect));
	}

	const IAttributeItem::LstCandidatas& CAttributeItem::GetCandidatas(void) const
	{
		return (m_lstCandidata.GetCandidatas());
	}

	// ��ÿɱ�ζ���
	Variant CAttributeItem::GetVariant(void) const
	{
		// ���ڴ����
		(const_cast<CAttributeItem*>(this))->ReadFromMem();
		if (m_lstCandidata.Empty())
		{
			return (m_curCanDidatas.value);
		}
		else
		{
			return (m_lstCandidata.GetVariant());
		}

	}

	// ��ǰ�Ƿ�ı�������ֵ
	bool CAttributeItem::IsChanged(void) const
	{
		// ��ȡ��һ�θı�֮��ֱ������Ϊ���ı䣨�Ժ��кõķ����ڽ��иĽ���
		if (m_bChanged)
		{
			m_bChanged = false;
			return (true);
		}
		else
		{
			return (false);
		}
	}

	int CAttributeItem::SelectCandidata(void)
	{
		ReadFromMem();
		return (m_lstCandidata.SelectCandidata());
	}

	void CAttributeItem::SetSelect(const int index)
	{
		m_lstCandidata.SetSelect(index);

		// д���ڴ���
		WriteMemory();

		m_bChanged = true;
	}

	// ���浽�ڴ濨��
	void CAttributeItem::WriteMemory(void) const
	{
		/*// ����ڴ����
		IMemoryManager* pIMemManage = CComManagerImp::GetComponent<IMemoryManager>(INSTANCE_NAME_MEMORYSYSTEM);
		if (NULL == pIMemManage)
		{
			return;
		}

		VRString strName = GetTypeName();

		// ���ID
		uint64_t ID = GetAttribute()->GetEntity()->GetID();
		// �ж��Ƿ�Ϊö��ֵ
		if (m_lstCandidata.Empty())
		{
			pIMemManage->Write(ID, strName, m_curCanDidatas.value);
		}
		else
		{
			// д��ö��ֵ
			pIMemManage->Write(ID, strName, m_lstCandidata.SelectCandidata());
		}
		*/
	}

	// ���ڴ��ж�ȡ����
	void CAttributeItem::ReadFromMem(void)
	{
		// ����ڴ����
		/*IMemoryManager* pIMemManage = CComManagerImp::GetComponent<IMemoryManager>(INSTANCE_NAME_MEMORYSYSTEM);
		if (NULL == pIMemManage)
		{
			return;
		}

		// ��õ�ǰ��������
		SVString strName = GetTypeName();

		// ���ID
		uint64_t ID = GetAttribute()->GetEntity()->GetID();

		// �ж��Ƿ�Ϊö��ֵ��ǰѡ����
		if (m_lstCandidata.Empty())
		{
			Variant var = pIMemManage->Read(ID, strName, m_curCanDidatas.value.type().name(), m_bChanged);
			m_curCanDidatas.value = var.empty() ? m_curCanDidatas.value : var;
		}
		else
		{
			// ��ȡö��ֵ��ǰѡ����
			Variant var = pIMemManage->Read(ID, strName, "int\0", m_bChanged);
			if (var.empty())
			{
				return;
			}
			m_lstCandidata.SetSelect(boost::any_cast<int>(var));
		}
		*/
	}

	// ռ�ÿռ�Ĵ�С
	size_t CAttributeItem::GetSize(void) const
	{
		// �ж��Ƿ�Ϊö��ֵ
		if (m_lstCandidata.Empty())
		{
			// ������ַ���
			if (typeid(SVString) == m_curCanDidatas.value.type())
			{
				const SVString& str = boost::any_cast<SVString>(m_curCanDidatas.value);
				return (str.size());
			}
			else if (typeid(CDoublePoint3D) == m_curCanDidatas.value.type())
			{
				return (sizeof(CDoublePoint3D));
			}
			else if (typeid(CFloatPoint3D) == m_curCanDidatas.value.type())
			{
				return (sizeof(CFloatPoint3D));
			}
			else if (typeid(int) == m_curCanDidatas.value.type())
			{
				return (sizeof(int));
			}
			else if (typeid(char) == m_curCanDidatas.value.type())
			{
				return (sizeof(char));
			}
			else if (typeid(bool) == m_curCanDidatas.value.type())
			{
				return (sizeof(bool));
			}
			else if (typeid(float) == m_curCanDidatas.value.type())
			{
				return (sizeof(float));
			}
			else if (typeid(double) == m_curCanDidatas.value.type())
			{
				return (sizeof(double));
			}

			return sizeof(m_curCanDidatas.value.type());
		}
		else
		{
			// д��ö��ֵ
			return sizeof(int);
		}
	}

	const SVString& CAttributeItem::GetUntil(void) const
	{
		return (m_strUntil);
	}

}
