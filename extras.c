/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:07:10 by kcowle            #+#    #+#             */
/*   Updated: 2016/07/18 14:23:22 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_isbuiltin(t_env *env, char *line)
{
	char	**line2;
	int		i;
	t_main w;

	i = 0;
	line2 = ft_strsplit(line, ' ');
	if (ft_strcmp(line2[0], "echo") == 0 && (i = 1))
	{
		line = ft_strfcut(line, 5);
		ft_echo(line);
	}
	else if (ft_strncmp(line, "cd", 2) == 0 && (i = 1))
		ft_cd(line);
	else if (ft_strncmp(line, "unsetenv", 7) == 0 && (i = 1))
		env = ft_unsetenv(env);
	else if (ft_strncmp(line, "env", 2) == 0 && (i = 1))
		print_env(env);
	else if (ft_strncmp(line, "setenv", 5) == 0 && (i = 1))
	{
		line = ft_strrw(line);
		line2 = ft_strsplit(line, ' ');
		env = set_env(line2, env);
	}
	if (i == 1)
		ft_doublecoms(env, &w, 0);
	return (1);
}

t_env	ft_excecute(char **line2, int comcount, t_env *env)
{
	int		i;
	int		ret;
	char	*newline;

	newline = (char *)malloc(sizeof(char *) * \
			(sizeof(env->path) + sizeof(line2[0]) + 1));
	ft_strcpy(newline, env->path);
	env->cmd = (char **)malloc(sizeof(char **) * 5);
	env->cmd[0] = (char *)malloc(sizeof(char *) * \
			(sizeof(newline) + sizeof(line2[0]) + 1));
	ft_strcpy(env->cmd[0], strcat(newline, line2[0]));
	env->args = (char **)malloc(sizeof(char **) * comcount);
	i = 0;
	while (i < comcount)
	{
		env->args[i] = (char *)malloc(sizeof(char *) * ft_strlen(line2[i]) + 1);
		ft_strcpy(env->args[i], line2[i]);
		i++;
	}
	env->args[i] = NULL;
	ret = execve(env->cmd[0], env->args, env->env);
	return (*env);
}

char	*gethome(void)
{
	char		*home;
	int			i;
	extern char	**environ;

	i = 0;
	home = NULL;
	while (environ[i] != NULL)
	{
		if (ft_strncmp(environ[i], "HOME=", 5) == 0)
		{
			home = (char *)malloc(sizeof(char *) * (ft_strlen(environ[i]) + 1));
			ft_strcpy(home, environ[i]);
			home = ft_strnshift(home, 5);
			break ;
		}
		i++;
	}
	return (home);
}

void	ft_cd(char *line)
{
	int			i;
	char		*tmp;
	char		*home;

	i = 0;
	home = gethome();
	tmp = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 1));
	ft_strcpy(tmp, line);
	tmp = ft_strrw(tmp);
	tmp = ft_strnshift(tmp, 3);
	i = 0;
	if (tmp[0] == '~')
	{
		tmp = ft_strnshift(tmp, 1);
		while (tmp[0] == '/')
			tmp = ft_strnshift(tmp, 1);
		home = ft_strjoin(home, "/");
		home = ft_strjoin(home, tmp);
		if (chdir(home) == -1)
			ft_putstr("No such file or directory.\n");
	}
	else if (chdir(tmp) == -1)
		ft_putstr("No such file or directory.\n");
}

t_env	get_dir(t_env *env, char **line)
{
	struct dirent	*pdirent;
	DIR				*pdir;
	char			*linel;
	char			**line2;
	int				i;
	char			**tdir;

	linel = get_path(env);
	ft_strcpy(linel, ft_strfcut(linel, 5));
	line2 = ft_strsplit(linel, ':');
	i = -1;
	if (line[0][0] == '/')
	{
		tdir = ft_strsplit(line[0], '/');
		env->path = (char *)malloc(sizeof(char *) * ft_strlen(tdir[0]));
		env->path[0] = '/';
		ft_strcat(env->path, tdir[0]);
		ft_strcat(env->path, "/");
		return (*env);
	}
	while (line2[++i] != NULL && ft_strcpy(line2[i], ft_strcat(line2[i], "/")))
	{
		pdir = opendir(line2[i]);
		while (pdir != NULL && (pdirent = readdir(pdir)) != NULL)
			if (ft_strcmp(pdirent->d_name, line[0]) == 0)
			{
				env->path = (char *)malloc(sizeof(char *) \
						* ft_strlen(line2[i]) + 1);
				ft_strcpy(env->path, line2[i]);
				ft_putstr(env->path);
				ft_putchar('\n');
				return (*env);
			}
	}
	ft_putstr(line[0]);
	ft_putstr(": command not found.\n");
	return (*env);
}
