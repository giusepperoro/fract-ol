/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 21:34:14 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:49:39 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*c;

	c = (t_list *)malloc(sizeof(t_list));
	if (!c)
		return (NULL);
	c->content = content;
	c->next = NULL;
	return (c);
}
