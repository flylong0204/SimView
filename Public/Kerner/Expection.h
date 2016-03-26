/**********************************************/
/*autor�� LJ				                  */
/*time: 2015-10-19		                      */
/*use:	the expection header                  */
/*use:				                          */
/**********************************************/

#ifndef _EXPECTION_H_
#define _EXPECTION_H_

#pragma once

#include <exception>

namespace SimView
{
	class KERNER_EXPORT CSVExpection : public std::exception
	{
	public:
		enum ExceptionCodes {
			ERR_CANNOT_WRITE_TO_FILE,
			ERR_INVALID_STATE,
			ERR_INVALIDPARAMS,
			ERR_RENDERINGAPI_ERROR,
			ERR_DUPLICATE_ITEM,
			ERR_ITEM_NOT_FOUND,
			ERR_FILE_NOT_FOUND,
			ERR_INTERNAL_ERROR,
			ERR_RT_ASSERTION_FAILED,
			ERR_NOT_IMPLEMENTED,
			ERR_CONVERT_FAILD
		};
		
	public:
		// ���캯��
		 CSVExpection(int number, const SVString& description, const SVString& source);
		// ���캯��
		 CSVExpection(int number, const SVString& description, const SVString& source, \
			 const SVChar* type, const SVChar* file, long line);
		// �������캯��
		 CSVExpection(const CSVExpection& rhs);
		// ��������
		virtual ~CSVExpection(void);
		// ��ֵ
		CSVExpection& operator = (const CSVExpection& rhs);
		// ���ȫ������
		virtual const SVString& GetFullDescription(void) const;
		// ��ô�����
		virtual int GetNumber(void) const throw();
		// ���Դ�ļ�
		virtual const SVString& GetSource(void) const;
		// ���Դ�ļ�
		virtual const SVString& GetFile(void) const;
		// ��ô����к�
		virtual int GetLine(void) const;
		// �������
		virtual const SVString& GetDescription(void) const;
		// �����κ���Ϣ
		virtual const SVChar* what(void) const { return GetFullDescription().c_str(); }

	private:
		long m_line; // ����
		int m_number; // ������
		SVString m_typeName; // ��������
		SVString m_description; // ����
		SVString m_source; // ��������
		SVString m_file; // �ļ�����
		mutable SVString m_strFullDec; // ȫ������
	};

	/************************************************************************/
	/* ʹ��ģ�����ʵ����������                                             */
	/************************************************************************/
	template <int num>
	struct ExceptionCodeType
	{
		enum { number = num };
	};

	// δʵ���쳣
	class KERNER_EXPORT CUnimplementedExpection : public CSVExpection
	{
	public:
		 CUnimplementedExpection(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "UnimplementedException", inFile, inLine)
		{
		}

		virtual ~CUnimplementedExpection(void) { }
	};

