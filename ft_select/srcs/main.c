/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:13:54 by dthan             #+#    #+#             */
/*   Updated: 2020/07/16 02:43:27 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	init_custom_config(t_terminal *term)
{
	term->termtype = getenv("TERM");
	tgetent(term->term_buffer, term->termtype);
	tcgetattr(STDERR_FILENO, &term->new_attributes);
	tcgetattr(STDERR_FILENO, &term->old_attributes);
	term->new_attributes.c_lflag &= ~(ICANON | ECHO);
	term->new_attributes.c_cc[VMIN] = 1;
	term->new_attributes.c_cc[VTIME] = 0;
	tcsetattr(STDERR_FILENO, TCSANOW, &term->new_attributes);
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

void	restore_old_term_config(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &g_select.term.old_attributes); // need to put to std_err
	tputs(tgetstr("ve", NULL), 1, char_to_term);
	tputs(tgetstr("te", NULL), 1, char_to_term);
}

void	signal_handler(int signo)
{
	if (signo == SIGTSTP)
	{
		restore_old_term_config();
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, CTRL_Z);
	}
	else if (signo == SIGCONT)
	{
		init_custom_config(&g_select.term);
		signal_initialization();
		ft_display();
	}
}

void	signal_initialization(void)
{
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
}

static void	on_key_press(void)
{
	char	buf[5];

	while (true)
	{
		ft_bzero(buf, 5);
		ft_display();
		read(STDERR_FILENO, buf, 5);
		if (ESCAPE_KEY(buf))
		{
			restore_old_term_config();
			// free_elems(&select->head, &select->last);
			exit(EXIT_SUCCESS);
		}
		else if (SPACE_KEY(buf))
			ft_space_key(g_select.head);
		else if (ENTER_KEY(buf))
			break ;
		else if (BACKSPACE_KEY(buf) || DELETE_KEY(buf))
			ft_remove_elem(&g_select.head);
		else
			ft_move(buf);
	}
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
	init_custom_config(&g_select.term);
	init_elems(&(g_select), av);
	signal_initialization();
	on_key_press();
	restore_old_term_config();
	send_selected_choices_to_the_shell(g_select.head);
	free_elems(&g_select.head, &g_select.last);
}

int			main(int ac, char **av)
{
	if (ac > 1)
		ft_select(&av[1]);
	else
		ft_putstr_fd("Print usage!\n", STDERR_FILENO);
	return (EXIT_SUCCESS);
}
