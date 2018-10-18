/*
 * Copyright (c) 2018 Jose Ruiz <jose.a.ruiz.dominguez.eu@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __INC_ICE40UP5K_MICRO5_BOARD_H
#define __INC_ICE40UP5K_MICRO5_BOARD_H

#include <soc.h>
#include <gpio.h>

/* SW2 switch block pin allocation. */
#define SW2_GPIO_PORT         "gpio0"
#define SW2_PIN0_GPIO_PIN     0
#define SW2_PIN1_GPIO_PIN     1
#define SW2_PIN2_GPIO_PIN     2
#define SW2_PIN3_GPIO_PIN     3

/* LEDS configuration. No LEDs on board but req'd by some samples. */
#define LED0_GPIO_PORT        "gpio0"
#define LED1_GPIO_PORT        "gpio0"
#define LED0_GPIO_PIN         8
#define LED1_GPIO_PIN         9

/* We'll use this to access 32-bit memory mapped registers. */
#define MICRO5_REG(a)           (*(volatile u32_t *)a)


/* UART block. */
#define UART_TXB                (CONFIG_UART_MICRO5_BASE + 0)
#define UART_RXB                (CONFIG_UART_MICRO5_BASE + 0)
#define UART_STATUS             (CONFIG_UART_MICRO5_BASE + 4)


/* Timer block. */
#define TIMER_COUNT             (CONFIG_MICRO5_TIMER_BASE + 0)



#endif /* __INC_ICE40UP5K_MICRO5_BOARD_H */
