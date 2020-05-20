/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 01:13:54 by dthan             #+#    #+#             */
/*   Updated: 2020/05/20 09:43:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"
#include <term.h>

int		ft_finding_longest_elem(t_lst *lst)
{
	int maxsize;
	int size;

	maxsize = 0;
	while (lst)
	{
		if (maxsize < lst->elem.max_length)
			maxsize = lst->elem.max_length;
		lst = lst->next;
	}
	return (maxsize);
}

void	ft_print_output(t_lst *lst, t_terminal term, int width_col)
{
	int i;
	int j;
	t_lst	*current;

	i = -1;
	j = 0;
	while (++i < term.rows && lst != NULL)
	{
		j = -1;
		while (++j < term.cols && lst != NULL)
		{
			if (lst->elem.position == true)
				ft_printf("%s", tgetstr("us", NULL));
			if (lst->elem.selected == true)
				ft_printf("%s", tgetstr("mr", NULL));
			ft_printf("%s%*s", lst->elem.av, width_col - lst->elem.max_length, "");
			// if (lst->elem.position == true)
			// 	ft_printf("%s", tgetstr("ue", NULL));
			if (lst->elem.selected == true || lst->elem.position == true)
				ft_printf("%s", tgetstr("me", NULL));
			lst = lst->next;
		}
		ft_putchar('\n');
	}
}

int		char_to_term(int c)
{
	return (write(1, &c, 1));
}

int		ft_count_elems(t_lst *lst)
{
	int ct;

	ct = 0;
	while (lst)
	{
		lst = lst->next;
		ct++;
	}
	return (ct);
}

void	ft_display(t_select *select)
{
	struct winsize w;
	int input_size;
	int width_col;

	tputs(tgetstr("cl", NULL), 1, char_to_term); 
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	input_size = ft_count_elems(select->head);
	width_col = (ft_finding_longest_elem(select->head) + 1);
	select->term.cols = w.ws_col / width_col;
	select->term.rows = (input_size == select->term.cols) ? 1 : (input_size / select->term.cols) + 1;
	ft_print_output(select->head, select->term, width_col);
}

void	init_custom_config(t_terminal *term)
{
	int		ret;

	term->termtype = getenv("TERM");
	tgetent(term->term_buffer, term->termtype);
	tcgetattr(STDOUT_FILENO, &term->term_attributes);
	term->term_attributes.c_lflag &= ~(ICANON | ECHO);
	term->term_attributes.c_cc[VMIN] = 1;
	term->term_attributes.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term->term_attributes);
	tputs(tgetstr("ti", NULL), 1, char_to_term);
	tputs(tgetstr("vi", NULL), 1, char_to_term);
}

void	moveRight(t_lst *head)
{
	t_lst *curr;

	curr = head;
	while(curr->next)
	{
		if (curr->elem.position == true)
		{
			curr->elem.position = false;
			curr->next->elem.position = true;
			return ;
		}
		curr = curr->next;
	}
	curr->elem.position = false;
	head->elem.position = true;
}

void	moveLeft(t_lst *last)
{
	t_lst *curr;

	curr = last;
	while(curr->previous)
	{
		if (curr->elem.position == true)
		{
			curr->elem.position = false;
			curr->previous->elem.position = true;
			return ;
		}
		curr = curr->previous;
	}
	curr->elem.position = false;
	last->elem.position = true;
}

void	moveDown(t_lst *head)
{
	t_lst *curr_position;
	int able_to_move_down;
	int cols;
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	cols = w.ws_col / (ft_finding_longest_elem(head) + 1);
	able_to_move_down = -1;
	while (head->next)
	{
		if (head->elem.position == true)
		{
			curr_position = head;
			while (++able_to_move_down < cols && head->next)
				head = head->next;
			if ((able_to_move_down == cols) == true)
			{
				curr_position->elem.position = false;
				head->elem.position = true;
			}
			return ;
		}
		else
			head = head->next;
	}
}

void	moveUp(t_lst *last, t_lst *head)
{
	t_lst *curr_position;
	int able_to_move_up;
	int cols;
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	cols = w.ws_col / (ft_finding_longest_elem(head) + 1);
	able_to_move_up = -1;
	while (last->previous)
	{
		if (last->elem.position == true)
		{
			curr_position = last;
			while (++able_to_move_up < cols && last->previous)
				last = last->previous;
			if ((able_to_move_up == cols) == true)
			{
				curr_position->elem.position = false;
				last->elem.position = true;
			}
			return ;
		}
		else
			last = last->previous;
	}
}

void	ft_move(t_select *select, char *buf)
{
	if (UPWARDS_ARROW(buf))
	{
		ft_printf("UPWARDS_ARROW PRESS\n");
		moveUp(select->last, select->head);
	}
	else if (DOWNWARDS_ARROW(buf))
	{
		ft_printf("DOWNWARDS_ARROW PRESS\n");
		moveDown(select->head);
	}
	else if (RIGHTWARDS_ARROW(buf))
	{
		ft_printf("RIGHTWARDS_ARROW PRESS\n");
		moveRight(select->head);
	}
	else if (LEFTWARDS_ARROW(buf))
	{
		ft_printf("LEFTWARDS_ARROW PRESS\n");
		moveLeft(select->last);
	}
}

void	ft_space_key(t_lst *head)
{
	while (head->next)
	{
		if (head->elem.position == true)
		{
			head->elem.selected = (head->elem.selected == false) ? true : false;
			return ;
		}
		else
			head = head->next;
	}
	head->elem.selected = (head->elem.selected == false) ? true : false;
}

void	on_key_press(t_select *select)
{
	char	buf[4];

	while (true)
	{
		ft_bzero(buf, 4);
		ft_display(select);
		read(STDIN_FILENO, buf, 100);
		if (buf[0] == SPACE_KEY)
			ft_space_key(select->head);
		else if (buf[0] == 27 && buf[1] == 0 && buf[2] == 0)
			ft_printf("ESCAPE KEY PRESSED\n");
		else
			ft_move(select, buf);
	}
}

t_lst	*ft_creat_elem(char *input)
{
	t_lst *node;

	node = (t_lst*)malloc(sizeof(t_lst));
	node->elem.av = input;
	node->elem.max_length = ft_strlen(input);
	node->elem.selected = false;
	node->elem.position = false;
	node->next = NULL;
	node->previous = NULL;
	return (node);
}

void	init_elems(t_select *select, char **input)
{
	t_lst *head;
	t_lst *prevNode;
	t_lst *newNode;

	head = ft_creat_elem((*input));
	head->elem.position = true;
	prevNode = head;
	input++;
	while (*input)
	{
		newNode = ft_creat_elem(*input);
		newNode->previous = prevNode;
		prevNode->next = newNode;
		prevNode = newNode;
		input++;
	}
	select->head = head;
	select->last = prevNode;
}

void	ft_select(char **av)
{
	t_select	select;
	
	init_custom_config(&select.term);
	init_elems(&(select), av);
	on_key_press(&select);
}

int	main(int ac, char **av)
{
	if (ac > 1)
		ft_select(&av[1]);
	else
		ft_putstr("Print usage!\n"); //print usage
	return (EXIT_SUCCESS);
}