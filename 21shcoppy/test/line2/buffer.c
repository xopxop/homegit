#include "line_edition.h"

void abAppend(t_buffer *ab, char *s) {
	ab->str = ft_strjoin_and_free_string1(ab->str, s);
	ab->len = ft_strlen(ab->str);
}

void abFree(t_buffer *ab) {
	free(ab->str);
}