/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flotob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:58:38 by albaud            #+#    #+#             */
/*   Updated: 2022/10/18 13:32:48 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	lens(long long int nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len + 1);
}

char	*ft_flotob(double nb)
{
	char			*str;
	long long int	n;
	int				i;

	n = (nb * 1000000);
	i = lens(n);
	nb = i;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	str[i--] = 0;
	str[0] = 48;
	if (n == 0)
		return (str);
	str[0] = '-';
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n = n / 10;
		if ((int) nb - 7 == i)
			str[i--] = '.';
	}
	return (str);
}
