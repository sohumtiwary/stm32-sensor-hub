#include "dma_buffer.h"

static size_t advance_index(size_t idx, size_t step, size_t capacity) {
    return (idx + step) % capacity;
}

void dma_buffer_init(dma_ring_buffer_t *rb, uint8_t *backing, size_t capacity) {
    rb->buffer   = backing;
    rb->capacity = capacity;
    rb->head     = 0;
    rb->tail     = 0;
}

size_t dma_buffer_available(const dma_ring_buffer_t *rb) {
    if (rb->head >= rb->tail) {
        return rb->head - rb->tail;
    } else {
        return rb->capacity - (rb->tail - rb->head);
    }
}

size_t dma_buffer_write(dma_ring_buffer_t *rb, const uint8_t *data, size_t len) {
    size_t written = 0;
    for (size_t i = 0; i < len; ++i) {
        size_t next_head = advance_index(rb->head, 1, rb->capacity);
        if (next_head == rb->tail) {
            // buffer full
            break;
        }
        rb->buffer[rb->head] = data[i];
        rb->head = next_head;
        written++;
    }
    return written;
}

size_t dma_buffer_read(dma_ring_buffer_t *rb, uint8_t *out, size_t len) {
    size_t read = 0;
    while (read < len && dma_buffer_available(rb) > 0) {
        out[read] = rb->buffer[rb->tail];
        rb->tail  = advance_index(rb->tail, 1, rb->capacity);
        read++;
    }
    return read;
}
