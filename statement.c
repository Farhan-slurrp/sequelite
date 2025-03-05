#include <string.h>
#include <stdio.h>
#include "input.h"
#include "statement.h"

PrepareStatementResult prepare_statement(InputBuffer* input_buffer, Statement* statement) {
    if (strncmp(input_buffer->buffer, "throw in", 8) == 0 || strncmp(input_buffer->buffer, "THROW IN", 8) == 0) {
        statement->type = STATEMENT_THROW_IN;
        return PREPARE_STATEMENT_SUCCESS;
    }
    if (strncmp(input_buffer->buffer, "grab", 4) == 0 || strncmp(input_buffer->buffer, "GRAB", 4) == 0) {
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