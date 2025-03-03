#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

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

void print_prompt() {
    printf("sequelite > ");
}

void read_input(InputBuffer* input_buffer) {
    int chars_read =  getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);
}

int main() {
    InputBuffer* input_buffer = new_input_buffer();
    while(true) {
        print_prompt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, "/exit") == 10) {
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            printf("%s", input_buffer->buffer);
        }
    }
}