/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:14:33 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/23 13:10:39 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// writes out an unsigned int in hexadecimal and returns bytes written
// lowercase.
size_t	ft_print_x(unsigned int num)
{
	size_t	count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (num >= 16)
		count += ft_print_x(num / 16);
	write(1, &base[num % 16], 1);
	count++;
	return (count);
}
