#include "app.h"
#include <stdio.h>
#include "HackSpi.h"
#include "parameters.h"

void main_task(intptr_t exinf)
{
  // カラーセンサーの入力ポートを設定する
  ev3_sensor_config(color_sensor, COLOR_SENSOR);
  // 超音波センサーの入力ポートを設定する
  ev3_sensor_config(ultrasonic_sensor, ULTRASONIC_SENSOR);

  // 左モーターの出力ポートを設定する
  ev3_motor_config(left_motor, MEDIUM_MOTOR);
  // 右モーターの出力ポートを設定する
  ev3_motor_config(right_motor, MEDIUM_MOTOR);
  // アームモーターの出力ポートを設定する
  ev3_motor_config(arm_motor, LARGE_MOTOR);

  // HackSpiを初期化する
  hackspi_init();

  // 一定時間待機する
  tslp_tsk(100 * 1000U);

  printf("\n\n\nSTART\n\n\n");

  // 周期タスクを開始する
  sta_cyc(RUN_TASK_CYC);

  // メインタスクを待機状態にする
  slp_tsk();

  // 周期タスクを停止する
  stp_cyc(RUN_TASK_CYC);

  printf("\n\n\nEND\n\n\n");

  // タスクを終了する
  ext_tsk();
}

void run_task(intptr_t exinf)
{
  if (ev3_button_is_pressed(RIGHT_BUTTON))
  {
    // 左モーターを停止する
    ev3_motor_stop(left_motor, true);
    // 右モーターを停止する
    ev3_motor_stop(right_motor, true);

    // 通常タスクの待機状態を解除する
    wup_tsk(MAIN_TASK);
  }
  else
  {
    // HackSpiを実行する
    hackspi_run();
  }

  // タスクを終了する
  ext_tsk();
}
