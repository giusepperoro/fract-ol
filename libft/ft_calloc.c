/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 09:59:37 by kdoyle            #+#    #+#             */
/*   Updated: 2021/09/28 19:53:46 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*bo;
	size_t	i;
	size_t	s;

	i = 0;
	s = count * size;
	bo = malloc(s);
	if (bo == NULL)
		return (NULL);
	while (i != s)
	{
		bo[i] = 0;
		i++;
	}
	return (bo);
}
