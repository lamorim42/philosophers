# Philosophers

## Índice

[Utilizando Singleton](#utilizando-singleton)
[Funções permitidas](#funções-permitidas)

## Utilizando Singleton



## Funções permitidas

| Função | Descrição | Retorno | Lib |
| ------ | --------- | ------- | --- |
| `void *memset(void *s, int c, size_t n)` | The `memset()` function fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c`. | returns a pointer to the memory area `s` | string.h |
| `int usleep(useconds_t usec)` | The  `usleep()` function suspends execution of the calling thread for (at least) `usec` microseconds. The sleep may be lengthened slightly by any system  activity or by the time spent processing the call or by the granularity of system timers. | returns `0` on success. On error, `-1` is returned, with errno set to indicate the cause of the error | unistd.h |
| `int gettimeofday(struct timeval *tv, struct timezone *tz)` | can get and set the time as well as a timezone ... | return `0` for success, or `-1` for failure (in which case errno is set appropriately) | sys/time.h |
| `int pthread_create(pthread_t *thread, const pthread_attr_t *attr void *(*start_routine) (void *), void *arg)` | The `pthread_create()` function starts a new thread in the calling process. The new thread starts execution by invoking start_routine(); arg is passed as the sole argument of start_routine() ... | On success returns `0`; on error, it returns an error number, and the contents of `*thread` are undefined. | pthread.h |
| `int pthread_detach(pthread_t thread)` | The `pthread_detach()` function marks the thread identified by thread as detached. When a detached thread terminates, its resources are automatically released back to the system without the need for another thread to join with the terminated thread. | On success returns `0`; on error, it returns an error number. | pthread.h |
| `int pthread_join(pthread_t thread, void **retval)` | The pthread_join() function waits for the thread specified by thread to terminate. If that thread has already terminated, then pthread_join() returns  immediately. The thread specified by thread must be joinable. If retval is not NULL, then pthread_join() copies the exit status of the target thread (i.e., the value that the target thread supplied to pthread_exit(3)) into the location pointed to by retval. If the target thread was canceled, then PTHREAD_CANCELED is placed in the location pointed to by retval. If multiple threads simultaneously try to join with the same thread, the results are undefined. If the thread calling pthread_join() is canceled, then the target thread will remain joinable (i.e., it will not be detached). | On success returns `0`; on error, it returns an error number. | pthread.h |
| `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)` | The pthread_mutex_init() function initialises the mutex referenced by mutex with attributes specified by attr. If attr is NULL, the default mutex attributes are used; the effect is the same as passing the address of a default mutex attributes object. Upon successful initialisation, the state of the mutex becomes initialised and unlocked. | On success returns `0`; on error, it returns an error number. | pthread.h |
| `int pthread_mutex_destroy(pthread_mutex_t *mutex)` | The pthread_mutex_destroy() function destroys the mutex object referenced by mutex; the mutex object becomes, in effect, uninitialised. An implementation may cause pthread_mutex_destroy() to set the object referenced by mutex to an invalid value. A destroyed mutex object can be re-initialised using pthread_mutex_init(); the results of otherwise referencing the object after it has been destroyed are undefined. | On success returns `0`; on error, it returns an error number. |pthread.h |
| `int pthread_mutex_lock(pthread_mutex_t *mutex)` | The mutex object referenced by mutex is locked by calling pthread_mutex_lock(). If the mutex is already locked, the calling thread blocks until the mutex becomes available. This operation returns with the mutex object referenced by mutex in the locked state with the calling thread as its owner ... | On success returns `0`; on error, it returns an error number. | pthread.h |
| `int pthread_mutex_unlock(pthread_mutex_t *mutex)` | The pthread_mutex_unlock() function releases the mutex object referenced by mutex. The manner in which a mutex is released is dependent upon the mutex's type attribute. If there are threads blocked on the mutex object referenced by mutex when pthread_mutex_unlock() is called, resulting in the mutex becoming available, the scheduling policy is used to determine which thread shall acquire the mutex ... | On success returns `0`; on error, it returns an error number. |pthread.h |
