/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:44:35 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/01 01:28:12 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void print_lst(t_list *lst)
{
	t_list *ptr;

	ptr = lst;

	printf("This prints the entire list:\nfirst node: ");
	while (ptr -> next != 0)
	{
		printf("%s\n", (char *) ptr -> content);
		ptr = ptr -> next;
	}
	printf("last node: %s\n", (char *) ptr -> content);
	return ;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	new -> content = content;
	new -> next = 0;
	return (new);
}
// ´a -> b' is the same as '(*a).b'
void ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
	return ;
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *ptr;

	ptr = lst;
	while (ptr -> next)
		ptr = ptr -> next;
	return (ptr);
}

int main(void)
{
	t_list *new = ft_lstnew("A");
	t_list *second = ft_lstnew("B");
	new -> next = second;
	t_list *third = ft_lstnew("C");
	ft_lstadd_front(&new, third);
	printf("last node content is: %s", (char *) ft_lstlast(third) -> content);
	return (1);
}

