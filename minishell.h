/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcowle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 14:07:10 by kcowle            #+#    #+#             */
/*   Updated: 2016/07/18 17:25:22 by kcowle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "libft/libft.h"
# include <dirent.h>
# include <libc.h>

typedef struct	s_env
{
	char		*path;
	char		**cmd;
	char		**args;
	char		**env;
	char		**enviro;
	char		**envirobk;
	int			cont;
	int			i;
}				t_env;

typedef struct	s_echo
{
	int			state;
	int			state2;
	int			newline;
	char		**line2;
	int			e;
	int			o;
	int			i;
}				t_echo;

typedef struct	s_main
{
	char		*line;
	char		**line2;
	int			comcount;
}				t_main;

void			ft_doublecoms(t_env *env, t_main *w, int read);
void			ft_echo(char *line);
char			*get_path(t_env *env);
t_env			*set_env(char **line2, t_env *env);
t_env			*ft_unsetenv(t_env *env);
int				ft_isbuiltin(t_env *env, char *line);
void			ft_cd(char *line);
t_env			get_dir(t_env *env, char **line);
void			ft_minishell(t_env *env, t_main m);
void			print_env(t_env *env);
t_env			ft_excecute(char **line2, int comcount, t_env *env);
int				oct_dec(int n);
void			ft_printoct(char *line, int *i);
void			ft_handle2(char *line, t_echo *ec);
int				ft_handle1(char *line, char **line2, int *e, int *o);
void			ft_handle3(t_echo *ec, char *line);
void			init_echo(char *line, t_echo *ec);
int				ft_pow(int i, int x);
#endif
