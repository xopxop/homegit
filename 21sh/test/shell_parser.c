#include <stdlib.h>

t_astnode *complete_command(t_token *token);
t_astnode *list(t_token *token);
t_astnode *and_or(t_token *token);
t_astnode *pipeline(t_token *token);
t_astnode *pipe_sequence(t_token *token);
t_astnode *command(t_token *token);
t_astnode *compound_command(t_token *token);
t_astnode *subshell(t_token *token);
t_astnode *compound_list(t_token *token);
t_astnode *term(t_token *token);
t_astnode *for_clause(t_token *token);
t_astnode *name(t_token *token);
t_astnode *in(t_token *token);
t_astnode *wordlist(t_token *token);
t_astnode *case_clause(t_token *token);
t_astnode *case_list_ns(t_token *token);
t_astnode *case_list(t_token *token);
t_astnode *case_item_ns(t_token *token);
t_astnode *case_item(t_token *token);
t_astnode *pattern(t_token *token);
t_astnode *if_clause(t_token *token);
t_astnode *else_part(t_token *token);
t_astnode *while_clause(t_token *token);
t_astnode *until_clause(t_token *token);
t_astnode *function_definition(t_token *token);
t_astnode *function_body(t_token *token);
t_astnode *fname(t_token *token);
t_astnode *brace_group(t_token *token);
t_astnode *do_group(t_token *token);
t_astnode *simple_command(t_token *token);
t_astnode *cmd_name(t_token *token);
t_astnode *cmd_word(t_token *token);
t_astnode *cmd_prefix(t_token *token);
t_astnode *cmd_suffix(t_token *token);
t_astnode *redirect_list(t_token *token);
t_astnode *io_redirect(t_token *token);
t_astnode *io_file(t_token *token);
t_astnode *filename(t_token *token);
t_astnode *io_here(t_token *token);
t_astnode *here_end(t_token *token);
t_astnode *newline_list(t_token *token);
t_astnode *linebreak(t_token *token);
t_astnode *separator_op(t_token *token);
t_astnode *separotor(t_token *token);
t_astnode *sequential_sep(t_token *token);

typedef enum
{
	AST_complete_command,
	AST_list,
	AST_and_or,
	AST_pipeline,
	AST_pipe_sequence,
	AST_command,
	AST_compound_command,
	AST_subshell,
	AST_compound_list,
	AST_term,
	AST_for_clause,
	AST_name,
	AST_in,
	AST_wordlist,
	AST_case_clause,
	AST_case_list_ns,
	AST_case_list,
	AST_case_item_ns,
	AST_case_item,
	AST_pattern,
	AST_if_clause,
	AST_else_part,
	AST_while_clause,
	AST_until_clause,
	AST_function_definition,
	AST_function_body,
	AST_fname,
	AST_brace_group,
	AST_do_group,
	AST_simple_command,
	AST_cmd_name,
	AST_cmd_word,
	AST_cmd_prefix,
	AST_cmd_suffix,
	AST_redirect_list,
	AST_io_redirect,
	AST_io_file,
	AST_filename,
	AST_io_here,
	AST_here_end,
	AST_newline_list,
	AST_linebreak,
	AST_separator_op,
	AST_separotor,
	AST_sequential_sep,
}	t_astnode_type;

typedef struct			s_astnode
{
	t_astnode_type		type;
	char				*data;
	struct s_astnode	*right;
	struct s_astnode	*left;
}						t_astnode;

typedef enum{
	TOKEN_WORD,
	TOKEN_ASSIGNMENT_WORD,
	TOKEN_NAME,
	TOKEN_NEWLINE,
	TOKEN_IO_NUMBER,
	TOKEN_AND_IF,
	TOKEN_OR_IF,
	TOKEN_DSEMI,
	TOKEN_DLESS,
	TOKEN_DGREAT,
	TOKEN_LESSAND,
	TOKEN_GREATAND,
	TOKEN_LESSGREAT,
	TOKEN_DLESSDASH,
	TOKEN_CLOBBER,
	TOKEN_If,
	TOKEN_Then,
	TOKEN_Else,
	TOKEN_Elif,
	TOKEN_Fi,
	TOKEN_Do,
	TOKEN_Done,
	TOKEN_Case,
	TOKEN_Esac,
	TOKEN_While,
	TOKEN_Until,
	TOKEN_For,
	TOKEN_Lbrace,
	TOKEN_Rbrace,
	TOKEN_Bang,
	TOKEN_In,
}t_token_type;

typedef struct			s_token
{
	char				*data;
	t_token_type		type;
	struct s_token		*next;
}						t_token;


int main()
{
	return (0);
}

t_astnode	*complete_command1(t_token *token)
{
	return (list(token));
}

t_astnode	*complete_command2(t_token *token)
{
	t_astnode *node;
	t_astnode *lnode;

	if ((lnode = list()) == NULL)
		return (NULL);
	if (token->data)
}

t_astnode	*complete_command(t_token *token)
{
	t_astnode_type *node;

	if ((node = complete_command1(token)) != NULL)
		return (node);
	if ((node = complete_command2(token)) != NULL)
		return (node);
	return (NULL);
}