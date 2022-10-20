/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:43:46 by albaud            #+#    #+#             */
/*   Updated: 2022/10/18 14:45:28 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_utob(unsigned long long int nb, char *base)
{
	char					*str;
	unsigned long long int	n;
	int						i;

	n = nb;
	i = ft_nlen(nb, ft_strlen(base));
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = 0;
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = base[n % ft_strlen(base)];
		n = n / ft_strlen(base);
		i--;
	}
	return (str);
}
