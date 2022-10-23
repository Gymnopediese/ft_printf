/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ultimate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:12:44 by albaud            #+#    #+#             */
/*   Updated: 2022/10/21 15:47:35 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"



void print(t_print *flags)
{
	printf("\n|%i|%i|%i|%i|%i|\n", flags->pading,flags->zeros, flags->length, flags->lrest, flags->toprint_length);
}

void	impression(t_print *flags, int *len)
{
	if (flags->symbol == 'c')
		putcharcount(flags->charr, len);
	else if (flags->symbol == 's')
		putstrncount(flags->to_print, len, flags->length);
	else
		putstrncount(flags->to_print, len, flags->toprint_length);
}

void	pre_modeling(t_print *flags, int *len)
{
	if (flags->prefixox && flags->minmaj == 1 && flags->to_print[0] != '0')
		putstrcount("0X", len);
	if (flags->symbol == 'p'
		|| (flags->prefixox && flags->minmaj == 0 && flags->to_print[0] != '0'))
		putstrcount("0x", len);
	if (flags->sign && flags->symbol != 's')
		putcharcount(flags->sign, len);

}

void	modeling(t_print *flags, int *len)
{
	while (--flags->zeros >= flags->length && flags->lrest > -1
		&& !flags->leftpadding)
		putcharcount(' ', len);
	pre_modeling(flags, len);
	while (flags->zeros-- >= flags->length && !flags->leftpadding)
		putcharcount('0', len);
	while (flags->lrest-- > flags->toprint_length && flags->symbol != 's')
		putcharcount('0', len);
	impression(flags, len);
}

void	filament_length2(t_print *flags)
{
	if (flags->length > flags->lrest && flags->lrest > -1
		&& flags->symbol == 's')
		flags->length = flags->lrest;
	if (flags->length < flags->lrest && flags->symbol != 's')
		flags->length = flags->lrest;
	if (flags->sign && flags->symbol != 's')
		flags->length++;
	if (flags->symbol == 'p' || flags->prefixox)
		flags->length += 2;
	if (flags->lrest == 0 && flags->symbol != 's' && flags->to_print[0] == '0')
	{
		flags->toprint_length = 0;
		flags->length = 0;
	}
}

void	filament_length(t_print *flags)
{
	if (flags->symbol == 'c')
		flags->toprint_length = 1;
	else if (flags->to_print)
		flags->toprint_length = ft_strlen(flags->to_print);
	else
		flags->toprint_length = 6;
	flags->length = flags->toprint_length;
	filament_length2(flags);
}

void	print_utlimate(t_print *flags, int *len)
{
	filament_length(flags);
	if (flags->leftpadding == 1)
		modeling(flags, len);
	while (--flags->pading >= flags->length)
		putcharcount(' ', len);
	if (flags->leftpadding == 0)
		modeling(flags, len);
}

