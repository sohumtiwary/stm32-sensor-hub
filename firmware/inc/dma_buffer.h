#ifndef DMA_BUFFER_H
#define DMA_BUFFER_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    uint8_t *buffer;
    size_t   capacity;
    size_t   head;
    size_t   tail;
} dma_ring_buffer_t;

// Initialize ring buffer with backing storage + capacity
void dma_buffer_init(dma_ring_buffer_t *rb, uint8_t *backing, size_t capacity);

// Write up to len bytes into buffer, returns number of bytes actually written
size_t dma_buffer_write(dma_ring_buffer_t *rb, const uint8_t *data, size_t len);

// Read up to len bytes out of buffer, returns number of bytes actually read
size_t dma_buffer_read(dma_ring_buffer_t *rb, uint8_t *out, size_t len);

// How many bytes are currently stored in the buffer?
size_t dma_buffer_available(const dma_ring_buffer_t *rb);

#endif // DMA_BUFFER_H
