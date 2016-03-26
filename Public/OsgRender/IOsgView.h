/**************************************************
outher: LJ
time: 2015-11-01
use: osg渲染类接口
from:
chanage:
change outher :
**************************************************/

#ifndef _PUBLIC_IOSGVIEW_H_
#define _PUBLIC_IOSGVIEW_H_

namespace SimView
{
#define SVView void
#define CameraManip void // 相机控制器

	class OSGRENDER_EXPORT IOsgView
	{
	public:
		// 析构函数
		virtual ~IOsgView() { }
		// 获得视图
		virtual SVView* GetView(void) const = 0;
		// 添加节点
		virtual void AddRenderObj(DrawObj* pRenderObj) = 0;
		// 添加相机控制器
		virtual void AddCameraManipulator(const SVString& strName, CameraManip* pCameraManip) = 0;
		// 选择操作器
		virtual void SelectCameraManipulator(const SVString& strName) = 0;
	};
}

#endif // !_PUBLIC_IOSGVIEW_H_
