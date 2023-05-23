/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:46:58 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/05/11 01:48:15 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getdig(int n)
{
	unsigned long	digits;

	if (n < 0)
	{
		digits = 2;
		n = n * (-1);
	}
	else
		digits = 1;
	while (n / 10 > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned long	digits;

	digits = ft_getdig(n);
	ptr = malloc(digits + 1);
	if (ptr == 0)
		return (0);
	ptr[digits] = 0;
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * (-1);
	}
	while (digits && ptr[digits - 1] != '-')
	{
		ptr[digits - 1] = n % 10 + 48;
		n = n / 10;
		digits--;
	}
	return (ptr);
}
/*
int main(void)
{
	int test = -36560;
	printf("%s", ft_itoa(test));
	return (0);
}
*/
