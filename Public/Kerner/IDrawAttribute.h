/**************************************************
outher: LJ
time: 2016-03-23
use: 渲染属性属性项接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_IDRAWATTRIBUTE_H_
#define _PUBLICE_IDRAWATTRIBUTE_H_

namespace SimView
{
	class KERNER_EXPORT IDrawAttribute : public IAttribute
	{
	public:
		// 析构函数
		virtual ~IDrawAttribute(void) { }
		// 更新
		virtual void Update(void) = 0;
		// 获得渲染体
		virtual DrawObj* GetDrawObj(void) = 0;
	};
}

#endif // !_PUBLICE_IDRAWATTRIBUTE_H_
