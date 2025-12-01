#ifndef UART_CLI_H
#define UART_CLI_H

#include <stdint.h>
#include <stddef.h>

void uart_cli_init(void);         // init UART + any buffers
void uart_cli_process(void);      // call periodically to handle RX commands
void uart_cli_write(const char *s); // helper to send strings

#endif // UART_CLI_H
