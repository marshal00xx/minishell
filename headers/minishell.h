#ifndef MINISHELL_H
#define MINISHELL_H

// libraries
# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>

// error messages
#define UNCLOSED_QUOTES "Syntax error: unclosed quotes.\n"
#define MISPLACED_PIPE "Syntax error: misplaced pipe `|`.\n"
#define INVALID_REDIRECTIONS "Syntax error: invalid redirection.\n"
#define UNSUPPORTED_OPERATORS "Syntax error: unsupported operator.\n"



typedef enum e_token_type
{
	TOKEN_LITERAL,
	TOKEN_PIPE,
	TOKEN_RDIR_IN,
	TOKEN_RDIR_OUT,
	TOKEN_RDIR_APPEND,
	TOKEN_HDOC,
}	t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next_token;
}	t_token;

typedef struct s_ast_node
{
	t_token_type		type;
	char				**args;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;


// 01 syntax error checking
bool has_syntax_error(char *cmd_line);
bool has_mismatched_quotes(char *cmd_line);
bool has_misplaced_pipes(char *cmd_line);
bool has_invalid_redirections(char *cmd_line);
bool has_unsupported_operators(char *cmd_line);
//bool is_invalid_redirection(char *cmd_line);



// 02 tokenization
t_token *new_token(t_token_type type, char *value);
void tokens_list_append(t_token **tokens, t_token *new_token);
void tokenize_pipe(t_token **tokens, char *token);
void tokenize_redirections(t_token **tokens, char *token);
t_token *tokenizer(char *cmd_line);


// 03 parser
t_ast_node *create_ast_node(t_token_type type);
void free_ast_tree(t_ast_node *node);
t_ast_node *create_redirection_node(t_token *token);
int get_token_precedence(t_token_type type);
t_ast_node *parse_command_arguments(t_token **tokens);
t_ast_node *parser(t_token **tokens);


// 66 debugging
void generate_ast_graph(t_ast_node *first_node);
void print_tokens(t_token *tokens);

#endif