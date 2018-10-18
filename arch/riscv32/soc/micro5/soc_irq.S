/*
 * Copyright (c) 2018 Jose Ruiz <jose.a.ruiz.dominguez.eu@gmail.com>
 * (Derived from the Pulpino version by Jean-Paul Etienne)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <kernel_structs.h>
#include <offsets.h>
#include <toolchain.h>
#include <linker/sections.h>
#include <soc.h>

/* exports */
GTEXT(__soc_save_context)
GTEXT(__soc_restore_context)
GTEXT(__soc_is_irq)
GTEXT(__soc_handle_irq)
GTEXT(__soc_irq_unlock)

/* Use ABI name of registers for the sake of simplicity */

/*
 * No context to save here.
 */
SECTION_FUNC(exception.other, __soc_save_context)
	/* Return */
	jalr x0, ra


SECTION_FUNC(exception.other, __soc_restore_context)
	/* Return */
	jalr x0, ra


/*
 * SOC-specific function to handle pending IRQ number generating the interrupt.
 *
 * Exception number is given as parameter via register a0.
 */
SECTION_FUNC(exception.other, __soc_handle_irq)
	/* Clear exception number from the Interrupt pending register */
	/* FIXME interrupt controller is a dummy */
	/*
	li t1, PULP_ICP_ADDR
	li t2, 1
	sll t3, t2, a0
	sw t3, 0x00(t1)
	*/

	/* Clear exception number from the Event pending register */
	/*
	li t1, PULP_ECP_ADDR
	sw t3, 0x00(t1)
	*/

	/* Return */
	jalr x0, ra


/*
 * SOC-specific function to determine if the exception is the result of a
 * an interrupt or an exception.
 * return 1 (interrupt) or 0 (exception).
 */
SECTION_FUNC(exception.other, __soc_is_irq)
	/* Get exception number from the mcause CSR register. */
	xor a0, a0, a0
	csrr t0, mcause
	andi t0, t0, 0x10 /* FIXME should come from soc header */
	beqz t0, not_interrupt
	addi a0, a0, 1

not_interrupt:
	jalr x0, ra
