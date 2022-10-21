/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:16:11 by albaud            #+#    #+#             */
/*   Updated: 2022/10/21 15:43:16 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_c(va_list *args, int *len, int *i, t_print *flags)
{
	flags->charr = (unsigned char) va_arg(*args, int);
	flags->symbol = 'c';
	print_utlimate(flags, len);
	*i += 1;
}
