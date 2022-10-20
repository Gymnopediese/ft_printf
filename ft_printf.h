/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:23:32 by tate              #+#    #+#             */
/*   Updated: 2022/10/20 12:08:50 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

struct s_print
{
	char	*to_print;
	char	sign;
	int		length;
	
}	t_print;


int		indexof(char *src, char target, int mode);
void	get_flags(va_list *args, char *to_print, int *num, int *flags);
void	putcharcount(char c, int *num);
void	putstrcount(char *c, int *num);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *s1, char *s2);
char	*ft_itoa(int nb, char sign);
char	*ft_replace(char *to_ch, char *to_re, char *re);
char	*ft_itob(unsigned long long int nb, char *base);
char	*ft_flotob(double nb);
char	*ft_replace_c(char c, char *changes, char *to_change);
int		ft_strcmpl(char *s1, char *s2);
int		ft_printf(const char *to_print, ...);
void	print_s(va_list *args, int *len, int *i, int *flags);
void	print_c(va_list *args, int *len, int *i, int *flags);
void	print_i(va_list *args, int *len, int *i, int *flags);
void	print_d(va_list *args, int *len, int *i, int *flags);
void	print_x(va_list *args, int *len, int *i, int *flags);
void	print_xx(va_list *args, int *len, int *i, int *flags);
void	print_u(va_list *args, int *len, int *i, int *flags);
void	print_p(va_list *args, int *len, int *i, int *flags);
void	print_sign(int *len, int *i);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);
void	ft_putstr(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_nlen(unsigned long long nb, int n);
char	*ft_utoa(unsigned int nb);
int		is_psign(char f);
int		is_not_zero(char f);
int		is_alpha(char f);
int		is_flag(char f);
int		indexof(char *src, char target, int mode);
void	get_flags(va_list *args, char *to_print, int *num, int *flags);
void	minitoi(int *num, char *str, int *loop);
void	print_space_char(unsigned char toprint, int *len, int *flags);
void	print_space(char *toprint, int *len, int *flags);
void	print_space_num(char *toprint, int *len, int *flags);
void	print_num_zeros(char *toprint, int *len, int *flags);
void	putstrncount(char *c, int *num, int len);
#endif