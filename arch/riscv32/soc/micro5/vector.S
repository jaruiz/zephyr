/*
 * (Derived from the Pulpino version by Jean-Paul Etienne)
 * Contributors: 2018 Antmicro <www.antmicro.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <toolchain.h>

/* exports */
GTEXT(__start)

/* imports */
GTEXT(__reset)
GTEXT(__irq_wrapper)

/*
 * Call __irq_wrapper to handle all interrupts/exceptions/faults/ECALL
 *
 * ECALL is used to handle context switching of threads, as well as
 * IRQ offloading (when enabled).
 *
 */
SECTION_FUNC(vectors, __start)
	.option norvc;

	/* Call __reset for reset vector */
	.org 0x0
	jal x0, __reset

	/* All other exceptions and interrupts. */
	.org 0x4
	jal x0, __irq_wrapper
