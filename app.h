#ifdef __cplusplus
extern "C"
{
#endif

#include "ev3api.h"

/* タスク優先度の定義 */
// 通常タスクの優先度
#define MAIN_PRIORITY (TMIN_APP_TPRI + 1)
// 周期タスクの優先度
#define RUN_PRIORITY (TMIN_APP_TPRI + 2)

/* タスク周期の定義 */
// 周期タスクの周期時間
#define RUN_PERIOD (10 * 1000)

/* スタックサイズの定義 */
#ifndef STACK_SIZE
#define STACK_SIZE (4096)
#endif

/* タスクで実行する関数の定義 */
#ifndef TOPPERS_MACRO_ONLY
  extern void main_task(intptr_t exinf);
  extern void run_task(intptr_t exinf);
#endif

#ifdef __cplusplus
}
#endif
