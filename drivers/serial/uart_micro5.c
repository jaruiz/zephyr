/*
 * Copyright (c) 2018 Jose Ruiz <jose.a.ruiz.dominguez.eu@gmail.com>
 * (Derived from ESP32 UART driver by Intel.)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <soc.h>
#include <uart.h>
#include <errno.h>
#include <board.h>


static unsigned char micro5_uart_tx(struct device *dev, unsigned char c)
{
	ARG_UNUSED(dev);

	/* FIXME should poll for busy tx status */
	*((volatile u8_t *)UART_TXB) = (u8_t)c;

	return c;
}

static int micro5_uart_rx(struct device *dev, unsigned char *p_char)
{
	ARG_UNUSED(dev);

	/* FIXME uart rx not implemented */
	int poll_code = 0;
	*p_char = '\0';

	/* FIXME status register unimplemented */
	switch (poll_code) {
	case 0:
		return 0;
	case 1:
		return -EINPROGRESS;
	case 2:
		return -EBUSY;
	default:
		return -EIO;
	}
}

static int micro5_uart_init(struct device *dev)
{
	ARG_UNUSED(dev);

	/* FIXME uart has nothing to init yet */

	return 0;
}

static const struct uart_driver_api micro5_uart_api = {
	.poll_in = &micro5_uart_rx,
	.poll_out = &micro5_uart_tx,
	.err_check = NULL,
};

DEVICE_AND_API_INIT(micro5_uart0, CONFIG_UART_MICRO5_PORT_0_NAME,
		    micro5_uart_init, NULL, NULL,
		    PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEVICE,
		    &micro5_uart_api);
