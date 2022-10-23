/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:19:42 by albaud            #+#    #+#             */
/*   Updated: 2022/10/19 17:16:12 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_i(va_list *args, int *len, int *i, t_print *flags)
{
	char	*temp;
	int		top;

	top = va_arg(*args, int);
	if (top < 0 && ++flags->length)
		flags->sign = '-';
	flags->prefixox = 0;
	temp = ft_itoa(top);
	flags->to_print = temp;
	print_utlimate(flags, len);
	free(temp);
	*i += 1;
}
