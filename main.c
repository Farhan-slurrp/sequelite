#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1

typedef struct {
    char* buffer;
    size_t buffer_length;
    ssize_t input_length;
} InputBuffer;

typedef enum {
    META_COMMAND_RUN_SUCCESS,
    META_COMMAND_UNRECOGNIZED
} MetaCommandExecResult;

typedef enum { 
    STATEMENT_THROW_IN, 
    STATEMENT_GRAB,
    STATEMENT_REVAMP,
    STATEMENT_YEET,
    STATEMENT_AT,
    STATEMENT_LINK 
} StatementType;

typedef struct {
    StatementType type;
} Statement;

typedef enum { 
    PREPARE_STATEMENT_SUCCESS, 
    PREPARE_STATEMENT_UNRECOGNIZED 
} PrepareStatementResult;

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

    if (chars_read <= 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
      }
    
      input_buffer->input_length = chars_read - 1;
      input_buffer->buffer[chars_read - 1] = 0;
}

MetaCommandExecResult execute_meta_command(InputBuffer* input_buffer) {
    if (strcmp(input_buffer->buffer, "/exit") == 0) {
        close_input_buffer(input_buffer);
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED;
    }
}

PrepareStatementResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {
        if (strncmp(input_buffer->buffer, "throw in", 8) == 0) {
        statement->type = STATEMENT_THROW_IN;
            return PREPARE_STATEMENT_SUCCESS;
        }
        if (strncmp(input_buffer->buffer, "grab", 4) == 0) {
            statement->type = STATEMENT_GRAB;
            return PREPARE_STATEMENT_SUCCESS;
        }

        return PREPARE_STATEMENT_UNRECOGNIZED;
}

void execute_statement(Statement* statement) {
    switch (statement->type) {
        case (STATEMENT_THROW_IN):
            printf("This is where we would throw in data.\n");
            break;
        case (STATEMENT_GRAB):
            printf("This is where we would grab data.\n");
            break;
    }
}

int main() {
    InputBuffer* input_buffer = new_input_buffer();
    while(true) {
        print_prompt();
        read_input(input_buffer);

        if (input_buffer->buffer[0] == '/') {
            switch (execute_meta_command(input_buffer)) {
                case (META_COMMAND_RUN_SUCCESS):
                    continue;
                case (META_COMMAND_UNRECOGNIZED):
                    printf("Unrecognized command '%s'\n", input_buffer->buffer);
                    continue;
            }
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)) {
        case PREPARE_STATEMENT_SUCCESS:
            break;
        case PREPARE_STATEMENT_UNRECOGNIZED:
            printf("Unrecognized statement at the start of '%s'\n", input_buffer->buffer);
            continue;
        }
    }
}