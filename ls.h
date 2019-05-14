/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 12:57:29 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/05 06:56:54 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "stdio.h"
#include "errno.h"
#include "dirent.h"
#include "./libft/libft.h"
#include "sys/stat.h"
typedef struct	s_p
{
	char	*flags;
	int		file_num;
	char	**av;
	int		ac;
	int		no_file;
}				t_p;

typedef struct	s_files
{
	char			*file_name;
	int				type;
	int				index;
	struct s_files	*next;
}				t_files;

typedef struct	s_param
{
	char			*file_name;
	int				type;
	struct s_param	*next;
}				t_param;

void	ft_same_time(t_param *f);
void	ft_ascii_sort(t_param *f);
void	ft_time_sort(t_param *s, char *p);
int		ft_point_on_ffile(int ac, char **av);
char	*ft_flag_check(int ac, char **av);
void	ft_main_arg(t_p *param);
int		ft_flags(char	*str, char *c);
t_param *ft_open_dir(char *av, char *s);
void	ft_check_afile(t_param *f, char *path, char *flags, int k);
char	*ft_sltocu(const char *s, char c);
int		ft_strlookup(char *s, char c);
void	ft_swap_param(t_param *s, t_param *start);
void	ft_revers_sort(t_param *t);
char	*ft_flag_check(int ac, char **av);
#endif
