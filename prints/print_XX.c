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

void	print_xx(va_list *args, int *len, int *i, int *flags)
{
	char	*temp;

	temp = ft_itob(va_arg(*args, unsigned int), "0123456789ABCDEF");
	flags[9] = 1;
	print_space_num(temp, len, flags);
	free(temp);
	*i += 1;
}
