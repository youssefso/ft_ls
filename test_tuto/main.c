/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 07:10:05 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/14 07:20:59 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_test(char *str)
{
	char *tmp;

	tmp = ft_strjoin(str, "/");
	free(str);
	str = ft_strjoin(tmp, "yes");
	free(tmp);
	ft_putstr(str);
}
int main(int ac, char **av)
{
	char *str;

	str = (char *)malloc(ft_strlen(av[1]));
	str = ft_strcpy(str, av[1]);
	ft_test(str);
	return 0;
}
