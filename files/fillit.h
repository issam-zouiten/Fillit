/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izouiten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:55:49 by izouiten          #+#    #+#             */
/*   Updated: 2019/10/10 18:23:26 by izouiten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_node
{
	char			**data;
	int				x;
	int				y;
	struct s_node	*next;
}					t_node;

typedef struct		s_point
{
	int				i;
	int				j;
}					t_point;

int					check_valid_form(char *buffer);
int					check_counts(char *buffer, int ret);
void				t_shift(t_node **lst);
int					t_read(int fd, t_node *lst);
t_node				*malloc_node(void);
void				t_solve(t_node *lst);
int					t_len(t_node *lst);
int					ft_sqrt(int nb);
char				**set_tab(int nb);
int					ft_solve_tet(char **tab, t_node *tet, int al);
void				print_table(char **tab);
int					t_is_safe(char **tab, int x, int y, t_node *lst);
void				t_set(char **tab, t_point spec, t_node *lst, int al);
void				remove_tet(char **tab, int al);
void				free_table(char **tab);
void				free_nodes(t_node **head);
int					check_t_n(t_node *node);

#endif
