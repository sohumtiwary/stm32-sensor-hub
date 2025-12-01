#ifndef I2C_DRIVER_H
#define I2C_DRIVER_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    void *instance;   // e.g., I2C_TypeDef * in a real project
} i2c_bus_t;

void i2c_init(i2c_bus_t *bus);

int i2c_write_reg(i2c_bus_t *bus, uint8_t addr, uint8_t reg, uint8_t value);

int i2c_read_reg(i2c_bus_t *bus, uint8_t addr, uint8_t reg, uint8_t *value);

int i2c_read_regs(i2c_bus_t *bus, uint8_t addr, uint8_t reg, uint8_t *buf, size_t len);

#endif
