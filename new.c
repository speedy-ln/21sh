/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 10:26:15 by kcowle            #+#    #+#             */
/*   Updated: 2016/08/02 16:15:06 by lnkadime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirection_gt(t_main *w, t_env *env, int append)
{
	int 	fd[2];
	char	**coms;

	coms = ft_strsplit(w->line, '>');
	if (append == 1)
	{
		fd[0] = open(ft_strrw(coms[1]), O_RDWR|O_CREAT|O_APPEND, 0666);
	}
	else
		fd[0] = open(ft_strrw(coms[1]), O_RDWR|O_CREAT, 0666);
	if (fd[0] < 0)
	{
		ft_strcpy(w->line, " ");
		ft_minishell(env, *w);
	}
	else {
		fd[1] = dup(STDOUT_FILENO);
		dup2(fd[0], STDOUT_FILENO);
		close(fd[0]);
		ft_strcpy(w->line, coms[0]);
		ft_minishell(env, *w);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
	}
}

void	redirection_lt(t_main *w, t_env *env)
{
	char	**coms;
	int 	fd[2];

	coms = ft_strsplit(w->line, '<');
	fd[0] = open(ft_strrw(coms[1]), O_RDWR);
	if (fd[0] == -1)
	{
		ft_putstr("File doesn't exist or cannot be opened.\n");
		ft_strcpy(w->line, " ");
		ft_minishell(env, *w);
	}
	else
	{
		//w->line = ft_strnew((size_t) ((ft_strlen(w->line) + ft_strlen(br)) + 1));
		w->line = ft_strnew((size_t) (ft_strlen(w->line) + 1));
		fd[1] = dup(STDIN_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ft_strcpy(w->line, coms[0]);
		ft_minishell(env, *w);
		dup2(fd[1], STDIN_FILENO);
		close(fd[1]);
	}
}

void	ft_doublecoms(t_env *env, t_main *w, int input)
{
	char **coms;
	int y;
	int i;
	int	append;

	y = 0;
	i = 0;
	append = 0;
	ft_putstr("<<^>>: ");
	if (input != 1)
		get_next_line(0, &w->line);
	if (ft_strchr(w->line, '<') == 0 && ft_strchr(w->line, ';') == 0 && ft_strchr(w->line, '|') == 0 && ft_strchr(w->line, '>') == 0)
		ft_minishell(env, *w);
	else if (ft_strchr(w->line, '<') == 0 && ft_strchr(w->line, '|') == 0 && ft_strchr(w->line, '>') == 0)
	{
		coms = ft_strsplit(w->line, ';');
		while (coms[y] != NULL)
		{
			w->line = coms[y];
			ft_minishell(env, *w);
			y++;
		}
	}
	else if (ft_strchr(w->line, '>') != 0)
	{
		if (ft_findstr(">>", w->line))
			append = 1;
		redirection_gt(w, env, 1);
	}
	else if (ft_strchr(w->line, '<') != 0)
	{
		redirection_lt(w, env);
	}
	env->cont == 1 ? *env : ft_doublecoms(env, w, 0);
}
