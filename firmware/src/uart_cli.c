#include "uart_cli.h"
#include "main.h"
#include <string.h>

extern UART_HandleTypeDef huart2;

void uart_cli_init(void) {
    const char *msg = "\r\nUART CLI ready\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), 100);
}

void uart_cli_process(void) {
    // RX command handling can be added later
}

void uart_cli_write(const char *s) {
    HAL_UART_Transmit(&huart2, (uint8_t *)s, strlen(s), 100);
}

void uart_cli_writeline(const char *s) {
    uart_cli_write(s);
    uart_cli_write("\r\n");
}
