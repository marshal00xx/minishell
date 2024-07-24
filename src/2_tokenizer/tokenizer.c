#include "../../headers/minishell.h"

t_token *tokenizer(char *cmd_line)
{
    char **splitted_args;
    char **arg_iter;
    t_token *tokens;

    tokens = NULL;
    splitted_args = ft_split(cmd_line);
    if (!splitted_args)
    {
        perror("Error: tokenizer: split didn't work >_<\n");
        return NULL;
    }
    arg_iter = splitted_args;
    while (*arg_iter)
    {
        if (**arg_iter == '|')
            tokenize_pipe(&tokens, *arg_iter);
        else if (**arg_iter == '>' || **arg_iter == '<')
            tokenize_redirections(&tokens, *arg_iter);
        else
            tokens_list_append(&tokens, new_token(TOKEN_LITERAL, *arg_iter));
        arg_iter++;
    }
    ft_free_list_chars(splitted_args);
    return tokens;
}
