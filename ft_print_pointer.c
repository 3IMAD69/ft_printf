/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:24:00 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/17 12:59:34 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(uintptr_t n)
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

int	ft_print_pointer(void *p)
{
	uintptr_t	p_value;
	char		*hex_base;
	char		*final_number;
	int			size;

	p_value = (uintptr_t)p;
	hex_base = "0123456789abcdef";
	write(1, "0x", 2);
	if (p_value == 0)
		return (ft_putchar_fd('0', 1));
	size = get_size(p_value);
	final_number = (char *)malloc(sizeof(char *) * size + 1);
	if (!final_number)
		return (0);
	final_number[size] = '\0';
	while (p_value)
	{
	    size--;
		final_number[size] = hex_base[(p_value % 16)];
		p_value /= 16;
	}
	ft_putstr_fd(final_number, 1);
    free (final_number);
	return (size + 2);
}
