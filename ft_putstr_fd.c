/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:07:19 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/17 13:02:29 by idhaimy          ###   ########.fr       */
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
	{
		ft_putchar_fd(*s++, fd);
		printed++;
	}
	return (printed++);
}
