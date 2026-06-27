# Cross-Platform Libraries
A collection of reusable, cross-platform C libraries for embedded systems.<br>

## Folder Overview
- **utils** — Common helper functions and lightweight utility components.
- **modules** — Reusable software modules and higher-level building blocks.
- **drivers** — Generic driver interfaces and hardware abstraction code.
- **platforms** — Platform-specific implementations and ports.
  - `avr8` — Platform support for Classic AVR (8-bit) MCUs.
    - `peripherals` — Peripheral drivers.
    - `ports` — Porting layer.
  - `stm32f1` — Platform support for STM32F1xx MCUs.
    - `peripherals` — Peripheral drivers.
    - `ports` — Porting layer.
  - `stm32f4` — Platform support for STM32F4xx MCUs.
    - `peripherals` — Peripheral drivers.
    - `ports` — Porting layer.

## Include Paths
Add the required directories to your project's include paths.<br>
The examples below assume that `CrossPlatformLibraries` is located a few levels above the project directory.<br>

### Common Paths
The following paths are examples.
- `..\..\..\CrossPlatformLibraries\utils`
- `..\..\..\CrossPlatformLibraries\modules`
- `..\..\..\CrossPlatformLibraries\drivers`
- `..\..\..\CrossPlatformLibraries\platforms\common`

### STM32F1xx Paths
The following paths are examples.
- `..\..\..\CrossPlatformLibraries\platforms\stm32f1\ports`
- `..\..\..\CrossPlatformLibraries\platforms\stm32f1\peripherals`

### STM32F4xx Paths
The following paths are examples.
- `..\..\..\CrossPlatformLibraries\platforms\stm32f4\ports`
- `..\..\..\CrossPlatformLibraries\platforms\stm32f4\peripherals`

### AVR8 Paths
The following paths are examples.
- `..\..\..\CrossPlatformLibraries\platforms\avr8\ports`
- `..\..\..\CrossPlatformLibraries\platforms\avr8\peripherals`

Notes
- Adjust the number of `..` levels depending on your workspace layout.
- Keep project paths relative so the repository remains portable.
- Add only the folders required by each target project.
- Use platform-specific paths only when the project depends on that platform.


