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

void	print_s(va_list *args, int *len, int *i, int *flags)
{
	*i += 1;
	print_space(va_arg(*args, char *), len, flags);
}
