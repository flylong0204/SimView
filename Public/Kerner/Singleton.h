/**********************************************/
/*autor£º LJ				                  */
/*time: 2015-10-18		                      */
/*use:	public singleton head                 */
/*use:				                          */
/*form: ogre singleton                        */
/**********************************************/

#ifndef _PUBLIC_SINGLETON_H_
#define _PUBLIC_SINGLETON_H_

namespace SimView
{
	template <typename T>
	class CSingleton
	{
	public:
		explicit CSingleton(void)
		{
			assert(!ms_Singleton);
#if defined( _MSC_VER ) && _MSC_VER < 1200       
			int offset = (int)(T*)1 - (int)(Singleton <T>*)(T*)1;
			ms_Singleton = (T*)((int)this + offset);
#else  
			ms_Singleton = static_cast< T* >(this);
#endif  
		}
		virtual ~CSingleton(void)
		{
			assert(ms_Singleton);  ms_Singleton = 0;
		}
		static T& getSingleton(void)
		{
			assert(ms_Singleton);  return (*ms_Singleton);
		}
		static T* getSingletonPtr(void)
		{
			return ms_Singleton;
		}
	};
}

#endif // _PUBLIC_SINGLETON_H_