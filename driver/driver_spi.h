#ifndef DRIVER_SPI_H
#define DRIVER_SPI_H

#include "main.h"

int32_t driver_spi_write_byte(uint8_t dat);

int32_t driver_spi_write_len(uint8_t *data, uint32_t len);

#endif
