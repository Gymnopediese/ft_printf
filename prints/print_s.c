/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:19:42 by albaud            #+#    #+#             */
/*   Updated: 2022/10/19 16:16:04 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_s(va_list *args, int *len, int *i, t_print *flags)
{
	*i += 1;
	flags->to_print = va_arg(*args, char *);
	print_utlimate(flags, len);
}
