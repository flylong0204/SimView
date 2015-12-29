/**********************************************/
/*autor£∫ LJ				                  */
/*time: 2015-10-18		                      */
/*use:	Load the library	                  */
/*use:	¿¥‘¥SIMVIEW	                          */
/**********************************************/

#ifndef _PUBLIC_PLATFORM_H_
#define _PUBLIC_PLATFORM_H_

namespace SimView
{
#define SIMVIEW_PLATFORM_WIN32 1
#define SIMVIEW_PLATFORM_LINUX 2
#define SIMVIEW_PLATFORM_APPLE 3
#define SIMVIEW_PLATFORM_APPLE_IOS 4
#define SIMVIEW_PLATFORM_ANDROID 5
#define SIMVIEW_PLATFORM_NACL 6

#define SIMVIEW_COMPILER_MSVC 1
#define SIMVIEW_COMPILER_GNUC 2
#define SIMVIEW_COMPILER_BORL 3
#define SIMVIEW_COMPILER_WINSCW 4
#define SIMVIEW_COMPILER_GCCE 5
#define SIMVIEW_COMPILER_CLANG 6

#define SIMVIEW_ENDIAN_LITTLE 1
#define SIMVIEW_ENDIAN_BIG 2

#define SIMVIEW_ARCHITECTURE_32 1
#define SIMVIEW_ARCHITECTURE_64 2

// ±‡“Î∆˜
#if defined( __GCCE__ )
#   define SIMVIEW_COMPILER SIMVIEW_COMPILER_GCCE
#   define SIMVIEW_COMP_VER _MSC_VER
	//# include <staticlibinit_gcce.h> // This is a GCCE toolchain workaround needed when compiling with GCCE
#elif defined( __WINSCW__ )
#   define SIMVIEW_COMPILER SIMVIEW_COMPILER_WINSCW
#   define SIMVIEW_COMP_VER _MSC_VER
#elif defined( _MSC_VER )
#   define SIMVIEW_COMPILER SIMVIEW_COMPILER_MSVC
#   define SIMVIEW_COMP_VER _MSC_VER
#elif defined( __clang__ )
#   define SIMVIEW_COMPILER SIMVIEW_COMPILER_CLANG
#   define SIMVIEW_COMP_VER (((__clang_major__)*100) + \
	(__clang_minor__ * 10) + \
	__clang_patchlevel__)
#elif defined( __GNUC__ )
#   define SIMVIEW_COMPILER SIMVIEW_COMPILER_GNUC
#   define SIMVIEW_COMP_VER (((__GNUC__)*100) + \
	(__GNUC_MINOR__ * 10) + \
	__GNUC_PATCHLEVEL__)
#elif defined( __BORLANDC__ )
#   define SIMVIEW_COMPILER SIMVIEW_COMPILER_BORL
#   define SIMVIEW_COMP_VER __BCPLUSPLUS__
#   define __FUNCTION__ __FUNC__
#else
#   pragma error "No known compiler. Abort! Abort!"

#endif

	/* See if we can use __forceinline or if we need to use __inline instead */
#if SIMVIEW_COMPILER == SIMVIEW_COMPILER_MSVC
#   if SIMVIEW_COMP_VER >= 1200
#       define FORCEINLINE __forceinline
#   endif
#elif defined(__MINGW32__)
#   if !defined(FORCEINLINE)
#       define FORCEINLINE __inline
#   endif
#else
#   define FORCEINLINE __inline
#endif

	/* Finds the current platform */

#if defined( __WIN32__ ) || defined( _WIN32 )
#   define SIMVIEW_PLATFORM SIMVIEW_PLATFORM_WIN32
#elif defined( __APPLE_CC__)
	// Device                                                     Simulator
	// Both requiring OS version 4.0 or greater
