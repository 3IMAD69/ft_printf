/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:26:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/13 15:58:32 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *str, ...)
{
    va_list args;

    va_start(args,str);
    while (*str)
    {   
        if (*str == '%')
        {
            str++;
            if (*str == 'd' || *str == 'i')
                ft_putnbr_fd(va_arg(args,int),1);
            else if (*str == 'c')
                ft_putchar_fd((char)va_arg(args,int),1);
            else if (*str == 's')
                ft_print_str(va_arg(args,char *));
            else if (*str == 'p')
                ft_print_pointer(va_arg(args,void *));
            else if (*str == 'x' || *str == 'X')
                ft_print_x(va_arg(args,unsigned int),*str);
            else if (*str == 'u')
                ft_print_u(va_arg(args,unsigned int));
            else if (*str == '%')
                ft_putchar_fd('%',1);
        }
        else
            ft_putchar_fd(*str,1);
        str++;
    }
    return (0);
    va_end(args);
}

int main()
{
    printf("a %% is dis\n");
    ft_printf("a %% is dis\n");

}
//gcc -Wall -Wextra -Werror ft_printf.c libft/ft_putnbr_fd.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c ft_print_str.c  && ./a.out