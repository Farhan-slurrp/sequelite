#ifndef STATEMENT_H
#define STATEMENT_H

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

PrepareStatementResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* statement);

#endif