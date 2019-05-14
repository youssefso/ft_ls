/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 10:34:23 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/14 01:18:27 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int     ft_flags(char *str,char *c)
{
	while (*str != '\0')
	{
		if (*str != 'a' && *str != 'l' && *str != 'r' &&
				*str != 'R' && *str != 't')
		{
			*c = *str;
			return (-1);
		}
		str++;
	}
	return 0;
}
t_param	*ft_init_tparam()
{
	t_param *f;

	f = (t_param *)malloc(sizeof(t_param));
	f->file_name = NULL;
	f->next = NULL;
	return (f);
}

t_param	*ft_last_param(t_param *f)
{
	while (f->next != NULL)
		f = f->next;
	return (f);
}
void	ft_stock_read(struct dirent dt, t_param **f)
{
	t_param *last_f;
	t_param *new_f;

	if (*f == NULL)
	{
		(*f) = ft_init_tparam();
		(*f)->file_name = ft_strdup(dt.d_name);
		(*f)->type = (int)dt.d_type;
	}
	else
	{
		last_f = ft_last_param(*f);
		new_f = ft_init_tparam();
		new_f->file_name = ft_strdup(dt.d_name);
		new_f->type = (int)dt.d_type;
		last_f->next = new_f;
	}	
}

void	ft_display(t_param *f, char *p, int a)
{
	char	*tmp;
	int		i = 0;
	if (f == NULL)
	{
		ft_putstr("ls : ");
		ft_putstr(ft_sltocu(p, '/'));
		ft_putstr(": ");
		perror(NULL);
	}
	else
	{
		while (f != NULL)
		{
			if (a == 1)
			{
				i++;
				ft_putstr(f->file_name);
				ft_putstr(" ");
			}
			else if (f->file_name[0] != '.')
			{
				i++;
				ft_putstr(f->file_name);
				ft_putstr(" ");
			}
			f = f->next;
		}
		if (i != 0)
			ft_putstr("\n");
	}
}

void	ft_free_param(t_param *f)
{
	t_param *tmp;

	while (f != NULL)
	{
		tmp = f;
		f = f->next;
		free(tmp->file_name);
		free(tmp);
	}
}
void	ft_check_afile(t_param *f, char *p, char *flags, int k)
{
	t_param *mini_f;
	char *path;
	int i;
	int a;

	ft_ascii_sort(f);
	if ((ft_strlookup(flags, 't')) == 1)
	{
		ft_time_sort(f, p);
		ft_same_time(f);
	}
	if ((ft_strlookup(flags, 'r')) == 1)
		ft_revers_sort(f);
	i = ft_strlookup(flags, 'R');
	a = ft_strlookup(flags, 'a');
	if (k > 1)
	{
		ft_putstr(p);
		ft_putstr(" :");
		ft_putstr("\n");
	}
	ft_display(f, p, a);
	while (f != NULL && i == 1)
	{
		path = p;
		if (f->type == 4 && (ft_strcmp(f->file_name, ".") != 0) && (ft_strcmp(f->file_name, "..") != 0))
		{
			if (a != 0 || f->file_name[0] != '.')
			{
			path = ft_strjoin(path, "/");
			path = ft_strjoin(path, f->file_name);//leak
			mini_f = ft_open_dir(path, flags);
			ft_check_afile(mini_f, path, flags, ++k);
			}
		}
		f = f->next;
	}
	ft_free_param(f);
}
t_param	*ft_open_dir(char *av, char *flags)
{
	DIR *dir;
	struct dirent *dt;
	t_param *f;
	int a;

	f = NULL;
	dir = opendir(av);
	a = 0;
	if (ft_strlookup(flags, 'a'))
		a = 1;
	if (dir != NULL)
	{
		while ((dt = readdir(dir)))
		{
			//if (dt->d_name[0] != '.' || a == 1)
			ft_stock_read(*dt, &f);
		}
		closedir(dir);
	}
	return (f);
}

void	ft_arg_process(t_p *p)
{
	int i;
	t_param *f;

	i = p->file_num;
	if (p->file_num == 0)
	{
		f = ft_open_dir(".", p->flags);
		ft_check_afile(f, ".", p->flags, 1);
	}
	else
	{
		while (i < p->ac)
		{
			f = ft_open_dir(p->av[i], p->flags);
			ft_check_afile(f, p->av[i++], p->flags, p->ac - p->file_num);
		}
	}
}
int main(int ac, char **av)
{
	t_param *f;
	t_p *param;
	struct stat b;
	param = (t_p *)malloc(sizeof(t_p));
	param->av = av;
	param->ac = ac;
	param->flags = ft_flag_check(ac, av);
	param->no_file = 0;
	param->file_num = ft_point_on_ffile(ac, av);
	ft_arg_process(param);
	/*f = ft_open_dir(av[param->file_num], param->flags);
	while (f != NULL)
	{
		lstat(f->file_name, &b);
		if (b.st_mode == )
		printf("file name : %s ** read %hu\n", f->file_name, b.st_mode);
		f = f->next;
	}*/
}
