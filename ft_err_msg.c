/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:35:23 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/30 17:12:50 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Utility function that retuns 1
// perrors the <str> and sets errno to <err>
int	ft_err_msg(const char *str, int err)
{
	errno = err;
	write(1, "Error\n", 6);
	perror(str);
	return (1);
}
