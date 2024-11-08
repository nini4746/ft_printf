/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhpark <yunhpark@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:15:59 by yunhpark          #+#    #+#             */
/*   Updated: 2024/10/04 14:53:55 by yunhpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new_node;
	t_list	*root;
	t_list	*result_ptr;

	ptr = lst;
	root = ft_lstnew(f(ptr->content));
	if (!root)
		return (NULL);
	result_ptr = root;
	ptr = ptr->next;
	while (ptr)
	{
		new_node = ft_lstnew(f(ptr->content));
		if (!new_node)
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		result_ptr->next = new_node;
		result_ptr = new_node;
		ptr = ptr->next;
	}
	return (root);
}
