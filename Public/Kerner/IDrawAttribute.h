/**************************************************
outher: LJ
time: 2016-03-23
use: ��Ⱦ����������ӿ�
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
		// ��������
		virtual ~IDrawAttribute(void) { }
		// ����
		virtual void Update(void) = 0;
		// �����Ⱦ��
		virtual DrawObj* GetDrawObj(void) = 0;
	};
}

#endif // !_PUBLICE_IDRAWATTRIBUTE_H_
