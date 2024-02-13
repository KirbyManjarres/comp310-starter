#include <stdio.h>
#include "token.h"

int main() {
    printf("Enter FORTH program:\n");

    // Read tokens from standard input until EOF
    token_t *token;
    while ((token = get_next_token(stdin)) != NULL) {
        // Print token class and text
        switch (token->type) {
            case NUMBER:
                printf("Number: %s\n", token->text);
                break;
            case OPERATOR:
                printf("Operator: %s\n", token->text);
                break;
            case SYMBOL:
                printf("Symbol: %s\n", token->text);
                break;
            case WORD:
                printf("Word: %s\n", token->text);
                break;
        }
        // Free memory allocated for the token
        free_token(token);
    }

    return 0;
}

