#define SIMVIEW_KERNERLIB

#include "../Public/BaseHeader.h"
#include "../Public/Kerner/Kerner.h"

namespace SimView
{
	CSVExpection::CSVExpection(int number, const SVString& description, const SVString& source)
		:m_line(0),
		m_number(number),
		m_description(description),
		m_source(source)
	{
	}

	// 构造函数
	CSVExpection::CSVExpection(int number, const SVString& description, const SVString& source, \
		const SVChar* type, const SVChar* file, long line)
		:m_line(line),
		m_number(number),
		m_typeName(type),
		m_description(description),
		m_source(source),
		m_file(file)
	{

	}

	CSVExpection::CSVExpection(const CSVExpection& rhs)
		:m_line(rhs.m_line),
		m_number(rhs.m_number),
		m_typeName(rhs.m_typeName),
		m_description(rhs.m_description),
		m_source(rhs.m_source),
		m_file(rhs.m_file)
	{

	}


	CSVExpection::~CSVExpection(void)
	{
	}

	// 赋值构造
	CSVExpection& CSVExpection::operator=(const CSVExpection& rhs)
	{
		m_line = rhs.m_line;
		m_number = rhs.m_number;
		m_typeName = rhs.m_typeName;
		m_description = rhs.m_description;
		m_source = rhs.m_source;
		m_file = rhs.m_file;
		m_strFullDec = rhs.m_strFullDec;

		return (*this);
	}

	// 获得全部描述
	const SVString& CSVExpection::GetFullDescription(void) const
	{
		if (m_strFullDec.empty())
		{

			SVSStream desc;

			desc << "SIMVIEW EXCEPTION(" << m_number << ":" << m_typeName << "): "
				<< m_description
				<< " in " << m_source;

			if (m_line > 0)
			{
				desc << " at " << m_file << " (line " << m_line << ")";
			}

			m_strFullDec = desc.str();
		}

		return m_strFullDec;
	}

	// 获得错误码
	int CSVExpection::GetNumber(void) const throw()
	{
		return (m_number);
	}

	// 获得源文件
	const SVString& CSVExpection::GetSource(void) const
	{
		return (m_source);
	}

	// 获得源文件
	const SVString& CSVExpection::GetFile(void) const
	{
		return (m_file);
	}

	// 获得描述
	const SVString& CSVExpection::GetDescription(void) const
	{
		return (m_description);
	}

	// 获得错误行号
	int CSVExpection::GetLine(void) const
	{
		return (m_line);
	}

}
