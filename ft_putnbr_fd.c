/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:37:23 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/17 19:37:38 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int printed;

	printed = 0;
	if (fd < 0)
		return (0) ;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr_fd("-2147483648", fd));
		else
		{
			printed += ft_putchar_fd('-', fd);
			printed += ft_putnbr_fd(-n, fd);
		}
	}
	else if (n <= 9)
		printed += ft_putchar_fd((n + '0'), fd);
	else
	{
		printed += ft_putnbr_fd((n / 10), fd);
		printed += ft_putchar_fd((n % 10) + '0', fd);
	}
	return (printed);
}