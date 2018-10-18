/*
 * Copyright (c) 2017 Google LLC.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>
#include <device.h>
#include <gpio.h>
#include <soc.h>

#define CONFIG_GPIO_MICRO5_PORT0_BASE_ADDRESS 0x10000004
#define CONFIG_GPIO_MICRO5_PORT0_LABEL "gpio0"


struct gpio_micro5_port_group_t {
	int dummy;
};


struct gpio_micro5_config_t {
	struct gpio_micro5_port_group_t *regs;
};

#define DEV_CFG(dev) \
	((const struct gpio_micro5_config_s *const)(dev)->config->config_info)

static int gpio_micro5_config(struct device *dev, int access_op, u32_t pin,
			      int flags)
{
#if 0
	const struct gpio_micro5_config_s *config = DEV_CFG(dev);
#endif

	/* FIXME gpio driver is an empty */

	return 0;
}

static int gpio_micro5_write(struct device *dev, int access_op, u32_t pin,
			     u32_t value)
{
#if 0
	const struct gpio_micro5_config_s *config = DEV_CFG(dev);
	u32_t mask = 1 << pin;

	if (access_op != GPIO_ACCESS_BY_PIN) {
		/* TODO(mlhx): support GPIO_ACCESS_BY_PORT */
		return -ENOTSUP;
	}

	if (value != 0) {
		config->regs->OUTSET.bit.OUTSET = mask;
	} else {
		config->regs->OUTCLR.bit.OUTCLR = mask;
	}
#endif

	/* FIXME gpio driver is an empty */

	return 0;
}

static int gpio_micro5_read(struct device *dev, int access_op, u32_t pin,
			    u32_t *value)
{
#if 0
	const struct gpio_micro5_config_s *config = DEV_CFG(dev);
	u32_t bits;

	if (access_op != GPIO_ACCESS_BY_PIN) {
		/* TODO(mlhx): support GPIO_ACCESS_BY_PORT */
		return -ENOTSUP;
	}

	bits = config->regs->IN.bit.IN;
	*value = (bits >> pin) & 1;
#endif

	/* FIXME gpio driver is an empty */

	return 0;
}

static const struct gpio_driver_api gpio_sam0_api = {
	.config = gpio_micro5_config,
	.write = gpio_micro5_write,
	.read = gpio_micro5_read,
};

static int gpio_micro5_init(struct device *dev)
{
	return 0;
}

static const struct gpio_micro5_config_t gpio_micro5_config_0 = {
	.regs = (struct gpio_micro5_port_group_t *)
		CONFIG_GPIO_MICRO5_PORT0_BASE_ADDRESS,
};

DEVICE_AND_API_INIT(gpio_sam0_0, CONFIG_GPIO_MICRO5_PORT0_LABEL,
		    gpio_micro5_init,
		    NULL, &gpio_micro5_config_0, POST_KERNEL,
		    CONFIG_KERNEL_INIT_PRIORITY_DEVICE, &gpio_sam0_api);
