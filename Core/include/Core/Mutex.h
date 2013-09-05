#include <Windows.h>

#define SKY_MUTEX CRITICAL_SECTION
#define SKY_MUTEX_INIT(m) InitializeCriticalSection(m)
#define SKY_MUTEX_LOCK(m) EnterCriticalSection(m)
#define SKY_MUTEX_UNLOCK(m) LeaveCriticalSection(m)
#define SKY_MUTEX_DESTROY(m) DeleteCriticalSection(m)