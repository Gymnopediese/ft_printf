/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:26:31 by albaud            #+#    #+#             */
/*   Updated: 2022/10/18 13:32:44 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_replace_c(char c, char *changes, char *to_change)
{
	char	end[2];

	end[0] = c;
	end[1] = 0;
	return (ft_replace(to_change, changes, end));
}
