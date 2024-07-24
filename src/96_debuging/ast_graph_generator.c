#include "../../headers/minishell.h"

void write_dot_node(FILE *file, t_ast_node *node) {
    if (!node) return;

    fprintf(file, "\"%p\" [label=\"", (void *)node);
    switch (node->type) {
        case TOKEN_LITERAL:
            fprintf(file, "LITERAL: ");
            for (int i = 0; node->args && node->args[i]; i++) {
                fprintf(file, "%s ", node->args[i]);
            }
            break;
        case TOKEN_PIPE:
            fprintf(file, "|");
            break;
        case TOKEN_RDIR_IN:
            fprintf(file, "<");
            break;
        case TOKEN_RDIR_OUT:
            fprintf(file, ">");
            break;
        case TOKEN_RDIR_APPEND:
            fprintf(file, ">>");
            break;
        case TOKEN_HDOC:
            fprintf(file, "<<");
            break;
        default:
            fprintf(file, "UNKNOWN");
            break;
    }
    fprintf(file, "\"];\n");

    if (node->left) {
        fprintf(file, "\"%p\" -> \"%p\" [label=\"L\"];\n", (void *)node, (void *)node->left);
        write_dot_node(file, node->left);
    }
    if (node->right) {
        fprintf(file, "\"%p\" -> \"%p\" [label=\"R\"];\n", (void *)node, (void *)node->right);
        write_dot_node(file, node->right);
    }
}

// Function to generate the AST diagram and write it to a DOT file
void generate_ast_graph(t_ast_node *first_node) {
    const char *filename = "ast.dot";
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("fopen");
        return;
    }

    fprintf(file, "digraph AST {\n");
    write_dot_node(file, first_node);
    fprintf(file, "}\n");

    fclose(file);
    printf("AST diagram generated in %s\n", filename);
}