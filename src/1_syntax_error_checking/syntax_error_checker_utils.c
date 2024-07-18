#include "../../headers/minishell.h"

bool has_mismatched_quotes(char *cmd_line)
{
    int single_quotes;
    int double_quotes;

    1 && (single_quotes = 0, double_quotes = 0);
    while (*cmd_line)
    {
        if (*cmd_line == '\'')
            single_quotes += 1;
        else if (*cmd_line == '\"')
            double_quotes += 1;
        cmd_line++;
    }
    return ((single_quotes % 2) + (double_quotes % 2));
}

bool has_misplaced_pipes(char *cmd_line)
{
    bool expecting_expression;
    bool s_quote_open;
    bool d_quote_open;

    expecting_expression = false;
    1 && (s_quote_open = false, d_quote_open = false);
    if (*cmd_line == '|')
        return (true);
    while (*cmd_line)
    {
        if (*cmd_line == '\'')
            s_quote_open = !s_quote_open;
        else if (*cmd_line == '\"')
            d_quote_open = !d_quote_open;
        if (*cmd_line == '|' && !s_quote_open && !d_quote_open)
        {
            if (expecting_expression == true)
                return (true);
            expecting_expression = true;
        }
        else if (!ft_isspace(*cmd_line))
            expecting_expression = false;
        cmd_line++;
    }
    return (expecting_expression);
}

bool has_invalid_redirections(char *cmd_line)
{
    bool s_quote_open = false;
    bool d_quote_open = false;
    char *current_operator;

    while (*cmd_line)
    {
        if (*cmd_line == '\'')
            s_quote_open = !s_quote_open;
        else if (*cmd_line == '\"')
            d_quote_open = !d_quote_open;
        if (!s_quote_open && !d_quote_open
            && (*cmd_line == '>' || *cmd_line == '<'))
        {
            current_operator = cmd_line++;
            if (*current_operator == *cmd_line)
                cmd_line++;
            cmd_line = ft_skip_spaces(cmd_line);
            if (*cmd_line == '\0' || *cmd_line == '>'
                || *cmd_line == '<' || *cmd_line == '|')
                return true;
        }
        cmd_line++;
    }
    return false;
}
