/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:26:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/17 20:50:25 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int ft_printf(const char *str, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args,str);
    while (*str)
    {   
        if (*str == '%')
        {
            str++;
            if (*str == 'd' || *str == 'i')
                printed_chars += ft_putnbr_fd(va_arg(args,int),1);
            else if (*str == 'c')
                printed_chars += ft_putchar_fd((char)va_arg(args,int),1);
            else if (*str == 's')
                printed_chars += ft_print_str(va_arg(args,char *));
            else if (*str == 'p')
                printed_chars += ft_print_pointer(va_arg(args,void *));
            else if (*str == 'x' || *str == 'X')
                printed_chars += ft_print_x(va_arg(args,unsigned int),*str);
            else if (*str == 'u')
                printed_chars += ft_print_u(va_arg(args,unsigned int));
            else if (*str == '%')
                printed_chars += ft_putchar_fd('%',1);
        }
        else
            printed_chars += ft_putchar_fd(*str,1);
        str++;
    }
    return (printed_chars);
    va_end(args);
}

// int main()
// {  
//         int result = printf("Hello, %s!\n", "world");
//         printf("%d",result);
// }
