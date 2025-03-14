#include <stdlib.h>
#include <stdio.h>
#include "input.h"

InputBuffer* new_input_buffer() {
    InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
  
    return input_buffer;
}

void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}

void read_input(InputBuffer* input_buffer) {
    int chars_read =  getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (chars_read <= 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
      }
    
      input_buffer->input_length = chars_read - 1;
      input_buffer->buffer[chars_read - 1] = 0;
}