# ETロボコンのRasPike用のテンプレート

ETロボコンで使用するRasPike用のテンプレートファイルです。

## 設計

### クラス図

```mermaid
classDiagram
  HackSpi "1" --> "1" Starter
  HackSpi "1" --> "1" Motor
  HackSpi -- state_t

  class state_t {
    <<enum>>
    UNDEFINED
    STARTING
    RUNNING
  }
  class HackSpi {
    - state_t state
    + hackspi_init() void
    + hackspi_run() void
    - hackspi_exec_undefined() void
    - hackspi_exec_starting() void
    - hackspi_exec_running() void
  }
  class Starter {
    + starter_init() void
    + starter_is_pressed() bool_t
  }
  class Motor {
  }
```

### ステートマシン図

```mermaid
stateDiagram-v2
  [*] --> STARTING
  STARTING --> RUNNING: Start button is pressed
```

### シーケンス図

```mermaid
sequenceDiagram
  rect rgb(150,150,100)
  TASK->>HackSpi: hackspi_init()
  HackSpi->>Starter: starter_init()
  end

  rect rgb(100,100,150)
  TASK->>HackSpi: hackspi_run()
  HackSpi->>Starter: starter_is_pressed()
  Starter-->>HackSpi: is pressed
  HackSpi->>(LeftMotor) Motor: ev3_motor_set_power(port, power)
  HackSpi->>(RightMotor) Motor: ev3_motor_set_power(port, power)
  end
```
