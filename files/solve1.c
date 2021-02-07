/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:12:23 by izouiten          #+#    #+#             */
/*   Updated: 2019/10/10 18:35:53 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		t_is_safe(char **tab, int x, int y, t_node *lst)
{
	int		tx;
	int		ty;
	int		xx;
	int		k;

	ty = lst->y;
	xx = x;
	k = 0;
	while (lst->data[ty] && tab[y])
	{
		tx = lst->x;
		x = xx;
		while (lst->data[ty][tx] && tab[y][x])
		{
			if (tab[y][x] == '.' && lst->data[ty][tx] == '#')
				k++;
			x++;
			tx++;
		}
		y++;
		ty++;
	}
	return (k == 4);
}

void	t_set(char **tab, t_point spec, t_node *lst, int al)
{
	int		tx;
	int		ty;
	int		xx;
	int		k;

	ty = lst->y - 1;
	k = 0;
	xx = spec.j;
	spec.i -= 1;
	while (lst->data[++(ty)] && tab[++(spec.i)])
	{
		tx = lst->x - 1;
		spec.j = xx - 1;
		while (lst->data[ty][++(tx)] && tab[spec.i][++(spec.j)])
			if (tab[spec.i][spec.j] == '.' && lst->data[ty][tx] == '#'
					&& k++ < 4)
				tab[spec.i][spec.j] = 'A' + al;
	}
}

void	remove_tet(char **tab, int al)
{
	int i;
	int j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
		{
			if (tab[i][j] == 'A' + al)
				tab[i][j] = '.';
		}
	}
}
