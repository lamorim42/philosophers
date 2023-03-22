# Philosophers

## Índice

1. [Utilizando Singleton](#utilizando-singleton)
2. [Read and write](#read-and-write)
3. [Funções permitidas](#funções-permitidas)

## Utilizando Singleton

### Definição

- Singleton é um design pattern de *'criação'*, o qual garante que uma `'classe'` tenha apenas **uma** `'instância'`, a qual tem um ponto de acesso global.

*Em outras palavras, podemos dizer que nossa 'estrutura' será criada ao começar o programa. Teremos acesso a essa estrutura de forma global e poderemos acessa-lá (read/write) durante todo o programa*

Para tal comportamento iremos utilizar a 'static'. Mas atenção, como estamos utilizando uma linguagem procedural para replicar um pattern de linguagens orientadas a objeto, não teremos uma implementação completamente fiel, porém funcional.

### Exemplo

```c

/* typedef struct s_input
{
	int				n_eat;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	n_philos;
	unsigned int	start;
	char			to_continue;
}	t_input; */

//input_instance.c

t_input	*input_instance(void)
{
	static t_input	__instance;

	return (&__instance);
}
```
*Exemplo retirado do arquivo [input_instance.c](./philo/app/src/input/input_instance.c)*

## Read and Write

Como criamos um espaço na memório, onde mapeamos esse espaço com uma struct e sempre devolvemos esse mesmo espaço na memória, podemos controlar o acesso a nossa instância.

### Exemplo

```c
// t_philo	**philo_instance(void)
// {
// 	static t_philo	*__instance;

// 	return (&__instance);
// }

void	main(void)
{
	t_philo	*write_philo;
	t_philo	*read_philo;

	write_philo = philo_instance();
	read_philo = *(philo_instance());
}

```

## Definindo 'Entidades'

- Um **philosopher** *(aka philo)* será uma 'entidade' que está em uma Jantar e usa um **fork** para comer. um *philo* executa as ações de comer, pensar e dormir.
- Um *philo* deve usar dois *forks* para comer
- o número de *forks* é igual ao de *philos*
- ao terminar de comer um *philo* libera ambos os *forks* e começa a dormir. Quando acordar volta a pensar novamente.
- o programa termina quando um *philo* morre.
- um *philo* **morre** se ele não conseguir comer em um tempo predeterminado.
- todo *philo* deve comer e não deveria morrer
	> a depender do tempo para morrer um *philo* pode morrer
- um *philo* não sabe que outro vai morrer
- um philo deve evitar morrer

## Requesitos do sistema

1. O programa deve receber os arqumentos:
	```
	./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
	```
	1. `number_of_philosophers`: Número de *philo* (também é o número de *forks*)
	2. `time_to_die`: tempo que cada *philo* tem para fazer um *'ciclo de atividade'*.
	3. `time_to_eat`: tempo que um *philo* para comer (para segurar dois *forks*)
	4. `time_to_sleep`: tempo que um *philo* tem para dormir (uma phorma de dar tempo de compartilhar os *forks*)
	5. `number_of_time_each_philosopher_must_eat`: Número de vezes que um *philo* come
	> Os tempos devem ser em milissegundos
2. Cada *philo* tem um **id** de 1 a *number_of_philosophers*
3. O philo de `id` 1 *senta* ao lado do philo `id` *number_of_philosophers*
	- O philo `N` fica entre os philos `N + 1` e `N - 1`
4. Devemos logar todas as ações de um philo
5. Os logs devem ter o padão:
	```
	timestamp_in_ms philo_id has taken a fork
	timestamp_in_ms philo_id is eating
	timestamp_in_ms philo_id is sleeping
	timestamp_in_ms philo_id is thinking
	timestamp_in_ms philo_id died
	```
	> tempo em milissegundo!
6. As mensagens não devem se misturar
7. A mensagem da morte de um philo não deve ser disparada mais de `10ms` apos a sua morte
8. O programa não deve ter [data races](https://en.wikipedia.org/wiki/Race_condition#Data_race)

## Detalhes técnicos

- cada philo deve ter um fork
- cada philo tem um fork a sua direita e um fork a sua esquerda
- 1 philo = 1 fork
- os forks devem ser protegidos com *mutex* um mutex para cada

### Funções permitidas

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
