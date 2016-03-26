/**************************************************
outher: LJ
time: 2015-12-31
use: the composite of Entity
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IENTITYCOMPOSITE_H_
#define _PUBLIC_IENTITYCOMPOSITE_H_

namespace SimView
{
	class KERNER_DLL IEntityComposite : public IEntity
	{
	public:
		// Îö¹¹º¯Êý
		virtual ~IEntityComposite(void) { }
	};
}

#endif // !_PUBLIC_IENTITYCOMPOSITE_H_
