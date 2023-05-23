/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 02:58:31 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/05/20 14:03:20 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recu(int n, int fd)
{
	if (n / 10 > 0)
		ft_recu(n / 10, fd);
	n = n % 10 + 48;
	write(fd, &n, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	ft_recu(n, fd);
	return ;
}
/*
//					---> how to handle overflow?
int main(void)
{
	int test = -124423;

	ft_putnbr_fd(test, 1);
	return (0);
}
*/
