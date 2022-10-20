/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:13:45 by tate              #+#    #+#             */
/*   Updated: 2022/10/20 12:05:26 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	putstrreplaceccount(va_list *args, char *to_print, int *num, int *flags)
{	
	if (to_print[num[1]] == 'c')
		print_c(args, num, &num[1], flags);
	else if (to_print[num[1]] == 'i' || to_print[num[1]] == 'd')
		print_i(args, num, &num[1], flags);
	else if (to_print[num[1]] == 's')
		print_s(args, num, &num[1], flags);
	else if (to_print[num[1]] == 'u')
		print_u(args, num, &num[1], flags);
	else if (to_print[num[1]] == 'x')
		print_x(args, num, &num[1], flags);
	else if (to_print[num[1]] == 'X')
		print_xx(args, num, &num[1], flags);
	else if (to_print[num[1]] == 'p')
		print_p(args, num, &num[1], flags);
	else if (to_print[num[1]] == '%')
		print_sign(num, &num[1]);
}

void	print_flags(int *flags)
{
	printf("\n|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|\n", flags[0], flags[1], flags[2], flags[3], flags[4], flags[5], flags[6], flags[7], flags[8], flags[9]);
}

void	reset_flags(int *flags)
{
	flags[0] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
	flags[5] = 0;
	flags[6] = -1;
	flags[7] = -1;
	flags[8] = -1;
}

int	ft_printf(const char *to_print, ...)
{
	va_list	args;
	int		nums[2];
	int		flags[10];

	va_start(args, to_print);
	*nums = 0;
	nums[1] = 0;
	while (to_print[nums[1]])
	{
		if (to_print[nums[1]] == '%')
		{
			reset_flags(flags);
			get_flags(&args, (char *) to_print, nums, flags);
			//print_flags(flags);
			putstrreplaceccount(&args, (char *) to_print, nums, flags);
		}
		else
		{
			putcharcount(to_print[nums[1]], nums);
			nums[1] += 1;
		}
	}
	return (*nums);
}

/*
int		flags[30] 
.-# +

0 : 0
1 : -
2 : .
3 : #
4 : ' '
5 : +
6 : 0num
7 : -num
8 : .num
9 : c
*/