/**************************************************
outher: LJ
time: 2016-03-15
use: ʵ�幤�������࣬ ����ʵ�幤������ʵ�����Ĺ���
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
		// ��������
		virtual ~IEntityFactoryType() { }
		// ������е��ӹ���
		virtual ListEntityFactorys GetChilds(void) const = 0;
		
	};
}
#endif // _PUBLIC_IENTITYFACTORYTYPE_H_0