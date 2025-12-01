#include "uart_cli.h"


void uart_cli_init(void) {
    // TODO: configure UART peripheral + RX buffer
}

void uart_cli_process(void) {
    // TODO: poll for incoming bytes, parse simple commands, etc.
}

void uart_cli_write(const char *s) {
    (void)s;
    // TODO: send null-terminated string over UART
}
