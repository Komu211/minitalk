/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmuhlbau <kmuhlbau@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:36:27 by kmuhlbau          #+#    #+#             */
/*   Updated: 2024/10/11 16:32:45 by kmuhlbau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	void	*tmp_content;

	if (!lst | !f | !del)
		return (NULL);
	tmp_content = (*f)(lst->content);
	new = ft_lstnew(tmp_content);
	if (!new)
		return ((*del)(tmp_content), NULL);
	lst = lst->next;
	while (lst)
	{
		tmp_content = (*f)(lst->content);
		tmp = ft_lstnew(tmp_content);
		if (!tmp)
		{
			ft_lstclear(&new, del);
			(*del)(tmp_content);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		lst = lst->next;
	}
	return (new);
}
