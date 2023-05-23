/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:50:12 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/05/10 00:54:31 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (0);
//	if (nmemb * size > 2147483648)
//		return (write(1, "Error", 1);
	ptr = malloc(nmemb * size);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
// how to throw an error?
/*
int main(void)
{
    char source[] = "GHDGFDtstsr";
    printf("source is: %s\n", source);
    char *ptr = ft_calloc(1, 5);
	ptr[1] = 'r';
	ptr[4] = 'e';
	write(1, ptr, 10);
    return (0);
}
*/
