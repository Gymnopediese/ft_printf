/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:17:18 by tate              #+#    #+#             */
/*   Updated: 2022/10/20 11:31:00 by albaud           ###   ########.fr       */
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
	   printf("%10p, %10p, %10p, %10p, %10p, %10p\n", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352);
	ft_printf("%10p, %10p, %10p, %10p, %10p, %10p\n", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352);
	printf(">------------<%36.30d>------------<\n", -885918674);
	
	ft_printf(">------------<%36.30d>------------<\n", -885918674);
	printf("42%38.2d42\n", -160424504);
	
	printf("42%38.2d42\n", -160424504);
	
	printf(">------------<% 24.28d>------------<\n", 0);

	ft_printf(">------------<% 24.28d>------------<\n", 0);

	printf("!%+16.24d!\n", 0);

	ft_printf("!%+16.24d!\n", 0);
	printf( "%046.22d\n", 0);

	ft_printf( "%046.22d\n", 0);
	printf("^.^/%038.8d^.^/\n", 580269098);

	ft_printf("^.^/%038.8d^.^/", 580269098);
}