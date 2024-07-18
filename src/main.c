#include "../headers/minishell.h"

int main(int argc, char **argv) {
    t_ast_node *ast;
    t_token *tokens;

    1 && (ast = NULL, tokens = NULL);
    if (has_syntax_error(argv[argc - 1]))
    {
        printf("Syntax error\n");
        return 1;
    }
    tokens = tokenizer(argv[argc - 1]);
    print_tokens(tokens);
    if (tokens )
        ast = parser(&tokens);
    generate_ast_graph(ast);
    return 0;
}