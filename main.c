/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:07:10 by kcowle            #+#    #+#             */
/*   Updated: 2016/07/18 17:25:55 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

void	print_env(t_env *env)
{
	int i;

	i = 0;
	while (env->enviro[i] != NULL)
	{
		ft_putstr(env->enviro[i]);
		ft_putchar('\n');
		i++;
	}
}

t_env	*set_env(char **line2, t_env *env)
{
	int i;

	i = 1;
	while (line2[1] && env->enviro[i] != NULL)
	{
		if (ft_strncmp(line2[1], env->enviro[i], 4) == 0)
		{
			env->enviro[i] = (char *)malloc(sizeof(char *) *\
					ft_strlen(line2[1]));
			ft_strcpy(env->enviro[i], line2[1]);
			return (env);
		}
		i++;
	}
	ft_putstr("env variable \"");
	ft_putstr(line2[1]);
	ft_putstr("\" not found.\n");
	return (env);
}

t_env	*ft_unsetenv(t_env *env)
{
	int i;

	i = 0;
	while (env->envirobk[i] != NULL)
	{
		ft_strcpy(env->enviro[i], env->envirobk[i]);
		i++;
	}
	return (env);
}

void	ft_minishell(t_env *env, t_main m)
{
	pid_t	father;
	int i;
	int n;
	int w;

		if (m.line[0] != '\0')
		{
			ft_isbuiltin(env, m.line);
			m.comcount = 0;
			father = fork();
			if (father != 0)
				wait(NULL);
			else
			{
				if (ft_strcmp(m.line, "exit") == 0)
					kill(father, SIGTERM);
				m.line = ft_strtrim(m.line);
				m.line2 = ft_strsplit(m.line, ' ');
				while (m.line2[m.comcount] != NULL)
					m.comcount++;
				*env = get_dir(env, m.line2);
				if (m.line2[0][0] == '/')
				{
					i = 0;
					n = 1;
					w = n;
					while (m.line2[0][n] != '/')
					{
						m.line2[0][i] = m.line2[0][n];
						while (m.line2[0][w] != '\0')
						{
							m.line2[0][n++] = m.line2[0][w++];
						}
						m.line2[0][n] = '\0';
						n = 0;
						w = 1;
					}
					while (m.line2[0][w] != '\0')
					{
						m.line2[0][n++] = m.line2[0][w++];
					}
					m.line2[0][n] = '\0';
				}
					*env = ft_excecute(m.line2, m.comcount, env);
			}
		}
}

int		main(void)
{
	t_env			env;
	extern char		**environ;
	int				i;
	int				n;
	t_main			w;

	n = 0;
	i = 0;
	while (environ[i] != NULL)
		i++;
	env.enviro = (char **)malloc(sizeof(char **) * i + 1);
	env.envirobk = (char **)malloc(sizeof(char **) * i + 1);
	while (n < i)
	{
		env.enviro[n] = (char *)malloc(sizeof(char *) * ft_strlen(environ[n]));
		env.envirobk[n] = (char *)malloc(sizeof(char *) *\
				ft_strlen(environ[n]));
		ft_strcpy(env.enviro[n], environ[n]);
		ft_strcpy(env.envirobk[n], environ[n]);
		n++;
	}
	ft_doublecoms(&env, &w, 2);
	return (0);
}
