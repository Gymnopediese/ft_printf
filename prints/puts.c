/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:19:27 by albaud            #+#    #+#             */
/*   Updated: 2022/10/21 13:46:48 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	putcharcount(char c, int *num)
{
	*num = *num + 1;
	write(1, &c, 1);
}

void	putstrcount(char *c, int *num)
{
	int	i;

	if (!c)
	{
		putstrcount("(null)", num);
		return ;
	}
	i = -1;
	while (c[++i])
		putcharcount(c[i], num);
}

void	putstrncount(char *c, int *num, int len)
{
	int	i;

	if (!c)
	{
		putstrncount("(null)", num, len);
		return ;
	}
	if (len == 0)
		return ;
	i = -1;
	while (len-- > 0 && c[++i])
		putcharcount(c[i], num);
}
