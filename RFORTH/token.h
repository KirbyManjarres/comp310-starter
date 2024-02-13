#ifndef TOKEN_H
#define TOKEN_H

// Enum to represent token types
typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD
} token_type_t;

// Struct to represent a token
typedef struct {
    token_type_t type;
    char *text;
} token_t;

// Function to get the next token from input
token_t *get_next_token(FILE *input);

// Function to free memory allocated for a token
void free_token(token_t *token);

#endif /* TOKEN_H */

