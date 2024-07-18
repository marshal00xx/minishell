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

void tokenize_redirections(t_token **tokens, char *token)
{
    if (*token == '<')
    {
        if (*(token + 1) && *(token + 1) == '<')
        {
            tokens_list_append(tokens, new_token(TOKEN_HDOC, "<<"));
            token++;
        }
        else
            tokens_list_append(tokens, new_token(TOKEN_RDIR_IN, "<"));
    }
    else if (*token == '>')
    {
        if (*(token + 1) && *(token + 1) == '>')
        {
            tokens_list_append(tokens, new_token(TOKEN_RDIR_APPEND, ">>"));
            token++;
        }
        else
            tokens_list_append(tokens, new_token(TOKEN_RDIR_OUT, ">"));
    }
}
