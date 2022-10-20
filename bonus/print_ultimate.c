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

#include "../ft_printf.h"

void	pre_modeling(t_print *flags, int *len)
{
	if (flags->prefixox && flags->minmaj == 1)
		putstrcount("0X", len);
	if (flags->prefixox && flags->minmaj == 0)
		putstrcount("0x", len);
	if (flags->sign)
		putcharcount(flags->sign, len);
	if (flags->symbol == 'c')
		putcharcount(flags->charr, len);
	else
		putstrcount(flags->to_print, len);
}

void	filament_length(t_print *flag)
{
	if (flag->symbol == 'c')
		flag->length = 1;
	else
		flag->length = ft_strlen(flag->to_print);
	if (flag->sign)
		flag->length++;
}


void	print_utlimate(t_print *flags, int *len)
{
	filament_length(flags);
	if (flags->leftpadding == 0)
		pre_modeling(flags, len);
	while (--flags->pading - flags->length >= 0)
		putcharcount(' ', len);
	if (flags->leftpadding == 1)
		pre_modeling(flags, len);
}

