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

void	impression(t_print *flags, int *len)
{
	if (flags->symbol == 'c')
		putcharcount(flags->charr, len);
	else if (flags->symbol == 's')
		putstrncount(flags->to_print, len, flags->length);
	else
		putstrncount(flags->to_print, len, flags->toprint_length);
}

void	modeling(t_print *flags, int *len)
{
	while (flags->lrest-- > flags->toprint_length && flags->symbol != 's')
		putcharcount('0', len);
	while (--flags->zeros - flags->length > -1)
		putcharcount('0', len);
	impression(flags, len);
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
	modeling(flags, len);
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
	if (flags->sign && flags->symbol != 's')
		flags->length++;
	if (flags->symbol == 'p' || flags->prefixox)
		flags->length += 2;
	if (flags->length > flags->lrest && flags->lrest > -1)
		flags->length = flags->lrest;
}

void	print_utlimate(t_print *flags, int *len)
{
	filament_length(flags);
	if (flags->leftpadding == 1)
		pre_modeling(flags, len);
	while (--flags->pading >= flags->length)
		putcharcount(' ', len);
	if (flags->leftpadding == 0)
		pre_modeling(flags, len);
}

