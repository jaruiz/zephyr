/*
 * Copyright (c) 2018 Jose Ruiz <jose.a.ruiz.dominguez.eu@gmail.com>
 * (Derived from the Pulpino version by Jean-Paul Etienne)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief pulpino interrupt management code
 */
#include <irq.h>
#include <soc.h>

void _arch_irq_enable(unsigned int irq)
{
	unsigned int key;

	key = irq_lock();
	/* FIXME interrupt controller is a dummy */
	irq_unlock(key);
};

void _arch_irq_disable(unsigned int irq)
{
	unsigned int key;

	key = irq_lock();
	/* FIXME interrupt controller is a dummy */
	irq_unlock(key);
};

int _arch_irq_is_enabled(unsigned int irq)
{
	/* FIXME interrupt controller is a dummy */
	return 1;
}

#if defined(CONFIG_RISCV_SOC_INTERRUPT_INIT)
void soc_interrupt_init(void)
{
	/* ensure that all interrupts are disabled */
	/* FIXME interrupt controller is a dummy */
	(void)irq_lock();
}
#endif
