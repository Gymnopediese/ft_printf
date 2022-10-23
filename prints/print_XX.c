/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_XX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:19:42 by albaud            #+#    #+#             */
/*   Updated: 2022/10/19 16:44:47 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_xx(va_list *args, int *len, int *i, t_print *flags)
{
	char	*temp;

	temp = ft_itob(va_arg(*args, unsigned int), "0123456789ABCDEF");
	flags->minmaj = 1;
	flags->sign = 0;
	if (temp[0] == '0')
		flags->prefixox = 0;
	flags->to_print = temp;
	print_utlimate(flags, len);
	free(temp);
	*i += 1;
}
