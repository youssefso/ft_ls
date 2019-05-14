/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:24:16 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/05/04 19:47:02 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s == NULL)
	{
		write(1, "(null)", 8);
		return ;
	}
	while (*s)
	{
		write(1, s++, 1);
	}
}
