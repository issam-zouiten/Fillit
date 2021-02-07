/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:02:56 by izouiten          #+#    #+#             */
/*   Updated: 2019/10/10 18:33:42 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_t_n(t_node *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		check_valid_form(char *buffer)
{
	char	**tab;
	t_point p;
	int		count;

	count = 0;
	p.i = -1;
	tab = ft_strsplit(buffer, '\n');
	while (tab[++(p.i)])
	{
		p.j = -1;
		while (tab[p.i][++(p.j)])
			if (tab[p.i][p.j] == '#')
			{
				if (p.j + 1 < 4 && tab[p.i][p.j + 1] == '#')
					count++;
				if (p.j - 1 >= 0 && tab[p.i][p.j - 1] == '#')
					count++;
				if (p.i + 1 < 4 && tab[p.i + 1][p.j] == '#')
					count++;
				if (p.i - 1 >= 0 && tab[p.i - 1][p.j] == '#')
					count++;
			}
	}
	free_table(tab);
	return (count == 6 || count == 8);
}

int		check_counts(char *buffer, int ret)
{
	int	i;
	int j;
	int z;
	int n;

	i = -1;
	j = 0;
	z = 0;
	n = 0;
	while (buffer[++i] != '\0' && ret != 0)
	{
		if (buffer[i] == '.')
			j++;
		else if (buffer[i] == '#')
			z++;
		else if (i == 4 || i == 9 || i == 14)
		{
			if (buffer[i] == '\n')
				n++;
		}
		else if (buffer[i] != '.' || buffer[i] != '#' || buffer[i] != '\n')
			return (0);
	}
	return (j == 12 && z == 4 && n == 3);
}

void	t_shift(t_node **lst)
{
	int i;
	int j;

	i = 4;
	(*lst)->x = 3;
	(*lst)->y = 3;
	while ((*lst)->data[--i] && i >= 0)
	{
		j = 4;
		while ((*lst)->data[i][--j] && j >= 0)
			if ((*lst)->data[i][j] == '#')
			{
				if (i < (*lst)->y)
					(*lst)->y = i;
				if (j < (*lst)->x)
					(*lst)->x = j;
			}
	}
}

void	free_table(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
