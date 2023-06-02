/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:44:35 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/02 02:52:20 by ggiertzu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *start;
	void *content;

	start = 0;
	while (lst)
	{
		content = f(lst -> content);
		if (!content)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, ft_lstnew(content));
		lst = lst -> next;
	}
	ft_lstlast(start) -> next = 0;
	return (start);
}
/*
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void *content;

	while (lst)
	{
		content = f(lst -> content);
		if (
*/
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

void ft_lstadd_back(t_list **lst, t_list *new)
{
	ft_lstlast(*lst) -> next = new;
	return ;
}

int main(void)
{
	t_list *new = ft_lstnew("A");
	t_list *second = ft_lstnew("B");
	new -> next = second;
	print_lst(new);
	t_list *third = ft_lstnew("C");
	ft_lstadd_front(&new, third);
	print_lst(third);
	t_list *fourth = ft_lstnew("D");
	ft_lstadd_back(&new, fourth);
	print_lst(third);
	return (1);
}

