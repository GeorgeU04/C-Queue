#include "queue.h"
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Queue {
  uint32_t capacity; // full capacity of array
  uint32_t size;     // size of the amount of elements
  int32_t *array;    // array of data
};
Queue *create_queue(uint32_t capacity) {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (!queue) {
    fprintf(stderr, "[ERROR]: Memory Allocation Failed\n");
    exit(EXIT_FAILURE);
  }
  queue->capacity = capacity;
  queue->size = 0;
  queue->array = (int32_t *)malloc(queue->capacity * sizeof(int32_t));
  if (!queue->array) {
    fprintf(stderr, "[ERROR]: Memory Allocation Failed\n");
    free(queue);
    exit(EXIT_FAILURE);
  }
  return queue;
}
bool is_empty(Queue *queue) { return queue->size == 0; }
uint32_t queue_size(Queue *queue) { return queue->size; }
int32_t front(Queue *queue) {
  if (is_empty(queue)) {
    return INT_MIN;
  }
  return queue->array[0];
}
int32_t back(Queue *queue) {
  if (is_empty(queue)) {
    return INT_MIN;
  }
  return queue->array[queue->size - 1];
}

void push(Queue *queue, int32_t value) {
  if (queue->size == queue->capacity) {
    queue->capacity *= 2;
    int32_t *temp =
        (int32_t *)realloc(queue->array, queue->capacity * sizeof(int32_t));
    if (!temp) {
      fprintf(stderr, "[ERROR] Memory Allocation Failed\n");
      free_queue(queue);
      exit(EXIT_FAILURE);
    }
    queue->array = temp;
  }
  queue->array[queue->size++] = value;
}
void pop(Queue *queue) {
  if (is_empty(queue)) {
    fprintf(stderr, "[ERROR] Queue Is Empty");
    return;
  }
  memmove(queue->array, queue->array + 1, (queue->size - 1) * sizeof(int32_t));
  --queue->size;
}
void free_queue(Queue *queue) {
  free(queue->array);
  free(queue);
}
