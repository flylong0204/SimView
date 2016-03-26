/**************************************************
outher: LJ
time: 2016-03-26
use: 地球管理接口，提供
from:
chanage:
change outher :
**************************************************/

#ifndef _OSGEARTHCONFIG_H_
#define _OSGEARTHCONFIG_H_

#pragma once

namespace SimView
{
	class COsgEarhConfig
	{
	public:
		// 构造函数
		explicit COsgEarhConfig(void);
		// 析构函数
		~COsgEarhConfig(void);

	protected:
		// 初始化
		void Init(void);
		// 读取地球文件
		void GetEarthNode(void);
	private:
		IConfigFileUtil* m_pIConfigFileUtil; // 配置文件操作类
	};
}


#endif // !_OSGEARTHCONFIG_H_