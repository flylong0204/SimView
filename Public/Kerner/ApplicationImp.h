/**************************************************
outher: LJ
time: 2015-12-21
use: 查找插件模版类
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_APPLICATIONIMP_H_
#define _PUBLICE_APPLICATIONIMP_H_

namespace SimView
{
	template <typename T>
	class  CApplicationImp
	{
	public:
		// 获得插件
		static T* GetComposition(const SVString& strComName);

	};

	template <typename T>
	 T* CApplicationImp<T>::GetComposition(const SVString& strComName)
	{
		 IComFaceBase* pIComFaceBase = IPluginManage::GetSingleton().GetComInstance(strComName);
		 T* pIInteface = dynamic_cast<T*>(pIComFaceBase);
		 return (pIInteface);
	}
}

#endif // _PUBLICE_APPLICATIONIMP_H_
