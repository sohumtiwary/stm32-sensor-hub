#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    void *instance;
} spi_bus_t;

void spi_init(spi_bus_t *bus);

// Full-duplex transfer. If rx is NULL, it's write-only.
// If tx is NULL, it's read-only (send dummy bytes).
int spi_transfer(spi_bus_t *bus, const uint8_t *tx, uint8_t *rx, size_t len);

#endif // SPI_DRIVER_H
