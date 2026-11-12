# SKILL.md

Guidance for working on the **CrossPlatformLibraries** repository.

This file describes the conventions, file layout, and coding style used across
this codebase so that any agent/editor can follow them consistently.

---

## 1. Language

- All documentation, comments, commit messages, and identifiers are written in
  **English**.
- Do not mix other natural languages into code comments or documentation.

---

## 2. Repository Layout

```
CrossPlatformLibraries/
├─ drivers/           Generic driver interfaces & hardware abstraction (cross-platform).
├─ modules/           Reusable higher-level software modules.
├─ utils/             Common helper functions & lightweight utilities.
└─ platforms/
   ├─ stm32f1/        STM32F1xx support.
   │  ├─ peripherals/ Peripheral drivers for this MCU.
   │  └─ ports/       Porting layer (implementation of `_port` interfaces).
   ├─ stm32f4/        STM32F4xx support (same sub-structure).
   └─ avr8/           Classic AVR (8-bit) support (same sub-structure).
```

- Cross-platform behaviour lives in `drivers/`, `modules/`, `utils/`.
- Everything that depends on a specific MCU lives under `platforms/<plat>/`.
- Keep each platform's sub-structure identical (peripherals + ports) so the
  three platforms stay easy to compare and port between.

---

## 3. File Naming

- **All file names are lowercase.** No uppercase letters.
- Use an `aj_` prefix for library files.
- Three common kinds of header appear together:

  | File name            | Purpose                                                    |
  |----------------------|------------------------------------------------------------|
  | `aj_<module>.h`      | Public interface: API declarations + inline implementations |
  | `aj_<module>_type.h` | Stand-alone header defining types/enums/constants for module |
  | `aj_<module>_port.h` | Platform-specific porting layer (registered `<plat>/ports`) |

  Examples: `aj_rcc.h`, `aj_buzzer.c`, `aj_bus_type.h`, `aj_buzzer_port.h`.

- Keep `_type.h` headers **independent**: they should not depend on the main
  module header, only on what they need (e.g. `<stdint.h>`, `stm32f1xx.h`).
- Source files use the same `aj_<module>.c` scheme.

---

## 4. Naming Conventions

### Functions
- Pattern: `AJ_<Module>_<Action>` — capital prefix `AJ_`, then a CamelCased
  module/qualifier, an underscore, then the action.
- Examples: `AJ_Buzzer_Start()`, `AJ_Bus_APB2_EnableClock()`,
  `AJ_GPIO_ConfigureDirection()`, `AJ_RCC_Init()`.
- Prefer a verb describing the action (`Enable`, `Disable`, `Get`, `Set`,
  `IsActive`, `TurnOn`, `Init`).

### Types (`typedef`)
- All lowercase, module-qualified, `_t` suffix.
- Pattern: `aj_<module>_<...>_t`.
- Examples: `aj_buzzer_t`, `aj_bus_apb2_clock_mask_t`, `aj_gpio_direction_t`.

### Enum fields / constants (macros)
- Constants and enum members use an `AJ_`-prefixed, SCREAMING-style name with
  descriptive components.
- Example: `AJ_BUS_AHB_CLOCK_DMA1`, `AJ_FLASH_LATENCY_0`, `AJ_BUZZER_ACTIVE`.

### Variables / struct fields
- Start with a lowercase letter; use camelCase for multi-word names.
- Examples: `buzzer_tick`, `system_tick`, `periphs`, `duration`.

---

## 5. Type Headers (`_type.h`) — Hardware-Specific Values

- When a value (bit mask, constant) exists only on some MCU models, guard it
  with the relevant CMSIS/SFR macro using `#if defined(...)`.
- Map library enums directly to the hardware `_Msk` values.
- Example pattern (STM32):

  ```c
  typedef enum {
      #if defined(RCC_APB2ENR_USART1EN_Msk)
          AJ_BUS_APB2_CLOCK_USART1 = RCC_APB2ENR_USART1EN_Msk,
      #endif
      AJ_BUS_APB2_CLOCK_ALL = 0xFFFFFFFFU
  } aj_bus_apb2_clock_mask_t;
  ```

- Use `U` (unsigned) literal suffixes on numeric values.
- Prefer an explicit `_ALL = 0xFFFFFFFFU` sentinel in mask enums.

---

## 6. Header Comment Pattern

Use the following structure at the top of the main module header:

```c
/**
 * @brief <one-line purpose of the module>.
 *
 * <short paragraph describing what it provides / how it is used>.
 *
 * @note  <important usage note, e.g. "under editing", or a prerequisite>
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 1: <Title>
 * -----------------------------------------------------------------------------
 * <description>, e.g. a list of source files to build.
 *
 * -----------------------------------------------------------------------------
 * REQUIREMENT 2: <Title>
 * -----------------------------------------------------------------------------
 * <description>, e.g. default macros are declared in ... 
 *
 * -----------------------------------------------------------------------------
 * EXAMPLE PROJECT
 * -----------------------------------------------------------------------------
 * @see    <Platform> example link:
 *         <paste full https link>
 *
 * -----------------------------------------------------------------------------
 * Source
 * -----------------------------------------------------------------------------
 * @author  AliReza Joodi
 * @see     https://github.com/AliRezaJoodi
 */
```

- The **full header block** (REQUIREMENT / EXAMPLE PROJECT / Source) is for the
  **main public headers** only.
- Internal headers (`_type.h`, `_port.h`) do **not** need this comment block —
  they start directly with the include guard.

### Include guard
- Pattern: `AJ_<MODULE>_INCLUDED` (or `AJ_<MODULE>_TYPE_INCLUDED` for type
  headers), and close with `#endif /* AJ_..._INCLUDED */`.
- Wrap the body in `extern "C" { ... }` for C++ compatibility.

---

## 7. Coding Style

- Use `static inline` for small, performance-sensitive function bodies placed in
  headers.
- Abstract register access through the utility layer (`aj_bit_reg.h`,
  `aj_gpio.h`) rather than touching raw registers in every driver.
- After enabling a clock, add a read-back sync write (`volatile uint32_t dummy =
  RCC->...; (void)dummy;`) where the hardware requires it.
- Mark work-in-progress headers with `@note ... under editing and will be
  completed gradually.`
- Avoid magic numbers: prefer named constants/enum fields.
- Do **not** add comments to code unless they clarify non-obvious behaviour.

---

## 8. Platform Porting Layer (`_port.h`)

- Lives under `platforms/<plat>/ports/`.
- Implements the platform-specific primitives the main driver needs
  (e.g. `AJ_Buzzer_InitPin()`, `AJ_Buzzer_WritePin()`).
- Keep the public names identical across platforms so the main driver can be
  shared unchanged; only the bodies differ.