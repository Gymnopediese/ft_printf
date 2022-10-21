/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:13:45 by tate              #+#    #+#             */
/*   Updated: 2022/10/21 15:39:29 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



void	putstrreplaceccount(va_list *args,
	char *to_print, int *num, t_print *flags)
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
	printf("\n|%i|%i|%i|%i|%i|%i|%i|%i|%i|%i|\n",
		flags[0], flags[1], flags[2], flags[3],
		flags[4], flags[5], flags[6], flags[7], flags[8], flags[9]);
}

void	reset_flags(t_print *flags)
{
	flags->symbol = 0;
	flags->charr = 0;
	flags->length = 0;
	flags->lrest = -1;
	flags->num = 0;
	flags->spaces = 0;
	flags->zeros = 0;
	flags->sign = 0;
	flags->to_print = 0;
	flags->pading = 0;
	flags->leftpadding = 0;
	flags->prefixox = 0;
}

int	ft_printf(const char *to_print, ...)
{
	va_list		args;
	int			nums[2];
	t_print		flags;

	va_start(args, to_print);
	*nums = 0;
	nums[1] = 0;
	while (to_print[nums[1]])
	{
		if (to_print[nums[1]] == '%')
		{
			reset_flags(&flags);
			get_flags((char *) to_print, nums, &flags);
			putstrreplaceccount(&args, (char *) to_print, nums, &flags);
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