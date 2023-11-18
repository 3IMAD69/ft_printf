/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:24:00 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/18 21:07:47 by idhaimy          ###   ########.fr       */
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

int	ft_print_p(void *p)
{
	uintptr_t	p_value;
	char		*hex_base;
	char		*final_number;
	int			size;

	hex_base = "0123456789abcdef";
	p_value = (uintptr_t)p;
	if (!p_value)
		return (ft_putstr_fd("0x0", 1));
	if (write(1, "0x", 2) == -1)
		return (-1);
	size = get_size(p_value);
	final_number = (char *)malloc(sizeof(char *) * size + 1);
	if (!final_number)
		return (-1);
	final_number[size] = '\0';
	while (p_value)
	{
	    size--;
		final_number[size] = hex_base[(p_value % 16)];
		p_value /= 16;
	}
	if (ft_putstr_fd(final_number, 1) == -1)
	{
	    free (final_number);
		return (-1);
	}
    free (final_number);
	return (get_size((uintptr_t)p) + 2);
}
