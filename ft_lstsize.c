/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiertzu <ggiertzu@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:44:35 by ggiertzu          #+#    #+#             */
/*   Updated: 2023/06/01 01:20:47 by ggiertzu         ###   ########.fr       */
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

int ft_lstsize(t_list *lst)
{
	t_list *ptr;
	int res;

	ptr = lst;
	res = 0;
	while (ptr)
	{
		res++;
		ptr = ptr -> next;
	}
	return (res);
}

int main(void)
{
	t_list *new = ft_lstnew("A");
	t_list *second = ft_lstnew("B");
	new -> next = second;
	print_lst(new);
	printf("list length is: %d\n", ft_lstsize(new));
	t_list *third = ft_lstnew("C");
	ft_lstadd_front(&new, third);
	print_lst(third);
	printf("list length is: %d\n", ft_lstsize(third));
	return (1);
}

