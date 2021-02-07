/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:42:10 by izouiten          #+#    #+#             */
/*   Updated: 2019/10/10 18:35:01 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		t_len(t_node *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (ft_sqrt(i * 4));
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

char	**set_tab(int nb)
{
	char	**tab;
	int		i;

	if (!(tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	tab[nb] = NULL;
	i = nb;
	while (--i >= 0)
	{
		if (!(tab[i] = (char *)malloc(sizeof(char) * (nb + 1))))
			return (NULL);
		tab[i][nb] = '\0';
		ft_memset(tab[i], '.', nb);
	}
	return (tab);
}

int		ft_solve_tet(char **tab, t_node *tet, int al)
{
	t_point it;

	if (!tet)
		return (1);
	it.i = -1;
	while (tab[++(it.i)])
	{
		it.j = -1;
		while (tab[it.i][++(it.j)])
		{
			if (t_is_safe(tab, it.j, it.i, tet))
			{
				t_set(tab, it, tet, al);
				if (ft_solve_tet(tab, tet->next, al + 1))
					return (1);
				else
					remove_tet(tab, al);
			}
		}
	}
	return (0);
}

void	print_table(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}
