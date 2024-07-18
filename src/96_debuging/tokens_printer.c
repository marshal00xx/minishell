#include "../headers/minishell.h"

void print_tokens(t_token *tokens) {
    const char *filename = "tokens.txt"; // Hardcoded filename
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("fopen");
        return;
    }

    while (tokens) {
        fprintf(file, "Token type: %d, Token value: %s\n", tokens->type, tokens->value);
        tokens = tokens->next_token;
    }

    fclose(file);
    printf("Tokens written to %s\n", filename);
}