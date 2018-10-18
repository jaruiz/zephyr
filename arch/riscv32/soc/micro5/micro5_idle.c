/*
 * Copyright (c) 2018 Jose Ruiz <jose.a.ruiz.dominguez.eu@gmail.com>
 * (Derived from the Pulpino version by Jean-Paul Etienne)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <toolchain.h>
#include <irq.h>
#include <soc.h>

#include <tracing.h>

static ALWAYS_INLINE void micro5_idle(unsigned int key)
{
	z_sys_trace_idle();

	/* unlock interrupts */
	irq_unlock(key);

	__asm__ volatile (".word 0x0000300b;");

	/* Wait for interrupt */
	__asm__ volatile ("wfi");
}

void k_cpu_idle(void)
{
	micro5_idle(SOC_MSTATUS_IEN);
}

void k_cpu_atomic_idle(unsigned int key)
{
	micro5_idle(key);
}