#   if __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= 40000 || __IPHONE_OS_VERSION_MIN_REQUIRED >= 40000
#       define SIMVIEW_PLATFORM SIMVIEW_PLATFORM_APPLE_IOS
#   else
#       define SIMVIEW_PLATFORM SIMVIEW_PLATFORM_APPLE
#   endif
#elif defined(__ANDROID__)
#   define SIMVIEW_PLATFORM SIMVIEW_PLATFORM_ANDROID
#elif defined( __native_client__ )
#   define SIMVIEW_PLATFORM SIMVIEW_PLATFORM_NACL
#   ifndef SIMVIEW_STATIC_LIB
#       error SIMVIEW must be built as static for NaCl (SIMVIEW_STATIC=true in CMake)
#   endif
#   ifdef SIMVIEW_BUILD_RENDERSYSTEM_D3D9
#       error D3D9 is not supported on NaCl (SIMVIEW_BUILD_RENDERSYSTEM_D3D9 false in CMake)
#   endif
#   ifdef SIMVIEW_BUILD_RENDERSYSTEM_GL
#       error OpenGL is not supported on NaCl (SIMVIEW_BUILD_RENDERSYSTEM_GL=false in CMake)
#   endif
#   ifndef SIMVIEW_BUILD_RENDERSYSTEM_GLES2
#       error GLES2 render system is required for NaCl (SIMVIEW_BUILD_RENDERSYSTEM_GLES2=false in CMake)
#   endif
#else
#   define SIMVIEW_PLATFORM SIMVIEW_PLATFORM_LINUX
#endif

	/* Find the arch type */
#if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) || defined(__ia64__) || defined(__s390__) || defined(__s390x__)
#   define SIMVIEW_ARCH_TYPE SIMVIEW_ARCHITECTURE_64
#else
#   define SIMVIEW_ARCH_TYPE SIMVIEW_ARCHITECTURE_32
#endif

	// For generating compiler warnings - should work on any compiler
	// As a side note, if you start your message with 'Warning: ', the MSVC
	// IDE actually does catch a warning :)
#define SIMVIEW_QUOTE_INPLACE(x) # x
#define SIMVIEW_QUOTE(x) SIMVIEW_QUOTE_INPLACE(x)
#define SIMVIEW_WARN( x )  message( __FILE__ "(" QUOTE( __LINE__ ) ") : " x "\n" )

	//----------------------------------------------------------------------------
	// Windows Settings
#if SIMVIEW_PLATFORM == SIMVIEW_PLATFORM_WIN32

	// If we're not including this from a client build, specify that the stuff
	// should get exported. Otherwise, import it.
#   if defined( SIMVIEW_STATIC_LIB )
	// Linux compilers don't have symbol import/export directives.
#       define _SVExport
#       define _SVPrivate
#   else
#       if defined( SIMVIEW_NONCLIENT_BUILD )
#           define _SVExport __declspec( dllexport )
#       else
#           if defined( __MINGW32__ )
#               define _SVExport
#           else
#               define _SVExport __declspec( dllimport )
#           endif
#       endif
#       define _SVPrivate
#   endif
	// Win32 compilers use _DEBUG for specifying debug builds.
	// for MinGW, we set DEBUG
#if defined(_DEBUG) || defined(DEBUG)
#       define SIMVIEW_DEBUG_MODE 1
#else
#       define SIMVIEW_DEBUG_MODE 0
#endif

	// Disable unicode support on MingW for GCC 3, poorly supported in stdlibc++
	// STLPORT fixes this though so allow if found
	// MinGW C++ Toolkit supports unicode and sets the define __MINGW32_TOOLBOX_UNICODE__ in _mingw.h
	// GCC 4 is also fine
#if defined(__MINGW32__)
# if SIMVIEW_COMP_VER < 400
#  if !defined(_STLPORT_VERSION)
#   include<_mingw.h>
#   if defined(__MINGW32_TOOLBOX_UNICODE__) || SIMVIEW_COMP_VER > 345
#    define SIMVIEW_UNICODE_SUPPORT 1
#   else
#    define SIMVIEW_UNICODE_SUPPORT 0
#   endif
#  else
#   define SIMVIEW_UNICODE_SUPPORT 1
#  endif
# else
#  define SIMVIEW_UNICODE_SUPPORT 1
# endif
#else
#  define SIMVIEW_UNICODE_SUPPORT 1
#endif


}

#endif // _PUBLIC_PLATFORM_H_
#endif // _PUBLIC_PLATFORM_H_