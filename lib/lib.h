/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdamitzi <hdamitzi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:24:46 by hdamitzi          #+#    #+#             */
/*   Updated: 2023/04/11 10:25:53 by hdamitzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_atoi(const char *str);
char				*ft_itoa(int n);

int					ft_isdigit(int c);

int					ft_isdigitstr(char *str);

int					ft_strcmp(char *s1, char *s2);
int					ft_int_overflow(char *nbr);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);

int					ft_printf(const char *s, ...);
unsigned long long	ft_printf_strlen(const char *s);

void				ft_putc(char c, int *total);
void				ft_puts(char *str, int *total);
void				ft_putnb_base(unsigned long long nb,
						char *base, int *total);
void				ft_putnb(unsigned long long nl, int *total);
void				ft_put_ptr(void *ptr, int *total);

#endif
