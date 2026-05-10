# Cross-Platform Libraries
A collection of reusable, cross-platform C libraries for embedded systems.<br>

## Folder Overview
- **utils** — Common helper functions and lightweight utility components.
- **modules** — Reusable software modules and higher-level building blocks.
- **drivers** — Generic driver interfaces and hardware abstraction code.
- **platforms** — Platform-specific implementations and ports.
  - `avr8` — Classic AVR (8-bit) microcontroller platform support.
    - `ports` — AVR8-specific porting layer.
    - `peripherals` — AVR8-specific peripheral interfaces.

## Include Paths
Add the required directories to your project's include paths.<br>
The examples below assume that `CrossPlatformLibraries` is located a few levels above the project directory.<br>
Adjust the number of `..` levels depending on your workspace layout.<br>

### Common Paths
The following paths are examples. Adjust the number of `..` levels depending on your workspace layout.<br>
`..\..\..\CrossPlatformLibraries\utils`<br>
`..\..\..\CrossPlatformLibraries\modules`<br>
`..\..\..\CrossPlatformLibraries\drivers`<br>

## AVR8 Paths
The following paths are examples. Adjust the number of `..` levels depending on your workspace layout.<br>
`..\..\..\CrossPlatformLibraries\platforms\avr8\ports`<br>
`..\..\..\CrossPlatformLibraries\platforms\avr8\peripherals`<br>

Notes
- Keep project paths relative so the repository remains portable.
- Add only the folders required by each target project.
- Use platform-specific paths only when the project depends on that platform.


