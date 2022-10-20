/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as                                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 10:13:45 by tate              #+#    #+#             */
/*   Updated: 2022/10/19 13:06:08 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putstrreplaceccount(va_list *args, char *to_print, int *num, int *flags)
{	
	if (ft_strcmpl(&to_print[num[1]], "%c") == 0)
		print_c(args, num, &num[1]);
	else if (ft_strcmpl(&to_print[num[1]], "%i") == 0)
		print_i(args, num, &num[1]);
	else if (ft_strcmpl(&to_print[num[1]], "%d") == 0)
		print_d(args, num, &num[1]);
	else if (ft_strcmpl(&to_print[num[1]], "%s") == 0)
		print_s(args, num, &num[1]);
	else if (ft_strcmpl(&to_print[num[1]], "%u") == 0)
		print_u(args, num, &num[1]);
	else if (ft_strcmpl(&to_print[num[1]], "%x") == 0)
		print_x(args, num, &num[1]);
	else if (ft_strcmpl(&to_print[num[1]], "%X") == 0)
		print_xx(args, num, &num[1]);
	else if (ft_strcmpl(&to_print[num[1]], "%p") == 0)
		print_p(args, num, &num[1]);
	else if (ft_strcmpl(&to_print[num[1]], "%%") == 0)
		print_sign(num, &num[1]);
	else
		get_flags(*args, to_print, num, flags);
}

void	putcharcount(char c, int *num)
{
	*num = *num + 1;
	write(1, &c, 1);
}

void	putstrcount(char *c, int *num)
{
	int	i;

	if (!c)
	{
		putstrcount("(null)", num);
		return ;
	}
	i = -1;
	while (c[++i])
		putcharcount(c[i], num);
}

int	ft_printf(const char *to_print, ...)
{
	va_list	args;
	int		nums[2];
	int		flags[9];

	va_start(args, to_print);
	*nums = 0;
	nums[1] = 0;
	while (to_print[nums[1]])
	{
		if (to_print[nums[1]] == '%')
			putstrreplaceccount(&args, (char *) to_print, nums, flags);
		else
			putcharcount(to_print[nums[1]], *nums);
		nums[1] += 1;
	}
	return (*nums);
}