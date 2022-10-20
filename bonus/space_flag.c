/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:12:44 by albaud            #+#    #+#             */
/*   Updated: 2022/10/20 11:52:02 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../ft_printf.h"

void	print_space(char *toprint, int *len, int *flags)
{
	int		loop;
	int		length;

	loop = -1;
	length = ft_strlen(toprint);
	if (!toprint)
		length = 6;
	if (length > flags[8] && flags[8] > -1)
		length = flags[8];
	if (flags[1])
		putstrncount(toprint, len, length);
	while (++loop < flags[7] - length)
		putcharcount(' ', len);
	if (!flags[1])
		putstrncount(toprint, len, length);
}

void	print_space_char(unsigned char toprint, int *len, int *flags)
{
	int		loop;

	loop = -1;
	if (flags[1])
		putcharcount(toprint, len);
	while (++loop < flags[7] - 1)
		putcharcount(' ', len);
	if (!flags[1])
		putcharcount(toprint, len);
}

void	print_space_num(char *toprint, int *len, int *flags)
{
	int		loop;

	loop = -1;
	if (flags[1])
		print_num_zeros(toprint, len, flags);
	if (flags[8] > 0)
	{
		if (flags[8] < ft_strlen(toprint))
		{
			while (++loop < flags[7] - ft_strlen(toprint))
				putcharcount(' ', len);	
		}
		else
		{
			if (indexof("-+ ", toprint[0], 1) != -1)
				flags[7] -= 1;
			while (++loop < flags[7] - flags[8])
				putcharcount(' ', len);	
		}
	}
	else
	{
		while (++loop < flags[7] - ft_strlen(toprint))
			putcharcount(' ', len);
	}
	if (!flags[1])
		print_num_zeros(toprint, len, flags);
}

void	print_num_zeros(char *toprint, int *len, int *flags)
{
	int	loop;
	int	index;

	index = -1;
	loop = -1;
	if (toprint[++index] == '-' && ++index)
		putcharcount('-', len);
	if (toprint[index] == ' ' && ++index)
		putcharcount(' ', len);
	if (toprint[index] == '+' && ++index)
		putcharcount('+', len);
	if (flags[3] && toprint[0] != '0' && !flags[9])
		putstrcount("0x", len);
	if (flags[3] && toprint[0] != '0' && flags[9])
		putstrcount("0X", len);
	while (++loop < flags[6] - ft_strlen(toprint) && flags[8] == -1)
		putcharcount('0', len);
	while (loop++ < flags[6] - flags[8] - 1 && flags[8] != -1)
		putcharcount(' ', len);
	loop = -1;
	while (++loop < flags[8] - ft_strlen(toprint) + index)
		putcharcount('0', len);
	putstrcount(&toprint[index], len);
}
 */