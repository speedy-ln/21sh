/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 10:26:15 by kcowle            #+#    #+#             */
/*   Updated: 2016/07/18 17:47:39 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_doublecoms(t_env *env, t_main *w, int read)
{
	char **coms;
	int y;
	int i;
	int	fd;

	y = 0;
	i = 0;
	ft_putstr("<<^>>: ");
	if (read != 1)
		get_next_line(0, &w->line);
	if (ft_strchr(w->line, ';') == 0 && ft_strchr(w->line, '|') == 0 && ft_strchr(w->line, '>') == 0)
	{
		ft_minishell(env, *w);
		ft_putstr(env->path);
		ft_putchar('\n');
	}
	else if (ft_strchr(w->line, '|') == 0 && ft_strchr(w->line, '>') == 0)
	{
		coms = ft_strsplit(w->line, ';');
		while (coms[y] != NULL)
		{
			w->line = coms[y];
			ft_minishell(env, *w);
			y++;
		}
	}
	else if (ft_strchr(w->line, '>') != 0) {
		coms = ft_strsplit(w->line, '>');
		open(ft_strrw(coms[1]), O_CREAT);
		fd = open(ft_strrw(coms[1]), O_RDWR);
		ft_putstr(ft_strrw(coms[1]));
		ft_putchar('\n');
		close(fd);
//		coms[y];
//		fd = open();
	}
	env->cont == 1 ? *env : ft_doublecoms(env, w, 0);
}
