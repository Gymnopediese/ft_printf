/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:21:03 by albaud            #+#    #+#             */
/*   Updated: 2022/10/20 10:36:38 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_p(va_list *args, int *len, int *i, t_print *flags)
{
	char	*temp;

	temp = ft_itob((long long int)va_arg(*args, long long int),
			"0123456789abcdef");
	flags->minmaj = 0;
	flags->prefixox = 1;
	flags->to_print = temp;
	print_utlimate(flags, len);
	free(temp);
	*i += 1;
}
