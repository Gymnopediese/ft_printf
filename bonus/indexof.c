/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:11:41 by albaud            #+#    #+#             */
/*   Updated: 2022/10/19 15:28:20 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	indexof(char *src, char target, int mode)
{
	int	i;

	i = -1;
	if (src == 0)
		return (-1);
	while (src[++i])
	{
		if (src[i] == target)
			return (i);
	}
	if (mode == 0)
		return (i - 1);
	else
		return (-1);
}
