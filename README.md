# Cross-Platform Libraries
A collection of reusable, cross-platform C libraries for embedded systems.

This repository is designed to keep **hardware-independent logic**, **device drivers**, and **platform-specific code** cleanly separated, making it easy to reuse libraries across different microcontrollers such as AVR, STM32, ESP32, and others.

This repository contains **libraries only**. Examples and application projects are kept in separate repositories.

## Folder Structure

### Utils
General-purpose headers and utilities shared across all platforms.  
Examples:
- Bit manipulation macros
- Math helpers
- Compile-time utilities
- Common definitions

Note: These files must be **platform-independent**.

### Drivers
Device-specific drivers (external ICs, sensors, peripherals).  
Examples:
- ADCs, DACs
- Sensors
- Communication chips

Note: Drivers contain core logic and rely on platform-specific code provided by `Platforms`.

### Modules
Pure software modules and algorithms with no hardware dependency.  
Examples:
- PID controllers
- Filters and averaging
- State machines
- Protocol logic

Note: Modules are fully reusable across all platforms.

### Platforms
Platform and MCU-specific implementations.  
Examples:
- GPIO, SPI, UART access
- Pin mapping
- Timing and low-level hardware control

Note: Each platform provides the required interface for drivers to work on that MCU.
