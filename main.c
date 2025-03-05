#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"
#include "meta.h"
#include "statement.h"

#define true 1

void print_prompt() {
    printf("sequelite > ");
}

char* to_lower_case(const char* str) {
    int length = strlen(str) + 1;
    char* result = (char*)malloc(length * sizeof(char));
    if (result == NULL) {
        return NULL;
    }

    for (int i = 0; i < length - 1; i++) {
        result[i] = tolower(str[i]);
    }

    result[length - 1] = '\0';
    return result;
}

void free_char(char* str) {
    if (str != NULL) {
        free(str);
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

        execute_statement(&statement);
        printf("Executed.\n");
    }
}