/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:32:33 by albaud            #+#    #+#             */
/*   Updated: 2022/10/21 15:42:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	minitoi(int *num, char *str, int *loop)
{
	*num = 0;
	while (is_alpha(str[*loop]))
	{
		*num = *num * 10 + str[*loop] - '0';
		*loop += 1;
	}
}

void	get_flags(char *to_print, int *num, t_print *flags)
{
	if (to_print[++num[1]] == '-' && ++num[1] > -1)
		flags->leftpadding = 1;
	else if (is_not_zero(to_print[num[1]]))
		minitoi(&flags->pading, to_print, &num[1]);
	else if (to_print[num[1]] == '0')
		minitoi(&flags->zeros, to_print, &num[1]);
	else if (to_print[num[1]] == '.' && ++num[1])
		minitoi(&flags->lrest, to_print, &num[1]);
	else if (to_print[num[1]] == '#' && ++num[1] > -1)
		flags->prefixox = 1;
	else if (to_print[num[1]] == ' ' && ++num[1] > -1)
	{
		flags->sign = ' ';
		minitoi(&flags->pading, to_print, &num[1]);
	}
	else if (to_print[num[1]] == '+' && ++num[1] > -1)
		flags->sign = '+';
	else if (to_print[num[1]] == '%')
		return ;
	if (is_flag(to_print[num[1]]) && num[1]-- > -123716)
		get_flags(to_print, num, flags);
}
