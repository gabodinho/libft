/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:44:33 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/05/22 21:42:28 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	idx;
	char			*ptr;

	idx = 0;
	ptr = 0;
	while (*s)
	{
		if (*s == (char) c)
			ptr = (char *) s;
		s++;
	}
	if (*s == (char) c)
		ptr = (char *) s;
	return (ptr);
}
/*
int main(void)
{
	char src[] = "this is our source";
	printf("%s\n", ft_strrchr(src, 'o'));
	return (0);
}
*/
