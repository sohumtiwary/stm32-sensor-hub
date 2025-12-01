#include "i2c_driver.h"

void i2c_init(i2c_bus_t *bus) {
    (void)bus;
    // TODO: configure I2C peripheral
}

int i2c_write_reg(i2c_bus_t *bus, uint8_t addr, uint8_t reg, uint8_t value) {
    (void)bus;
    (void)addr;
    (void)reg;
    (void)value;
    // TODO
    return 0;
}

int i2c_read_reg(i2c_bus_t *bus, uint8_t addr, uint8_t reg, uint8_t *value) {
    (void)bus;
    (void)addr;
    (void)reg;
    (void)value;
    // TODO
    return 0;
}

int i2c_read_regs(i2c_bus_t *bus, uint8_t addr, uint8_t reg, uint8_t *buf, size_t len) {
    (void)bus;
    (void)addr;
    (void)reg;
    (void)buf;
    (void)len;
    // TODO
    return 0;
}
