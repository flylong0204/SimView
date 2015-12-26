#if SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_WIN32

#include <Windows.h>
#include <time.h>
#define EPOCHFILETIME 11644473600000000Ui64

#else

#include <unistd.h>
#include <sys/utime.h>
#define EPOCHFILETIME 11644473600000000ULL

#endif // SIMVIEW_PLATFORM

#include "../Public/Kerner/Kerner.h"
#include "GUID.h"

namespace SimView
{
	// 获得时间
	ulong_l GetTime(void);

	CGUID::CGUID(void)
	{
	}

	CGUID::~CGUID(void)
	{
	}

	// 生成guid
	long_l CGUID::Generate(void)
	{
		return (0);
	}

	// 获得时间
	ulong_l GetTime(void)
	{
#if SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_WIN32
		FILETIME filetime;
		ulong_l utime = 0;
		::GetSystemTimeAsFileTime(&filetime);
		utime |= filetime.dwLowDateTime;
		utime <<= 32;
		utime |= filetime.dwLowDateTime;
		utime /= 10;
		utime -= EPOCHFILETIME;
		return (utime / 1000);
#else
		struct timeval tv;
		gettimeofday(&tv, NULL);
		ulong_l utime = tv.tv_usec;
		utime /= 1000;
		utime += (tv.tv_sec * 1000);
		return (utime);

#endif
	}

}
