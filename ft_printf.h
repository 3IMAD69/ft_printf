#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

void ft_print_str(char *s);
void ft_print_pointer(void *p);
void ft_print_x(unsigned int nb, char maj);
void ft_print_u(unsigned int nb);
#endif