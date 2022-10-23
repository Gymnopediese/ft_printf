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
#include <stdio.h>
#include <string.h>

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[1;32m");
}

void reset () {
  printf("\033[0m");
}

void test(char *totest, int num)
{
	int a = printf(totest, num);
	printf("$ : %i\n", a);
	int b = ft_printf(totest, num);
	printf("$ : %i\n", b);
	if (a == b)
	{
		green();
		printf("[ passed ]\n");
	}
	else
	{
		red();
		printf("[ failed ]\n");
	}
	reset();
}

// int	main(int argc, char **argv)
// {
// 	int	a;

// 	(void) argc;
// 	if (argv[3][0] == 'f')
// 	{
// 		a = ft_printf(argv[1], atoi(argv[2]));
// 		printf("$ : %i\n", a);
// 	}
// 	if (argv[3][0] == 't')
// 	{
// 		a = printf(argv[1], atoi(argv[2]));
// 		printf("$ : %i\n", a);
// 	}
// 	if (argv[3][0] == 'c')
// 	{
// 		test(argv[1], atoi(argv[2]));
// 	}
// }


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
	printf(">------------<%50.10d>------------<\n",0);
	ft_printf(">------------<%50.10d>------------<\n",0);
	printf("!%+16.24d!\n", 0);

	ft_printf("!%+16.24d!\n", 0);
	
	test("%046.22d", 1);
	test("%038.8d", 580269098);
	test("%046d", 1);
	test("%046d", 0);
	test("%046.22d", 0);
	test("%038.8d", 0);
	test("%38.8d", 0);
	test("%0138.8d", 0);
	test("%018.d", 0);
	test("%-18.d", 0);
	test("%018.10d", -10);
	test("%#018.10x", 10);
}
