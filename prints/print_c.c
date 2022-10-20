/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:16:11 by albaud            #+#    #+#             */
/*   Updated: 2022/10/19 16:13:59 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_c(va_list *args, int *len, int *i, int *flags)
{
	unsigned char	res;

	res = (char)(unsigned char) va_arg(*args, int);
	if (flags[7] > -1)
		print_space_char(res, len, flags);
	else
		putcharcount(res, len);
	*i += 1;
}
