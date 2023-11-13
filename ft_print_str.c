/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:52:17 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/12 19:53:51 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void ft_print_str(char *s)
{
    if (!s)
    {
        ft_putstr_fd("(null)",1);
        return;
    }
    else
        ft_putstr_fd(s,1);
}