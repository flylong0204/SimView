/**************************************************
outher: LJ
time: 2016-03-15
use: 实体工厂管理类， 进行实体工程类型实例化的管理
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IENTITYFACTORYTYPE_H_
#define _PUBLIC_IENTITYFACTORYTYPE_H_

namespace SimView
{
	class KERNER_EXPORT IEntityFactoryType : public IEntityBaseFactory
	{
	public:
		typedef std::vector<IEntityBaseFactory*> ListEntityFactorys;
	public:
		// 析构函数
		virtual ~IEntityFactoryType() { }
		// 获得所有的子工厂
		virtual ListEntityFactorys GetChilds(void) const = 0;
		
	};
}
#endif // _PUBLIC_IENTITYFACTORYTYPE_H_0