//*****************************************************************************
//
//! @file button.c
//!
//! @brief Utility for reading EVB Buttons.
//!
//! Purpose: Reading EVB buttons
//!
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************

#include "am_bsp.h"
#include "am_mcu_apollo.h"
#include "am_util.h"
#include "ns_core.h"
#include "ns_peripherals_button.h"

const ns_core_api_t ns_button_V0_0_1 = {.apiId = NS_BUTTON_API_ID, .version = NS_BUTTON_V0_0_1};

const ns_core_api_t ns_button_V1_0_0 = {.apiId = NS_BUTTON_API_ID, .version = NS_BUTTON_V1_0_0};

const ns_core_api_t ns_button_oldest_supported_version = {.apiId = NS_BUTTON_API_ID,
                                                          .version = NS_BUTTON_V0_0_1};

const ns_core_api_t ns_button_current_version = {.apiId = NS_BUTTON_API_ID,
                                                 .version = NS_BUTTON_V1_0_0};

int volatile *g_ns_peripheral_button0;
int volatile *g_ns_peripheral_button1;

/**
 * @brief GPIO Button0 ISR handler
 *
 */
void
am_gpio0_001f_isr(void) {
    uint32_t ui32IntStatus;

    //
    // Delay for button debounce.
    //
    am_hal_delay_us(40000);

    //
    // Clear the GPIO Interrupt (write to clear).
    //
    AM_CRITICAL_BEGIN
    am_hal_gpio_interrupt_irq_status_get(GPIO0_001F_IRQn, true, &ui32IntStatus);
    am_hal_gpio_interrupt_irq_clear(GPIO0_001F_IRQn, ui32IntStatus);
    AM_CRITICAL_END

    *g_ns_peripheral_button0 = 1;
}

/**
 * @brief GPIO Button1 ISR handler
 *
 */
void
am_gpio1_001f_isr(void) {
    uint32_t ui32IntStatus;

    //
    // Delay for button debounce.
    //
    am_hal_delay_us(20000);

    //
    // Clear the GPIO Interrupt (write to clear).
    //
    AM_CRITICAL_BEGIN
    am_hal_gpio_interrupt_irq_status_get(GPIO1_001F_IRQn, true, &ui32IntStatus);
    am_hal_gpio_interrupt_irq_clear(GPIO1_001F_IRQn, ui32IntStatus);
    AM_CRITICAL_END

    *g_ns_peripheral_button1 = 1;
}
uint32_t
ns_peripheral_button_init(ns_button_config_t *cfg) {
    uint32_t ui32IntStatus;
    uint32_t ui32BUTTON0GpioNum = AM_BSP_GPIO_BUTTON0;
    uint32_t ui32BUTTON1GpioNum = AM_BSP_GPIO_BUTTON1;

#ifndef NS_DISABLE_API_VALIDATION
    if (cfg == NULL) {
        return NS_STATUS_INVALID_HANDLE;
    }

    if (ns_core_check_api(cfg->api, &ns_button_oldest_supported_version,
                          &ns_button_current_version)) {
        return NS_STATUS_INVALID_VERSION;
    }
#endif

    //
    // Configure the button pin.
    //
    if (cfg->button_0_enable) {
        am_hal_gpio_pinconfig(AM_BSP_GPIO_BUTTON0, g_AM_BSP_GPIO_BUTTON0);
        g_ns_peripheral_button0 = cfg->button_0_flag;
        //
        // Clear the GPIO Interrupt (write to clear).
        //
        AM_CRITICAL_BEGIN
        am_hal_gpio_interrupt_irq_status_get(GPIO0_001F_IRQn, false, &ui32IntStatus);
        am_hal_gpio_interrupt_irq_clear(GPIO0_001F_IRQn, ui32IntStatus);
        AM_CRITICAL_END

        //
        // Enable the GPIO/button interrupt.
        //
        am_hal_gpio_interrupt_control(AM_HAL_GPIO_INT_CHANNEL_0, AM_HAL_GPIO_INT_CTRL_INDV_ENABLE,
                                      (void *)&ui32BUTTON0GpioNum);

        NVIC_SetPriority(GPIO0_001F_IRQn, AM_IRQ_PRIORITY_DEFAULT);
        NVIC_EnableIRQ(GPIO0_001F_IRQn);
    }

    if (cfg->button_1_enable) {
        am_hal_gpio_pinconfig(AM_BSP_GPIO_BUTTON1, g_AM_BSP_GPIO_BUTTON1);
        g_ns_peripheral_button1 = cfg->button_1_flag;

        //
        // Clear the GPIO Interrupt (write to clear).
        //
        AM_CRITICAL_BEGIN
        am_hal_gpio_interrupt_irq_status_get(GPIO1_001F_IRQn, false, &ui32IntStatus);
        am_hal_gpio_interrupt_irq_clear(GPIO1_001F_IRQn, ui32IntStatus);
        AM_CRITICAL_END

        //
        // Enable the GPIO/button interrupt.
        //
        am_hal_gpio_interrupt_control(AM_HAL_GPIO_INT_CHANNEL_1, AM_HAL_GPIO_INT_CTRL_INDV_ENABLE,
                                      (void *)&ui32BUTTON1GpioNum);

        NVIC_SetPriority(GPIO1_001F_IRQn, AM_IRQ_PRIORITY_DEFAULT);
        NVIC_EnableIRQ(GPIO1_001F_IRQn);
    }

    am_hal_interrupt_master_enable();
    return NS_STATUS_SUCCESS;
}
