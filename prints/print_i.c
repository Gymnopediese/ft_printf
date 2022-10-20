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

void	print_i(va_list *args, int *len, int *i, int *flags)
{
	char	*temp;
	int		top;
	char	maqueu;

	top = va_arg(*args, int);
	maqueu = 0;
	if (top < 0)
		maqueu = '-';
	if (flags[5] && top > -1)
		maqueu = '+';
	if (flags[4] && top > -1)
		maqueu = ' ';
	temp = ft_itoa(top, maqueu);
	print_space_num(temp, len, flags);
	free(temp);
	*i += 1;
}
