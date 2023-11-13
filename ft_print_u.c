/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:02:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/13 15:34:52 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void	ft_print_u(unsigned int nb)
{
	char	*dec_base;
	char	*final_number;
	int		size;

	dec_base = "0123456789";
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
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
		final_number[size] = dec_base[(nb % 10)];
		nb /= 10;
	}
	ft_putstr_fd(final_number, 1);
	free(final_number);
}
