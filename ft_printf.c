/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 18:26:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/11 19:40:13 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

int ft_printf(const char *str, ...)
{
    va_list args;

    va_start(args,str);
    // printf("%d",va_arg(args,int));
    // printf("%d",va_arg(args,int));
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            if (*str == 'd')
                ft_putnbr_fd(va_arg(args,int),1);
            else if (*str == 'c')
                ft_putchar_fd((char)va_arg(args,int),1);
            else if (*str == 's')
                ft_putstr_fd(va_arg(args,char *),1);
        }
        else
        {
            ft_putchar_fd(*str,1);
        }
        str++;
    }


    va_end(args);
    
}


int main()
{
    ft_printf("%dtesting%c",5,'s');
}