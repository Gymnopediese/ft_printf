/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:32:33 by albaud            #+#    #+#             */
/*   Updated: 2022/10/20 10:13:51 by albaud           ###   ########.fr       */
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

void	get_flags(va_list *args, char *to_print, int *num, int *flags)
{
	(void) args;
	if ((to_print[++num[1]] == '-' || is_not_zero(to_print[num[1]]))
		&& flags[7] == -1)
	{
		if (to_print[num[1]] == '-' && num[1]++ > -10)
			flags[1] = 1;
		minitoi(&flags[7], to_print, &num[1]);
	}
	else if (to_print[num[1]] == '0' && flags[0] == 0 && ++flags[0] == 1)
		minitoi(&flags[6], to_print, &num[1]);
	else if (to_print[num[1]] == '.' && flags[2] == 0
		&& ++flags[2] == 1 && ++num[1])
		minitoi(&flags[8], to_print, &num[1]);
	else if (to_print[num[1]] == '#' && flags[3] == 0 && ++num[1] > -1)
		flags[3] = 1;
	else if (to_print[num[1]] == ' ' && ++flags[4] == 1 && ++num[1] > -1)
		minitoi(&flags[7], to_print, &num[1]);
	else if (to_print[num[1]] == '+' && flags[5] == 0 && ++num[1] > -1)
		flags[5] = 1;
	else if (to_print[num[1]] == '%')
		return ;
	if (is_flag(to_print[num[1]]) && num[1]-- > -123716)
		get_flags(args, to_print, num, flags);
}
