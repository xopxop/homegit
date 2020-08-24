#include "line_edition.h"

void insertChar(t_line *line, int c)
{
	char *new;

	new = ft_strnew(ft_strlen(line->str) + 1);
	new = ft_strcpy(new, line->str);
	ft_memmove(&new[E.cursor.atLine + 1], &new[E.cursor.atLine], line->len - E.cursor.atLine + 1);
	new[E.cursor.atLine] = c;
	free(line->str);
	line->str = new;
	line->len++;
	E.cursor.atLine++;
}

void delChar(t_line *line)
{
	char *new;

	ft_memmove(&line->str[E.cursor.atLine - 1], &line->str[E.cursor.atLine], line->len - E.cursor.atLine + 1);
	new = ft_strdup(line->str);
	free(line->str);
	line->str = new;
	line->len--;
}
