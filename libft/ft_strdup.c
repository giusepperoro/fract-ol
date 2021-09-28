/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdoyle <kdoyle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:00:07 by kdoyle            #+#    #+#             */
/*   Updated: 2020/11/07 11:13:11 by kdoyle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*so1;
	char	*buff;
	size_t	l;
	size_t	i;

	i = 0;
	so1 = (char *)s1;
	l = ft_strlen(so1);
	buff = (char *)malloc(l + 1);
	if (buff == NULL)
		return (NULL);
	while (i < l)
	{
		buff[i] = so1[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
