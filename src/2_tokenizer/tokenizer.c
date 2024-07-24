#include "../../headers/minishell.h"

// int is_operator_char(char c) {
//     return (c == '<' || c == '>' || c == '|');
// }

// void update_iterator(char ***arg_iter)
// {
//     char *arg = **arg_iter;

//     if (*arg == '>' || *arg == '<' || *arg == '|') {
//         // Move the iterator past the operator character
//         (***arg_iter)++;
        
//         // Check if the next token starts with the operator character
//         if (**arg_iter && (**(*arg_iter) == '>' || **(*arg_iter) == '<' || **(*arg_iter) == '|')) {
//             // Skip over additional operators if present
//             (***arg_iter)++;
//         }
//     } else {
//         // Move to the next argument
//         (*arg_iter)++;
//     }
// }

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
