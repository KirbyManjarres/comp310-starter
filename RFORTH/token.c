










#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "token.h"

// Function to classify a token based on its text
static token_type_t classify_token(const char *text) {
    if (isdigit(text[0]))
        return NUMBER;
    else if (strchr(":", text[0]) != NULL || strchr(";", text[0]) != NULL)
        return SYMBOL;
    else if (strchr("+-*/", text[0]) != NULL)
        return OPERATOR;
    else
        return WORD;
}












// Function to get the next token from input
token_t *get_next_token(FILE *input) {
    char buffer[128];
    if (fscanf(input, "%127s", buffer) == 1) {
        token_t *token = malloc(sizeof(token_t));
        if (token == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        token->text = strdup(buffer);
        if (token->text == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
        token->type = classify_token(token->text);
        return token;
    }
    return NULL;
}

// Function to free memory allocated for a token
void free_token(token_t *token) {
    free(token->text);
    free(token);
}

