#include "../../headers/minishell.h"

t_ast_node *parse_expression(t_token **tokens, int precedence)
{
    t_ast_node *left_node; 
    t_ast_node *right_node; 
    t_ast_node *operator_node; 
    t_token *current_token; 
    int token_precedence; 

    left_node = parse_command_arguments(tokens); 
    current_token = *tokens; 
    while (current_token && !(current_token->type == TOKEN_LITERAL)) 
    {
        token_precedence = get_token_precedence(current_token->type); 
        if (token_precedence < precedence) 
            break;
        *tokens = (*tokens)->next_token; 
        right_node = parse_expression(tokens, token_precedence + 1); 
        operator_node = create_ast_node(current_token->type); 
        operator_node->left = left_node; 
        operator_node->right = right_node; 
        left_node = operator_node; 
        current_token = *tokens; 
    }
    return (left_node); 
}

t_ast_node *parser(t_token **tokens)
{
    if (!tokens || !*tokens) 
        return (NULL); 
    return (parse_expression(tokens, 0)); 
}