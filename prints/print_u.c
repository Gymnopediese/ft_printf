/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:19:42 by albaud            #+#    #+#             */
/*   Updated: 2022/10/19 16:01:31 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_u(va_list *args, int *len, int *i, t_print *flags)
{
	char	*temp;

	temp = ft_utoa((unsigned long int)va_arg(*args, unsigned long int));
	flags->to_print = temp;
	print_utlimate(flags, len);
	free(temp);
	*i += 1;
}
