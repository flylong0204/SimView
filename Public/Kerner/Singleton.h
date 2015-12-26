/**********************************************/
/*autor£º LJ				                  */
/*time: 2015-10-18		                      */
/*use:	public singleton head                 */
/*use:				                          */
/*form: ogre singleton                        */
/**********************************************/

#ifndef _PUBLIC_SINGLETON_H_
#define _PUBLIC_SINGLETON_H_

#include <assert.h>
#include <stdlib.h>

namespace SimView
{
	template <typename T>
	class CSingleton
	{
	public:
		explicit CSingleton(void)
		{
			assert(!m_pSingleton);
#if defined( _MSC_VER ) && _MSC_VER < 1200       
			int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
			m_pSingleton = (T*)((int)this + offset);
#else  
			m_pSingleton = static_cast< T* >(this);
#endif  
		}
		virtual ~CSingleton(void)
		{
			assert(m_pSingleton);  m_pSingleton = 0;
		}
		static T& GetSingleton(void)
		{
			assert(m_pSingleton);  return (*m_pSingleton);
		}
		static T* GetSingletonPtr(void)
		{
			return m_pSingleton;
		}

	protected:
		static T* m_pSingleton;

	private:
		CSingleton(const CSingleton<T> &);
		CSingleton& operator=(const CSingleton<T> &);
	};

	template<class T>
	T* CSingleton<T>::m_pSingleton = NULL;
}

#endif // _PUBLIC_SINGLETON_H_