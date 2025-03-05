#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "meta.h"

MetaCommandExecResult execute_meta_command(InputBuffer* input_buffer) {
    if (strcmp(input_buffer->buffer, "/exit") == 0) {
        close_input_buffer(input_buffer);
        exit(EXIT_SUCCESS);
    } else {
        return META_COMMAND_UNRECOGNIZED;
    }
}