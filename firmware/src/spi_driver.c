#include "spi_driver.h"

//  hook into STM32 SPI or HAL.

void spi_init(spi_bus_t *bus) {
    (void)bus;
    // TODO: configure SPI peripheral
}

int spi_transfer(spi_bus_t *bus, const uint8_t *tx, uint8_t *rx, size_t len) {
    (void)bus;
    (void)tx;
    (void)rx;
    (void)len;
    // TODO: blocking transfer, DMA-based, etc.
    return 0;
}
