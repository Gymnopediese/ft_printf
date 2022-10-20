/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 03:26:21 by tate              #+#    #+#             */
/*   Updated: 2022/10/19 17:17:17 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	len(long nb, char sign)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = nb * -1;
	if (sign)
		len++;
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*zero(char sign)
{
	char	*res;

	if (sign == 0)
	{
		res = malloc(2);
		res[0] = '0';
		res[1] = 0;
		return (res);
	}
	else
	{
		res = malloc(3);
		res[0] = sign;
		res[1] = '0';
		res[2] = 0;
		return (res);
	}
}

char	*ft_itoa(int nb, char sign)
{
	char	*str;
	long	n;
	int		i;

	if (nb == 0)
		return (zero(sign));
	n = nb;
	i = len(n, sign);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	str[i--] = '\0';
	str[0] = 48;
	if (n == 0)
		return (str);
	str[0] = sign;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n = n / 10;
	}
	return (str);
}
