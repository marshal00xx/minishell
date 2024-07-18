#include "../../headers/minishell.h"

bool has_syntax_error(char *cmd_line)
{
    //TODO: check for not required special characters

    if (has_mismatched_quotes(cmd_line) == true)
    {
        perror(UNCLOSED_QUOTES);
        return (true);
    }
    if (has_misplaced_pipes(cmd_line) == true)
    {
        perror(MISPLACED_PIPE);
        return (true);
    }
    if (has_invalid_redirections(cmd_line) == true)
    {
        perror(INVALID_REDIRECTIONS);
        return (true);
    }
    // if (has_unsupported_operators(cmd_line))
    // {
    //     perror(UNSUPPORTED_OPERATORS);
    //     return (true);
    // }
    return (false);
}