	// �ļ��������쳣
	class KERNER_EXPORT CFileNotFoundException : public CSVExpection
	{
	public:
		CFileNotFoundException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "FileNotFoundException", inFile, inLine)
		{
		}
		virtual ~CFileNotFoundException(void) { }
	};

	// IO���쳣
	class KERNER_EXPORT CIOException : public CSVExpection
	{
	public: 
		CIOException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			:CSVExpection(inNumber, inDescription, inSource, "IOException", inFile, inLine)
		{

		}
		virtual ~CIOException(void) { }
	};

	// ��Ч״̬�쳣
	class KERNER_EXPORT CInvalidStateException : public CSVExpection
	{
	public:
		 CInvalidStateException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "InvalidStateException", inFile, inLine) {}
		virtual ~CInvalidStateException(void) { }
	};

	// ��Ч����
	class KERNER_EXPORT CInvalidParametersException : public CSVExpection
	{
	public:
		 CInvalidParametersException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "InvalidParametersException", inFile, inLine) {}
		virtual ~CInvalidParametersException(void) { }
	};

	// ��Ч��
	class KERNER_EXPORT CItemIdentityException : public CSVExpection
	{
	public:
		 CItemIdentityException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "ItemIdentityException", inFile, inLine) {}
		virtual ~CItemIdentityException(void) { }
	};

	// �ڲ������쳣
	class KERNER_EXPORT CInternalErrorException : public CSVExpection
	{
	public:
		 CInternalErrorException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "InternalErrorException", inFile, inLine) {}
		virtual ~CInternalErrorException(void) { }
	};

	// ��Ⱦ�ӿ��쳣
	class KERNER_EXPORT CRenderingAPIException : public CSVExpection
	{
	public:
		 CRenderingAPIException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "RenderingAPIException", inFile, inLine) {}
		virtual ~CRenderingAPIException(void) { }
	};

	// ���з����쳣
	class KERNER_EXPORT CRuntimeAssertionException : public CSVExpection
	{
	public:
		 CRuntimeAssertionException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "RuntimeAssertionException", inFile, inLine) {}
		virtual ~CRuntimeAssertionException(void) { }
	};

	// ת��ʧ��
	class KERNER_EXPORT CConvertException : public CSVExpection
	{
	public:
		CConvertException(int inNumber, const SVString& inDescription, const SVString& inSource, \
			const SVChar* inFile, long inLine)
			: CSVExpection(inNumber, inDescription, inSource, "RuntimeAssertionException", inFile, inLine) {}
		virtual ~CConvertException(void) { }
	};

	//////////////////////////////////////////////////////////////////////////
	// �쳣���󹤳�
	class CExceptionFactory
	{
	private:
		/// Private constructor, no construction
		explicit CExceptionFactory(void) {}
	public:
		static CUnimplementedExpection create(
			ExceptionCodeType<CSVExpection::ERR_NOT_IMPLEMENTED> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CUnimplementedExpection(code.number, desc, src, file, line);
		}
		static CFileNotFoundException create(
			ExceptionCodeType<CSVExpection::ERR_FILE_NOT_FOUND> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CFileNotFoundException(code.number, desc, src, file, line);
		}
		static CIOException create(
			ExceptionCodeType<CSVExpection::ERR_CANNOT_WRITE_TO_FILE> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CIOException(code.number, desc, src, file, line);
		}
		static CInvalidStateException create(
			ExceptionCodeType<CSVExpection::ERR_INVALID_STATE> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CInvalidStateException(code.number, desc, src, file, line);
		}
		static CInvalidParametersException create(
			ExceptionCodeType<CSVExpection::ERR_INVALIDPARAMS> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CInvalidParametersException(code.number, desc, src, file, line);
		}
		static CItemIdentityException create(
			ExceptionCodeType<CSVExpection::ERR_ITEM_NOT_FOUND> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CItemIdentityException(code.number, desc, src, file, line);
		}
		static CItemIdentityException create(
			ExceptionCodeType<CSVExpection::ERR_DUPLICATE_ITEM> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CItemIdentityException(code.number, desc, src, file, line);
		}
		static CInternalErrorException create(
			ExceptionCodeType<CSVExpection::ERR_INTERNAL_ERROR> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CInternalErrorException(code.number, desc, src, file, line);
		}
		static CRenderingAPIException create(
			ExceptionCodeType<CSVExpection::ERR_RENDERINGAPI_ERROR> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CRenderingAPIException(code.number, desc, src, file, line);
		}
		static CRuntimeAssertionException create(
			ExceptionCodeType<CSVExpection::ERR_RT_ASSERTION_FAILED> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CRuntimeAssertionException(code.number, desc, src, file, line);
		}
		static CConvertException create(
			ExceptionCodeType<CSVExpection::ERR_CONVERT_FAILD> code,
			const SVString& desc,
			const SVString& src, const char* file, long line)
		{
			return CConvertException(code.number, desc, src, file, line);
		}
	};

	//////////////////////////////////////////////////////////////////////////////
	// �����쳣��
#ifndef SIMVIEW_EXCEPT
#define SIMVIEW_EXCEPT(num, desc, src) throw CExceptionFactory::create( \
	ExceptionCodeType<num>(), desc, src, __FILE__, __LINE__);
#endif
}

#endif // _EXPECTION_H_