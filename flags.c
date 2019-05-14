/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:26:31 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/04 19:58:26 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	ft_dp_flgerror(char *flags)
{
	free(flags);
	ft_putstr("usage: ls [-Ralrt] [file ...]");
	exit(0);
}
int		ft_point_on_ffile(int ac, char **av)
{
	int i;

	i = 1;
	if (ac == 1)
		return (0);
	while(i < ac && av[i][0] == '-' && av[i][1] != '\0')
		i++;
	if (i == ac)
		return (0);
	return (i);
}
char	*ft_flag_check(int ac, char **av)
{
	int i;
	char	*flags;
	char	*tmp;
	char	c;
	
	i = 1;
	if (ac == 1)
		return (NULL);
	flags = ft_strnew(0);
	while(i < ac && av[i][0] == '-' && av[i][1] != '-')
	{
		tmp = flags;
		flags = ft_strjoin(flags, av[i] + 1);
		free(tmp);
		i++;
	}
	if ((ft_strlen(flags) == 0))
	{
		free(flags);
		return (NULL);
	}
	else
	{
		if ((ft_flags(flags, &c) < 0)) // ie: remove arg c if not used
			ft_dp_flgerror(flags);
	}
	return (flags);
}
