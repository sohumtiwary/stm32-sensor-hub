#ifndef UART_CLI_H
#define UART_CLI_H

#include <stdint.h>
#include <stddef.h>


void uart_cli_init(void);

void uart_cli_process(void);

void uart_cli_write(const char *s);

void uart_cli_writeline(const char *s);

#endif
