/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:02:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/13 15:27:08 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 16;
		size++;
	}
	return (size);
}

void ft_print_x(unsigned int nb, char maj)
{
	char		*hex_base;
    char        *final_number;
    int size;

	hex_base = "0123456789abcdef";
    if (nb == 0)
    {
        ft_putchar_fd('0',1);
        return ;
    }
    size = get_size(nb);
	final_number = (char *)malloc(sizeof(char *) * size + 1);
	if (!final_number)
		return ;
	final_number[size] = '\0';
	while (nb)
	{
	    size--;
        if (maj == 'X' && (nb % 16) > 9)
            final_number[size] = hex_base[(nb % 16)] - 32;
        else
		    final_number[size] = hex_base[(nb % 16)];
		nb /= 16;
	}
	ft_putstr_fd(final_number, 1);
    free (final_number);
}