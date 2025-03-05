#ifndef META_H 
#define META_H

typedef enum {
    META_COMMAND_RUN_SUCCESS,
    META_COMMAND_UNRECOGNIZED
} MetaCommandExecResult;

MetaCommandExecResult execute_meta_command(InputBuffer* input_buffer);

#endif