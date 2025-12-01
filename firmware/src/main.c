#include <stdint.h>
#include "i2c_driver.h"
#include "spi_driver.h"
#include "dma_buffer.h"
#include "uart_cli.h"

// Example sensor addresses (placeholder)
#define IMU_ADDR   0x68
#define TEMP_ADDR  0x76

static i2c_bus_t i2c1;
static spi_bus_t spi1;

#define TELEMETRY_BUFFER_SIZE 512
static uint8_t telemetry_backing[TELEMETRY_BUFFER_SIZE];
static dma_ring_buffer_t telemetry_rb;

typedef struct {
    int16_t ax, ay, az;
    int16_t gx, gy, gz;
    int32_t temperature;
    int32_t pressure;
} sensor_sample_t;

static void system_init(void) {
    // TODO: clock init, GPIO init, etc.
    i2c_init(&i2c1);
    spi_init(&spi1);
    uart_cli_init();

    dma_buffer_init(&telemetry_rb, telemetry_backing, TELEMETRY_BUFFER_SIZE);
}

static void read_sensors(sensor_sample_t *s) {
    (void)s;
    // TODO:
    //  - use i2c_read_regs() for IMU
    //  - use spi_transfer() for pressure/temp sensor
}

static void push_sample_to_telemetry(const sensor_sample_t *s) {
    dma_buffer_write(&telemetry_rb, (const uint8_t *)s, sizeof(*s));
}

static void flush_telemetry(void) {
    uint8_t chunk[64];
    size_t n = dma_buffer_read(&telemetry_rb, chunk, sizeof(chunk));
    if (n > 0) {
        // TODO: send chunk over UART
        (void)chunk;
        (void)n;
    }
}

int main(void) {
    HAL_Init();
    SystemClock_Config();

    MX_GPIO_Init();
    MX_USART2_UART_Init();

    uart_cli_init();

    while (1) {
        uart_cli_writeline("loop");
        HAL_Delay(1000);
    }
}
