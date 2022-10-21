/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:21:03 by albaud            #+#    #+#             */
/*   Updated: 2022/10/21 13:17:02 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_p(va_list *args, int *len, int *i, t_print *flags)
{
	char	*temp;

	temp = ft_itob((long long int)va_arg(*args, long long int),
			"0123456789abcdef");
	flags->symbol = 'p';
	flags->to_print = temp;
	print_utlimate(flags, len);
	free(temp);
	*i += 1;
}
