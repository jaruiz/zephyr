Zephyr fork (v1.13-branch) -- port for micro5 core
==================================================

This fork of Zephyr is a port of branch `v1.13-branch` for the RISC-V micro5_ core, which is meant to be an entrant in the `RISC-V SoftCPU Contest 2018`_.

A copy of the original README file for the repository has been preserved_ as a reference. This README file only contains information relevant to the micro5_ port.

Status summary
==============

The whole port is little more than a placeholder at the time of writing this. The features of the acutal hardware have not been defined yet. In fact, I am in the process of finding out what's the minimum set of features the SoC needs to support in order to meet the requirements of `the contest`_ and that will take some experimentation.

A few applications can be `built and run on a custom iss`_ using this Zephyr port. This custom iss is an ad-hoc `basic risc-v simulator`_ specifically built to help me experiment with the ISA and the OS. So far none of this has met any real or simulated hardware.


New SoCs and boards
===================

The micro5_ core is just an implementation of the :code:`rv32i` ISA so it uses the existing support for `riscv32` in Zephyr.

It's been necessary to port a new *SoC* under the :code:`riscv32` architecture, plus a new *board* using the new SoC:

+------------+--------------------+----------------------------------+
| New...     | Name               | Location                         |
+============+====================+==================================+
| SoC        | micro5             | arch/riscv32/soc/micro5          |
+------------+--------------------+----------------------------------+
| Board      | ice40up5k_micro5   | boards/riscv32/ice40up5k_micro5  |
+------------+--------------------+----------------------------------+


Board :code:`ice40up5k_micro5` targets Lattice's `iCE40 UltraPlus Breakout Board`_. Other board targets may be added eventually built around the same SoC support.

Eventually, all the *soc* and *board* configuration symbols will be documented here or somewhere else.


New drivers
===========

Apart from the support for the new :code:`soc` and :code:`board` entities, the port includes a number of *drivers*: 


+------------+--------------------+----------------------------------------+
| New...     | Root config name   | New and modified files                 |
+============+====================+========================================+
| serial     | UART_MICRO5        | :code:`drivers/serial/Kconfig.micro5`  |
+            +                    +----------------------------------------+
|            |                    | :code:`drivers/serial/uart_micro5.c`   |
+            +                    +----------------------------------------+
|            |                    | :code:`drivers/serial/Kconfig`         |
+            +                    +----------------------------------------+
|            |                    | :code:`drivers/serial/CMakeLists.txt`  |
+------------+--------------------+----------------------------------------+
| timer      | MICRO5_TIMER       | :code:`drivers/timer/micro5_timer.c`   |
+            +                    +----------------------------------------+
|            |                    | :code:`drivers/timer/Kconfig`          |
+            +                    +----------------------------------------+
|            |                    | :code:`drivers/timer/CMakeLists.txt`   |
+------------+--------------------+----------------------------------------+
| gpio       | GPIO_MICRO5        | :code:`drivers/gpio/Kconfig.micro5`    |
+            +                    +----------------------------------------+
|            |                    | :code:`drivers/gpio/gpio_micro5.c`     |
+            +                    +----------------------------------------+
|            |                    | :code:`drivers/gpio/Kconfig`           |
+            +                    +----------------------------------------+
|            |                    | :code:`drivers/gpio/CMakeLists.txt`    |
+------------+--------------------+----------------------------------------+

All the drivers have been created by mimicking existing drivers. The API is implemented to the extent it is necessary to execute the `few code samples` I have been experimenting with. Like everything else this is a work in progress.


Caveats
=======

This fork has been made exclusively for the SoftCPU contest. I think it goes without saying that this code is not meant to ever become a part of the main Zephyr repository. Thus, although I have tried to follow the style guidelines and have strived to make new code as much alike old code as possible, it should be remembered that this is little more than a supporting act for the main show: the hardware.



.. _preserved: https://github.com/jaruiz/zephyr/blob/v1.13-branch/README.original.rst
.. _micro5: https://github.com/jaruiz/micro5
.. _`RISC-V SoftCPU Contest 2018`: https://riscv.org/2018contest/
.. _`the contest`: https://riscv.org/2018contest/
.. _`iCE40 UltraPlus Breakout Board`: http://www.latticesemi.com/en/Products/DevelopmentBoardsAndKits/iCE40UltraPlusBreakoutBoard
.. _`built and run on a custom iss`: https://github.com/jaruiz/micro5sim#running-zephyr-code-samples
.. _`basic risc-v simulator`: https://github.com/jaruiz/micro5sim
