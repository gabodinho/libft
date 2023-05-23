/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 00:33:08 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/05/18 20:36:13 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getword(char const *s, char c)
{
	unsigned long	len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	char			*stor;
	unsigned long	len;
	unsigned long	idx;

	len = ft_strlen(s);
	stor = malloc((len + 1));
	res = malloc(((len + 1) / 2 + 1) * 8);
	idx = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			len = ft_getword(s, c);
			ft_strlcat(stor, s, len + 1);
			res[idx] = stor;
			stor = stor + len + 1;
			idx++;
			s = s + len;
		}
	}
	res[idx] = 0;
	return (res);
}
/*
int main(void)
{
	const char str[] = " This is a test string !  ";
	char delim = ' ';
	char **res;
	printf("String: %s\n", str);
	printf("Delimiter: %c", delim);
	
	res = ft_split(str, delim);
	
	//printf("%s", res[0]);
	while (*res)
	{
		printf("\n%s", *res);
		res++;
	}
	return (0);
}
*/
