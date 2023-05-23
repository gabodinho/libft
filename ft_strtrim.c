/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 01:21:59 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/05/21 02:16:06 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	unsigned long	set_len;
	unsigned long	s1_len;
//								---> is set properly defined?
	s1_len = ft_strlen(s1);
	res = malloc(s1_len + 1);
	set_len = ft_strlen(set);
	if (res == 0)
		return (0);
	if (!ft_strncmp(s1, set, set_len))
		ft_strlcpy(res, s1 + set_len, s1_len - set_len + 1);
	else
		ft_strlcpy(res, s1, s1_len + 1);
	if (!ft_strncmp(s1 + s1_len - set_len, set, set_len))
		ft_bzero(res + ft_strlen(res) - set_len, set_len);
	return (res);
}
/*

#include <stdio.h>

int main(void)
{
	char test[] = "this is a test this";
	char set[] = "this";
	char *res = ft_strtrim(test, set);
	printf("%s\n%s\n%s", test, set, res);
//	printf("\n%s", *(&test + 1)	- 5);
	return (0);
}
*/
