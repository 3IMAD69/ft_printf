#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int ft_print_str(char *s);
int ft_print_p(void *p);
int ft_print_x(unsigned int nb, char maj);
int ft_print_u(unsigned int nb);
int ft_printf(const char *str, ...);

int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(long n, int fd);
int	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif