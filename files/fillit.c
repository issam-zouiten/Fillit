/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:47:52 by izouiten          #+#    #+#             */
/*   Updated: 2019/10/10 18:31:22 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	t_solve(t_node *lst)
{
	char	**tab;
	int		size;

	size = t_len(lst);
	if ((tab = set_tab(size)))
	{
		while (!ft_solve_tet(tab, lst, 0))
		{
			free_table(tab);
			tab = set_tab(++size);
		}
		print_table(tab);
		free_table(tab);
	}
}

int		t_read(int fd, t_node *lst)
{
	int		ret;
	int		ret2;
	char	buffer[20];
	int		i;

	ret2 = 0;
	i = 0;
	while ((ret = read(fd, buffer, 19)) > 0)
	{
		buffer[ret] = '\0';
		if (!(check_counts(buffer, ret)) || !(check_valid_form(buffer)))
			return (0);
		if (i > 0)
		{
			lst->next = malloc_node();
			lst = lst->next;
		}
		lst->data = ft_strsplit(buffer, '\n');
		t_shift(&lst);
		ft_bzero(buffer, 20);
		ret2 = read(fd, buffer, 2);
		ft_bzero(buffer, 2);
		i++;
	}
	return (ret2 == 1 && ret == 0);
}

t_node	*malloc_node(void)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->next = NULL;
	node->data = NULL;
	return (node);
}

void	free_nodes(t_node **head)
{
	t_node	*node;
	t_node	*tmp;
	int		i;

	node = *head;
	while (node)
	{
		i = -1;
		tmp = node->next;
		if (node->data)
		{
			while (node->data[++i])
				free(node->data[i]);
			free(node->data);
		}
		free(node);
		node = tmp;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	t_node	*head;
	char	str[1];

	if (argc == 2)
	{
		head = malloc_node();
		if ((fd = open(argv[1], O_RDONLY)) != -1 && read(fd, str, 0) != -1
		&& t_read(fd, head) && check_t_n(head) < 27)
			t_solve(head);
		else
			ft_putendl("error");
		free_nodes(&head);
	}
	else
		ft_putendl("Usage: fillit <filename>");
	return (0);
}
