/*
 * Copyright (c) 2018 Jose Ruiz <jose.a.ruiz.dominguez.eu@gmail.com>
 * (Derived from the Pulpino version by Jean-Paul Etienne)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __MICRO5_SOC_H_
#define __MICRO5_SOC_H_


/* FIXME most of this is temporary placeholding stuff */

/*
 * SOC-specific MSTATUS related info
 */
/* MSTATUS register to save/restore upon irq/trap/context switch */
#define SOC_MSTATUS_REG            0x300    /* FIXME MSTATUS */

#define SOC_MSTATUS_IEN            (1 << 0) /* Machine Interrupt Enable */

/*
 * Default MSTATUS register value to restore from stack
 * upon scheduling a thread for the first time
 */
#define SOC_MSTATUS_DEF_RESTORE    SOC_MSTATUS_IEN

/* SOC-specific MCAUSE bitfields */
#define SOC_MCAUSE_EXP_MASK        0x0F     /* Exception code Mask */
#define SOC_MCAUSE_ECALL_EXP       0x0b     /* ECALL exception number */

/* SOC-Specific EXIT ISR command */
#define SOC_ERET                   mret


#ifndef _ASMLANGUAGE
#include <irq.h>


#if defined(CONFIG_RISCV_SOC_INTERRUPT_INIT)
void soc_interrupt_init(void);
#endif


/* lib-c hooks required RAM defined variables */
#define RISCV_RAM_BASE             CONFIG_MICRO5_RAM_BASE_ADDRESS
#define RISCV_RAM_SIZE             CONFIG_MICRO5_RAM_SIZE

#endif  /* !_ASMLANGUAGE */

#endif  /* __MICRO5_SOC_H_ */
