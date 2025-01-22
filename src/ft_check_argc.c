/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:34:25 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/22 17:23:25 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// returns -1 if argc is wrong
int	ft_check_argc(int argc)
{
	if (argc < 2)
	{
		errno = 5;
		perror("No map specified, please provide a valid map file");
		return (-1);
	}
	if (argc > 2)
	{
		errno = 7;
		perror("Too many arguments given, please provide only 1");
		return (-1);
	}
	return (0);
}
