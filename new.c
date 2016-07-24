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

void	ft_doublecoms(t_env *env, t_main *w, int input)
{
	char **coms;
	int y;
	int i;
	int	fd[2];
	ssize_t	bytes;
	char 	*bytes_read;
	char	*br;
	char	*temp;

	y = 0;
	i = 0;
	ft_putstr("<<^>>: ");
	if (input != 1)
		get_next_line(0, &w->line);
	if (ft_strchr(w->line, ';') == 0 && ft_strchr(w->line, '|') == 0 && ft_strchr(w->line, '>') == 0)
	{
		ft_minishell(env, *w);
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
	else if (ft_strchr(w->line, '>') != 0)
	{
		coms = ft_strsplit(w->line, '>');
		fd[0] = open(ft_strrw(coms[1]), O_RDWR|O_CREAT, 0666);
		if (fd[0] < 0)
		{
			//Error
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
	else if (ft_strchr(w->line, '<') != 0)
	{
		coms = ft_strsplit(w->line, '<');
		fd[0] = open(ft_strrw(coms[1]), O_RDWR);
		if (fd[0] == -1)
		{
			ft_putstr("File doesn't exist or cannot be opened.\n");
			ft_strcpy(w->line, " ");
			ft_minishell(env, *w);
		}
		else{
			bytes_read = ft_strnew(BYTE_SIZE);
			br = ft_strnew(BYTE_SIZE);
			temp = ft_strnew(BYTE_SIZE);
			while ((bytes = read(fd[0], bytes_read, BYTE_SIZE)) != 0)
			{
				br = ft_strnew((size_t) (ft_strlen(temp) + bytes));
				ft_strcpy(br, temp);
				ft_strcat(br, bytes_read);
				temp = ft_strnew((size_t) ft_strlen(br));
				ft_strcpy(temp, br);
			}
			free(temp);
			free(bytes_read);
			ft_putstr(br);
			fd[1] = dup(STDIN_FILENO);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
			ft_strcpy(w->line, br);
			ft_minishell(env, *w);
			dup2(fd[1], STDIN_FILENO);
			close(fd[1]);
		}
	}
	env->cont == 1 ? *env : ft_doublecoms(env, w, 0);
}
