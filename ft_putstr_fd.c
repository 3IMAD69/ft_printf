/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:07:19 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/17 16:28:06 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int printed;

	printed = 0;
	if (fd < 0 || !s)
		return (0);
	while (*s)
		printed += ft_putchar_fd(*s++, fd);
	return (printed++);
}
