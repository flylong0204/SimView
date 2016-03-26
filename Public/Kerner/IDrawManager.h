/**************************************************
outher: LJ
time: 2016-03-23
use: ��Ⱦ���Թ���ӿ�
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLICE_IDRAWMANAGER_H_
#define _PUBLICE_IDRAWMANAGER_H_


namespace SimView
{
#define DrawObj void
#define EarthMapNode void

	class IDrawAttribute;

	class KERNER_EXPORT IDrawManager
	{
	public:
		// ���ʵ��
		virtual IEntity* GetEntity(void) const = 0;
		// ���õ�����
		virtual void SetMapNode(EarthMapNode* pMapNode) = 0;
		// �����Ⱦ��
		virtual DrawObj* GetDrawObj(void) = 0;
		// ��ø���Ⱦ��
		virtual DrawObj* GetRootDrawObj(void) = 0;
		// �����Ⱦ��
		virtual void Add(IDrawAttribute* pIDrawAttribute) = 0;
		// �Ƴ���Ⱦ����
		virtual void Remove(IDrawAttribute* pIDrawAttribute) = 0;
		// �����Ⱦ����
		virtual IDrawAttribute* GetAttribute(const SVString& strName) const = 0;
		// ��������
		virtual void Update(void) = 0;
	};
}

#endif // !_PUBLICE_IDRAWMANAGER_H_
