/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:44:35 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/05/31 01:01:54 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// ´a -> b' is the same as '(*a).b'
void ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = // <-- hier weiter
	t_list	*new;

	new = malloc(sizeof(t_list));
	new -> content = content;
	new -> next = 0;
	return (new);
}
/*
int main(void)
{
	t_list *new = ft_lstnew("new content");
	printf("%s", (char *) new -> content);
	return (1);
}
*/
