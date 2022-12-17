#ifndef PARAMETERS_H
#define PARAMETERS_H

#include "ev3api.h"

/* センサーポートの定義 */
// カラーセンサーのポート番号
static const sensor_port_t color_sensor = EV3_PORT_2;
// 超音波センサーのポート番号
static const sensor_port_t ultrasonic_sensor = EV3_PORT_3;

/* モーターポートの定義 */
// 左モーターのポート番号
static const motor_port_t left_motor = EV3_PORT_C;
// 右モーターのポート番号
static const motor_port_t right_motor = EV3_PORT_B;
// アームモーターのポート番号
static const motor_port_t arm_motor = EV3_PORT_A;

#endif
