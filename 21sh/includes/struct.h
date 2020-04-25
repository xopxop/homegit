/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 07:58:26 by dthan             #+#    #+#             */
/*   Updated: 2020/04/07 07:58:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum			e_type{
	T_WORD,
	T_PIPE,
	T_SEMI,
	// T_ASSIGNMENT_WORD,
	// T_NAME,
	// T_NEWLINE,
	// T_IO_NUMBER,
	/* The following are the operators mentioned above.
	%token  AND_IF    OR_IF    DSEMI
             '&&'      '||'     ';;'  
	%token  DLESS  DGREAT  LESSAND  GREATAND  LESSGREAT  DLESSDASH
	        '<<'   '>>'    '<&'     '>&'      '<>'       '<<-'   
	%token  CLOBBER
	         '>|'       */
	// T_AND_IF,
	// T_OR_IF,
	// T_DSEMI,
	// T_DLESS,
	// T_DGREAT,
	// T_LESSAND,
	// T_GREATAND,
	// T_LESSGREAT,
	// T_DLESSDASH,
	// T_CLOBBER,
	/* The following are the reserved words. 
	%token  If    Then    Else    Elif    Fi    Do    Done
           'if'  'then'  'else'  'elif'  'fi'  'do'  'done'  
	%token  Case    Esac    While    Until    For
	       'case'  'esac'  'while'  'until'  'for'   */
	// T_If,
	// T_Then,
	// T_Else,
	// T_Elif,
	// T_Fi,
	// T_Do,
	// T_Done,
	// T_Case,
	// T_Esac,
	// T_While,
	// T_Until,
	// T_For,
	/* These are reserved words, not operator tokens, and are
   recognized when reserved words are recognized.
	%token  Lbrace    Rbrace    Bang
			'{'       '}'       '!'  */
	// T_Lbrace,
	// T_Rbrace,
	// T_Bang,
}						t_type;

typedef struct			s_token
{
	char				*data;
	t_type				type;
	int					pos_args;
	struct s_token		*next;
}						t_token;

typedef struct			s_cmd
{
	t_token				*token;
	char				**argv;
	int					argc;
	struct s_cmd		*next;
}						t_cmd;

typedef struct			s_builtin
{
	char				*command;
	void				(*func)(char**);
}						t_builtin;

#endif
