/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikunne <sikunne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:59:24 by sikunne           #+#    #+#             */
/*   Updated: 2025/01/28 13:01:22 by sikunne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	int num;

	num = 11;
	printf("%i - %i\n", num % 10, num / 10);
	num = 10;
	printf("%i - %i\n", num % 10, num / 10);
	num = 01;
	printf("%i - %i\n", num % 10, num / 10);
	num = 00;
	printf("%i - %i\n", num % 10, num / 10);
	num = -11;
	printf("%i - %i\n", num % 10, num / 10);
	num = -10;
	printf("%i - %i\n", num % 10, num / 10);
	num = -01;
	printf("%i - %i\n", num % 10, num / 10);
	num = -00;
	printf("%i - %i\n", num % 10, num / 10);
	return (0);
}