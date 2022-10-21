/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:17:18 by tate              #+#    #+#             */
/*   Updated: 2022/10/21 15:25:39 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h" 
#include <limits.h>

int	main(void)
{
	void *pointer = malloc(323);
	
	printf("%i\n",    printf("%% : %% | char : %c | str : %s | hex : %x | hex maj : %X | int : %i | unsigned int : %u | deci : %d | pointer : %p$\n", '%', "hello world" , 111, 222, 3, 4, -5, pointer));
	printf("%i\n", ft_printf("%% : %% | char : %c | str : %s | hex : %x | hex maj : %X | int : %i | unsigned int : %u | deci : %d | pointer : %p$\n", '%', "hello world" , 111, 222, 3, 4, -5, pointer));
	   printf("%.d, %.d, %.d, %.d, %.d, %.d, %.d, %.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	ft_printf("%.d, %.d, %.d, %.d, %.d, %.d, %.d, %.d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf(">------------<%36.30d>------------<\n", -885918674);
	
	ft_printf(">------------<%36.30d>------------<\n", -885918674);
		printf("%5.1d, %5.1d, %5.1d, %5.1d, %5.1d, %5.1d, %5.1d, %5.1d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	
	ft_printf("%5.1d, %5.1d, %5.1d, %5.1d, %5.1d, %5.1d, %5.1d, %5.1d\n", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);
	printf("\\!/%14c\\!/\n", (char)0);
	ft_printf("\\!/%14c\\!/\n", (char)0);

	printf("!%+16.24d!\n", 0);

	ft_printf("!%+16.24d!\n", 0);
	printf( "%046.22d\n", 0);

	ft_printf( "%046.22d\n", 0);
	printf("^.^/%038.8d^.^/\n", 580269098);

	ft_printf("^.^/%038.8d^.^/", 580269098);
}