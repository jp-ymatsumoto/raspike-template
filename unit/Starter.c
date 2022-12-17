#include "Starter.h"

/**
 * コンストラクター
 */
void starter_init()
{
}

/**
 * スタートボタンの押下状態を取得する
 * @return 押下状態
 */
bool_t starter_is_pressed()
{
  // 中央ボタンの押下状態を取得する
  return ev3_button_is_pressed(ENTER_BUTTON);
}
