zephyr_include_directories(.)

zephyr_compile_options(
  -march=I
  )


zephyr_sources(
  soc_irq.S
  vector.S
  micro5_irq.c
  micro5_idle.c
  )
