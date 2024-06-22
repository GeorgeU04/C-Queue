#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
struct Queue typedef Queue;
Queue *create_queue(uint32_t capacity);
bool is_empty(Queue *queue);
uint32_t queue_size(Queue *queue);
int32_t front(Queue *queue);
int32_t back(Queue *queue);
void push(Queue *queue, int32_t value);
void pop(Queue *queue);
void free_queue(Queue *queue);
#endif
