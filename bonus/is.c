/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:10:30 by albaud            #+#    #+#             */
/*   Updated: 2022/10/20 11:12:51 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_flag(char f)
{
	return (indexof(".-# +0", f, 1) != -1 || (f >= '0' && f <= '9'));
}

int	is_alpha(char f)
{
	return (f >= '0' && f <= '9');
}

int	is_not_zero(char f)
{
	return ((f >= '1' && f <= '9'));
}

int	is_psign(char f)
{
	return (indexof("%sidcuxXp", f, 1) == -1);
}
