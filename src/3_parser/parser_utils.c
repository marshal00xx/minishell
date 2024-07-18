#include "../../headers/minishell.h"



t_ast_node *create_ast_node(t_token_type type)
{
    t_ast_node *node = malloc(sizeof(t_ast_node)); 
    if (!node) 
        return (NULL); 
    node->type = type; 
    node->args = NULL; 
    node->left = NULL; 
    node->right = NULL; 
    return (node); 
}


void free_ast_tree(t_ast_node *node)
{
    int i = 0; 
    if (!node) 
        return; 
    free_ast_tree(node->left); 
    free_ast_tree(node->right); 
    if (node->type == TOKEN_LITERAL && node->args) 
    {
        while (node->args[i]) 
            free(node->args[i++]); 
        free(node->args); 
    }
    free(node); 
}


int get_token_precedence(t_token_type type)
{
    if (type == TOKEN_PIPE) 
        return (1); 
    else if (!(type == TOKEN_LITERAL)) 
        return (2); 
    return (0); 
}


t_ast_node *parse_command_arguments(t_token **tokens)
{
    t_ast_node *command_node; 
    int arg_count; 
    t_token *current; 
    t_token *tmp; 
    int i; 

    arg_count = 0; 
    current = *tokens; 
    i = 0; 
    command_node = create_ast_node(TOKEN_LITERAL); 
    while (current && current->type == TOKEN_LITERAL) 
    {
        current = current->next_token; 
        arg_count++; 
    }
    command_node->args = malloc(sizeof(char *) * (arg_count + 1)); 
    if (!command_node->args) 
    {
        perror("Error: parse_command_arguments: malloc failed >_<"); 
        return (NULL); 
    }
    while (i < arg_count) 
    {
        command_node->args[i] = ft_strdup((*tokens)->value); 
        tmp = *tokens; 
        *tokens = (*tokens)->next_token; 
        free(tmp->value); 
        free(tmp); 
        i++; 
    }
    command_node->args[arg_count] = NULL; 
    return (command_node); 
}