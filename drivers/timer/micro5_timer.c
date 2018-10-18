/*
 * Copyright (c) 2018 Jose Ruiz <jose.a.ruiz.dominguez.eu@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel.h>
#include <arch/cpu.h>
#include <device.h>
#include <system_timer.h>
#include <board.h>


static ALWAYS_INLINE void micro5_rearm_timer(void)
{
	/* Micro5's is a free running timer that rearms automatically. */
	/* Nothing to do here and nothing to control in the timer. */
}

static void micro5_timer_irq_handler(void *unused)
{
	ARG_UNUSED(unused);
#ifdef CONFIG_EXECUTION_BENCHMARKING
	extern void read_timer_start_of_tick_handler(void);
	read_timer_start_of_tick_handler();
#endif

	_sys_clock_tick_announce();

	micro5_rearm_timer();

#ifdef CONFIG_EXECUTION_BENCHMARKING
	extern void read_timer_end_of_tick_handler(void);
	read_timer_end_of_tick_handler();
#endif
}

#ifdef CONFIG_TICKLESS_IDLE
#error "Tickless idle not implemented for micro5 timer"
#endif

int _sys_clock_driver_init(struct device *device)
{
	ARG_UNUSED(device);

	IRQ_CONNECT(CONFIG_MICRO5_TIMER_IRQ,
		0, micro5_timer_irq_handler, NULL, 0);

	/* Initialize timer, just call micro5_rearm_timer. */
	micro5_rearm_timer();

	return 0;
}


u32_t _timer_cycle_get_32(void)
{
	return MICRO5_REG(TIMER_COUNT);
}
