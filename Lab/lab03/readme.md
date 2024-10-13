# lab03  

这次实验引入了互斥锁这一概念，有几个api和数据结构需要介绍：  

```c   
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[__SIZEOF_PTHREAD_MUTEX_T];
  long int __align;
} pthread_mutex_t;//  互斥锁，可通过下面这样来初始化
//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int pthread_mutex_lock (pthread_mutex_t *__mutex)  // 尝试获取锁并上锁，获取不到锁的话该线程就阻塞

int pthread_mutex_unlock (pthread_mutex_t *__mutex)  // 释放锁
```  

## 实验一 模拟售票员卖票  


