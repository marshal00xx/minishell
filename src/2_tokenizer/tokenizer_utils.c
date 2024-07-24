#include "../../headers/minishell.h"

t_token *new_token(t_token_type type, char *value)
{
    t_token *token;

    token = malloc(sizeof(t_token));
    if (!token)
        return (NULL);
    token->type = type;
    token->value = ft_strdup(value);
    if (!token->value)
        return (free(token), NULL);
    token->next_token = NULL;
    return (token);
}

void tokens_list_append(t_token **tokens, t_token *new_token)
{
    t_token *last;

    if (!*tokens)
        *tokens = new_token;
    else
    {
        last = *tokens;
        while (last->next_token)
            last = last->next_token;
        last->next_token = new_token;
    }
}

void process_remaining_token(t_token **tokens, char *token)
{
    if (*token)
    {
        tokens_list_append(tokens, new_token(TOKEN_LITERAL, token));
    }
}

void tokenize_pipe(t_token **tokens, char *token)
{
    tokens_list_append(tokens, new_token(TOKEN_PIPE, "|"));
    if (*(token + 1))
        process_remaining_token(tokens, token + 1);
}

void tokenize_redirections(t_token **tokens, char *token)
{
    int operator_size;

    operator_size = 1;
    if (*token == '<')
    {
        if (*(token + 1) && *(token + 1) == '<')
        {
            tokens_list_append(tokens, new_token(TOKEN_HDOC, "<<"));
            operator_size = 2;
        }
        else
            tokens_list_append(tokens, new_token(TOKEN_RDIR_IN, "<"));
    }
    else if (*token == '>')
    {
        if (*(token + 1) && *(token + 1) == '>')
        {
            tokens_list_append(tokens, new_token(TOKEN_RDIR_APPEND, ">>"));
            operator_size = 2;
        }
        else
            tokens_list_append(tokens, new_token(TOKEN_RDIR_OUT, ">"));
    }
    if (token)
        process_remaining_token(tokens, token + operator_size);
}
