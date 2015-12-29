/**************************************************
 outher: LJ
 time: 2015-10-23
 use: 用到的线程依赖的头文件
 from: org 
 chanage:
 change outher
 **************************************************/

#ifndef _PUBLIC_THREADDEPEND_H_
#define _PUBLIC_THREADDEPEND_H_

#include <boost/thread/tss.hpp>
#include <boost/thread/recursive_mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/shared_mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/bind.hpp>

#define SIMVIEW_AUTO_MUTEX_NAME mutex
#define SIMVIEW_AUTO_MUTEX mutable boost::recursive_mutex SIMVIEW_AUTO_MUTEX_NAME;
#define SIMVIEW_LOCK_AUTO_METEX boost::recursive_mutex::scoped_lock autoMutexLock(SIMVIEW_AUTO_MUTEX_NAME);
#define SIMVIEW_MUTEX(name) mutable boost::recursive_mutex name;
#define SIMVIEW_STATIC_MUTEX(name) static boost::recursive_mutex name;
#define SIMVIEW_STATIC_MUTEX_INSTANCE(name) boost::recursive_mutex name;
#define SIMVIEW_LOCK_MUTEX(name) boost::recursive_mutex::scoped_lock SIMVIEWnameLock(name);
#define SIMVIEW_LOCK_MUTEX_NAMED(mutexName, lockName) boost::recursive_mutex::scoped_lock lockName(mutexName);
// like SIMVIEW_AUTO_MUTEX but mutex held by pointer
#define SIMVIEW_AUTO_SHARED_MUTEX mutable boost::recursive_mutex *SIMVIEW_AUTO_MUTEX_NAME;
#define SIMVIEW_LOCK_AUTO_SHARED_MUTEX assert(SIMVIEW_AUTO_MUTEX_NAME); boost::recursive_mutex::scoped_lock autoMutexLock(*SIMVIEW_AUTO_MUTEX_NAME);
#define SIMVIEW_NEW_AUTO_SHARED_MUTEX assert(!SIMVIEW_AUTO_MUTEX_NAME); SIMVIEW_AUTO_MUTEX_NAME = new boost::recursive_mutex();
#define SIMVIEW_DELETE_AUTO_SHARED_MUTEX assert(SIMVIEW_AUTO_MUTEX_NAME); delete SIMVIEW_AUTO_MUTEX_NAME;
#define SIMVIEW_COPY_AUTO_SHARED_MUTEX(from) assert(!SIMVIEW_AUTO_MUTEX_NAME); SIMVIEW_AUTO_MUTEX_NAME = from;
#define SIMVIEW_SET_AUTO_SHARED_MUTEX_NULL SIMVIEW_AUTO_MUTEX_NAME = 0;
#define SIMVIEW_MUTEX_CONDITIONAL(mutex) if (mutex)
#define SIMVIEW_THREAD_SYNCHRONISER(sync) boost::condition sync;
#define SIMVIEW_THREAD_WAIT(sync, mutex, lock) sync.wait(lock);
#define SIMVIEW_THREAD_NOTIFY_ONE(sync) sync.notify_one();
#define SIMVIEW_THREAD_NOTIFY_ALL(sync) sync.notify_all();
// Read-write mutex
#define SIMVIEW_RW_MUTEX(name) mutable boost::shared_mutex name;
#define SIMVIEW_LOCK_RW_MUTEX_READ(name) boost::shared_lock<boost::shared_mutex> nameLock(name)
#define SIMVIEW_LOCK_RW_MUTEX_WRITE(name) boost::unique_lock<boost::shared_mutex> nameLock(name)
// Thread-local pointer
#define SIMVIEW_THREAD_POINTER(T, var) boost::thread_specific_ptr<T> var
#define SIMVIEW_THREAD_POINTER_INIT(var) var(&deletePtr)
#define SIMVIEW_THREAD_POINTER_VAR(T, var) boost::thread_specific_ptr<T> var (&deletePtr<T>)
#define SIMVIEW_THREAD_POINTER_SET(var, expr) var.reset(expr)
#define SIMVIEW_THREAD_POINTER_GET(var) var.get()
#define SIMVIEW_THREAD_POINTER_DELETE(var) var.reset(0)
// Thread objects and related functions
#define SIMVIEW_THREAD_TYPE boost::thread
// #define SIMVIEW_THREAD_CREATE(name, worker) boost::thread* name = new(boost::thread, MEMCATEGORY_GENERAL)(worker);
// #define SIMVIEW_THREAD_DESTROY(name) SIMVIEW_DELETE_T(name, thread, MEMCATEGORY_GENERAL)
#define SIMVIEW_THREAD_HARDWARE_CONCURRENCY boost::thread::hardware_concurrency()
#define SIMVIEW_THREAD_CURRENT_ID boost::this_thread::get_id()
#define SIMVIEW_THREAD_WORKER_INHERIT
// Utility
#define SIMVIEW_THREAD_SLEEP(ms) boost::this_thread::sleep(boost::posix_time::millisec(ms));



#endif