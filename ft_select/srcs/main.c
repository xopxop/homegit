/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:13:54 by dthan             #+#    #+#             */
/*   Updated: 2020/05/22 17:28:12 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	init_custom_config(t_terminal *term)
{
	int		ret;

	term->termtype = getenv("TERM");
	tgetent(term->term_buffer, term->termtype);
	tcgetattr(STDERR_FILENO, &term->term_attributes);
	tcgetattr(STDERR_FILENO, &term->old_attributes);
	term->term_attributes.c_lflag &= ~(ICANON | ECHO);
	term->term_attributes.c_cc[VMIN] = 1;
	term->term_attributes.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &term->term_attributes);
	tputs(tgetstr("ti", NULL), 1, char_to_term);
	tputs(tgetstr("vi", NULL), 1, char_to_term);
}

void		init_elems(t_select *select, char **input)
{
	t_lst *head;
	t_lst *prev_node;
	t_lst *new_node;

	head = ft_creat_elem((*input));
	head->elem.position = true;
	prev_node = head;
	input++;
	while (*input)
	{
		new_node = ft_creat_elem(*input);
		new_node->previous = prev_node;
		prev_node->next = new_node;
		prev_node = new_node;
		input++;
	}
	select->head = head;
	select->last = prev_node;
}

static void	on_key_press(t_select *select)
{
	char	buf[5];

	while (true)
	{
		ft_bzero(buf, 5);
		ft_display(select);
		read(STDIN_FILENO, buf, 5);
		if (ESCAPE_KEY(buf))
			exit(EXIT_SUCCESS);
		else if (SPACE_KEY(buf))
			ft_space_key(select->head);
		else if (ENTER_KEY(buf))
			break ;
		else if (BACKSPACE_KEY(buf) || DELETE_KEY(buf))
			ft_remove_elem(&select->head);
		else
			ft_move(select, buf);
	}
}

static void	restore_old_term_config(t_select select)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &select.term.old_attributes);
	tputs(tgetstr("ve", NULL), 1, char_to_term);
	tputs(tgetstr("te", NULL), 1, char_to_term);
}

static void	send_selected_choices_to_the_shell(t_lst *head)
{
	char	*selected_elem[count_selected_elem(head) + 1];
	int		i;

	i = 0;
	while (head)
	{
		if (head->elem.selected == true)
			selected_elem[i++] = head->elem.av;
		head = head->next;
	}
	selected_elem[i] = NULL;
	i = -1;
	while (selected_elem[++i] != NULL)
	{
		if (selected_elem[i + 1] == NULL)
			ft_putstr_fd(selected_elem[i], STDOUT_FILENO);
		else
			ft_dprintf(STDOUT_FILENO, "%s ", selected_elem[i]);
	}
}

static void	ft_select(char **av)
{
	t_select	select;

	init_custom_config(&select.term);
	init_elems(&(select), av);
	on_key_press(&select);
	restore_old_term_config(select);
	send_selected_choices_to_the_shell(select.head);
	free_elems(&select.head, &select.last);
}

int			main(int ac, char **av)
{
	if (ac > 1)
		ft_select(&av[1]);
	else
		ft_putstr_fd("Print usage!\n", STDERR_FILENO);
	return (EXIT_SUCCESS);
}
