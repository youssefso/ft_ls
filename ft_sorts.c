/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 00:07:08 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/06 16:35:18 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_ascii_sort(t_param *s)
{
	t_param *start;
	int tmp;

	start = s;
	while (start != NULL && start->next != NULL)
	{
		s = start;
		while (s != NULL)
		{
			if (ft_strcmp(s->file_name, start->file_name) < 0)
			{
				ft_swap(&s->file_name, &start->file_name);
				tmp = s->type;
				s->type = start->type;
				start->type = tmp;
			}
			s = s->next;
		}
		start = start->next;
	}
}
void	ft_swap_param(t_param *s, t_param *start)
{
	int tmp;

	ft_swap(&s->file_name, &start->file_name);
	tmp = s->type;
	s->type = start->type;
	start->type = tmp;
}
char	*ft_path_maker(char *p, t_param *s)
{
	p = ft_strjoin(p, "/");
	p = ft_strjoin(p, s->file_name);
	return p;
}
void	ft_same_time(t_param *f)
{
	t_param *start = NULL;
	t_param *end = NULL;
	struct stat b1;
	t_param *tmp = NULL;
	struct stat b2;

	while (f != NULL && f->next != NULL)
	{
		lstat(f->file_name, &b1);
		lstat(f->next->file_name, &b2);
		if (b1.st_mtime == b2.st_mtime)
		{
			if (start == NULL)
				start = f;
			end = f->next;
		}
		else if (start != NULL)
		{
			tmp = end->next;
			end->next = NULL;
			ft_ascii_sort(start);
			end->next = tmp;
			start = NULL;
		}
		f = f->next;
	}
}

void	ft_time_sort(t_param *s, char *p)
{
	t_param *start;
	struct stat b1;
	struct stat b2;
	char *path;
	char *path1;
	int tmp;
	t_param *starts;

	starts = s;
	start = s;
	while (start != NULL && start->next != NULL)
	{
		s = start;
		while (s != NULL)
		{
			path = ft_path_maker(p, start);
			lstat(path, &b1);
			path1 = ft_path_maker(p, s);
			lstat(path1, &b2);
			if (b2.st_mtime > b1.st_mtime)
			{
				ft_swap(&s->file_name, &start->file_name);
				tmp = s->type;
				s->type = start->type;
				start->type = tmp;
			}
			s = s->next;
		}
		start = start->next;
	}
}
