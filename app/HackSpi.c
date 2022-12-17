#include "HackSpi.h"
#include "Starter.h"
#include "parameters.h"

// HackSpiクラスの状態一覧
typedef enum
{
  UNDEFINED,
  STARTING,
  RUNNING
} state_t;

// HackSpiクラスの状態
static state_t state = UNDEFINED;

static void hackspi_exec_undefined();
static void hackspi_exec_starting();
static void hackspi_exec_running();

/**
 * コンストラクター
 */
void hackspi_init()
{
  starter_init();
}

/**
 * ロボットを実行する
 */
void hackspi_run()
{
  switch (state)
  {
  case UNDEFINED:
    hackspi_exec_undefined();
    break;
  case STARTING:
    hackspi_exec_starting();
    break;
  case RUNNING:
    hackspi_exec_running();
    break;
  }
}

/**
 * UNDEFINED状態に実行する関数
 */
static void hackspi_exec_undefined()
{
  state = STARTING;
}

/**
 * STARTING状態に実行する関数
 */
static void hackspi_exec_starting()
{
  if (starter_is_pressed())
  {
    state = RUNNING;
  }
}

/**
 * RUNNING状態に実行する関数
 */
static void hackspi_exec_running()
{
  // 左モーターにパワーを設定する（モーターを回転させる）
  ev3_motor_set_power(left_motor, 100);
  // 右モーターにパワーを設定する（モーターを回転させる）
  ev3_motor_set_power(right_motor, 40);
}
